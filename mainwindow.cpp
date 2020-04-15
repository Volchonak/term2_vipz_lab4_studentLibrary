#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopWidget"
#include "addnewprofile.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QTextStream"
//#include "QDir"
#include "QList"
#include "studentlist.h"
#include "getlinedialog.h"
#include "QDebug"
using std::memcmp;

QList<Student> list;
void print(QList<Student> list)
{
    for(int i=0; i<list.size();++i)
    {
        qInfo()<<list.at(i).getLastName();
        qInfo()<<list.at(i).getFirstName();
        qInfo()<<i;
    }
}
QString filename="";
static sort sortType=Default;
static showExcellentStudents ExcellentType=no;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_search->setPlaceholderText("Шукати..");
    ui->tableWidget->horizontalHeader()->setStyleSheet("border: 0px white;border-bottom: 0px;"
                                                   "font: 10pt \"Times New Roman\";color: rgb(64,65,66);");
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Прізвище"<<"Ім'я"<<"ООП"
                                               <<"ЛААГ" <<"Чисельні\nМетоди"<<"Англійська\nмова"
                                               <<"ВІПЗ"<<"Фізика"<<"Українська\nмова");
    ui->tableWidget->setColumnWidth(0,100);
    ui->tableWidget->setColumnWidth(1,100);
    int columns=ui->tableWidget->columnCount();
    int rows=ui->tableWidget->rowCount();
    for(int i=2;i<columns;++i)
    {
        ui->tableWidget->setColumnWidth(i,73);
    }
    for(int i=1; i<rows;i+=2)
    {
        setRowBackground(QColor(222,222,222),ui->tableWidget->model(),i);
    }


}
void MainWindow::setRowBackground(const QBrush& brush,
                      QAbstractItemModel* model, int row,
                      const QModelIndex& parent)
{
    if(!model || row<0 || row>=model->rowCount(parent))
    {
        return;
    }
    if(parent.isValid() && parent.model() != model)
    {
        return;
    }
    for(int i=0;i<model->columnCount(parent);++i)
    {
        Q_ASSUME(model->setData(model->index(row,i,parent),brush,Qt::BackgroundRole));
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_box1_button_addNewProf_clicked()
{
    int numOfElemBefore=list.size();
    addNewProfile w;
    QString lastName;
    w.setModal(true);
    w.exec();
    int numOfElemAfter=list.size();
    if(numOfElemAfter-numOfElemBefore)
    {
        ui->lineEdit_search->setText("");
        sortType=Default;
        if(ExcellentType==yes)
        {
            on_box1_buttonShowExcellent_clicked();
        }
        else
        {
            showDataAtTableWidget(*(ui->tableWidget),list,QColor(222,222,222));
        }
    }
}

void MainWindow::on_box1_button_addFile_clicked()
{
    getLineDialog w;
    w.exec();
    QFile fp(filename);
    if(filename==".txt")
    {
        return;
    }
    if(!fp.open(QFile::ReadWrite | QFile::Text))
    {
        QMessageBox::information(this,"Створення нового файлу", "Файл не створено\nСпробуйте знову");
        return;
    }
    else
    {
        if(fp.size())
        {
            QMessageBox::information(this,"Створення нового файлу", "Файл не створено\nСпробуйте знову");
            fp.close();
            return;
        }
        if(list.isEmpty())
        {
            sortType=Default;
            ExcellentType=no;
            clearTableWidget(*(ui->tableWidget),QColor(222,222,222));
        }
        ui->lineEdit_search->setText("");
    }

}

void MainWindow::on_box1_button_open_clicked()
{
    QString str= QFileDialog::getOpenFileName(this,"","C:\\users\\roman\\source\\repos\\VIPZ_lab4_2","Text file (*.txt)");
    if(str=="")
    {
        return;
    }
    else
    {
        filename=str;
    }
    QFile fp(filename);

    if(!fp.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this,"Відкрити файл", "Файл не було відкрито");
        return;
    }
    list.clear();
    sortType=Default;
    ExcellentType=no;
    ui->lineEdit_search->setText("");
    QTextStream in(&fp);
    Student *tmp= new Student;
    tmp->readFromFile(list, in);
    delete tmp;
    fp.close();
    clearTableWidget(*(ui->tableWidget),QColor(222,222,222));
    showDataAtTableWidget(*(ui->tableWidget),list,QColor(222,222,222));

}

void MainWindow::on_box1_button_save_clicked()
{
    QFile fp(filename);
    if(!fp.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this,"Збереження", "Немає файлу для збереження інформації\nВідкрийте"
                                                    "вже існуючий або створіть новий файл");
        return;
    }
    list.clear();
    readDataFromTableWidget(*(ui->tableWidget),list);
    int numOfElem=list.size();
    QString content="";
    for(int i=0; i<numOfElem;++i)
    {
        content+=list.at(i).getLastName()+" ";
        content+=list.at(i).getFirstName()+" ";
        for(int j=0;j<NUMOFMARKS;++j)
        {
            content+=QString::number(list.at(i).getMark(j))+" ";
        }
    }
    QTextStream out(&fp);
    out.setCodec("UTF-8");
    out<< content;
    out.flush();
    fp.close();

}

void MainWindow::on_box1_button_close_clicked()
{
    QMessageBox::StandardButton saveChanges;
    saveChanges=QMessageBox::question(this, "Закрити файл", "Зберегти зміни?",
                                                            QMessageBox::Yes|QMessageBox::No);
    if(saveChanges==QMessageBox::Yes)
    {
        MainWindow::on_box1_button_save_clicked();

    }
    clearTableWidget(*(ui->tableWidget),QColor(222,222,222));
    ui->lineEdit_search->setText("");

}

void MainWindow::on_box1_button_delete_clicked()
{
    int deleteRow=ui->tableWidget->currentRow();
    if(deleteRow>=list.size())
    {
        return;
    }
    //int rows=ui->tableWidget->rowCount();
    int columns=ui->tableWidget->columnCount();
    bool checkForDelete=false;
    for(int i=0;i<columns;++i)
    {
        if(ui->tableWidget->item(deleteRow,i)->isSelected())
        {
            checkForDelete=true;

            break;
        }
    }
    if(checkForDelete)
    {
        if(ExcellentType==yes)
        {
            int currentExcellentItem=-1;
            int numOfElem=list.size();
            for(int i=0; i<numOfElem;++i)
            {
                if(list.at(i).getLastName().toUpper().contains(ui->lineEdit_search->text().toUpper()))
                {
                    if(list.at(i).isExcellentStudent())
                    {
                        ++currentExcellentItem;
                        if(currentExcellentItem==deleteRow)
                        {
                            deleteRow=i;
                            break;
                        }
                    }
                }
            }
            list.removeAt(deleteRow);
            on_box1_buttonShowExcellent_clicked();
            on_box1_buttonShowExcellent_clicked();
            return;
        }
        list.removeAt(deleteRow);
        clearTableWidget(*(ui->tableWidget),QColor(222,222,222));
        showDataAtTableWidget(*(ui->tableWidget),list,QColor(222,222,222));
    }
}

void MainWindow::on_box1_buttonShowExcellent_clicked()
{
    clearTableWidget(*(ui->tableWidget),QColor(222,222,222));
    if(ExcellentType==no)
    {
        ExcellentType=yes;
        QString textCheck=ui->lineEdit_search->text().toLower();
        QList<Student> excellent;
        int numOfElem=list.size();
        for(int i=0; i<numOfElem;++i)
        {
            if(list.at(i).isExcellentStudent())
            {
                if(list.at(i).getLastName().toLower().contains(textCheck))
                {
                    excellent.append(list.at(i));
                }
            }
        }
        showDataAtTableWidget(*(ui->tableWidget),excellent,QColor(222,222,222));
    }
    else
    {
        ExcellentType=no;
        on_lineEdit_search_textChanged(ui->lineEdit_search->text());
    }

}


void MainWindow::on_box1_button_sort_clicked()
{

    while(1)
    {
        if(sortType==Default)
        {
            sortType=ByNameLess;
            std::sort(list.begin(),list.end(),compareLastName_Less);
            on_lineEdit_search_textChanged(ui->lineEdit_search->text());
            break;
        }
        if(sortType==ByNameLess)
        {
            sortType=ByNameBigger;
            std::sort(list.begin(),list.end(),compareLastName_Bigger);
            on_lineEdit_search_textChanged(ui->lineEdit_search->text());
            break;
        }
        if(sortType==ByNameBigger)
        {
            sortType=ByAverageBigger;
            std::sort(list.begin(),list.end(),compareAverage_Bigger);
            on_lineEdit_search_textChanged(ui->lineEdit_search->text());
            break;
        }
        if(sortType==ByAverageBigger)
        {
            sortType=ByAverageLess;
            std::sort(list.begin(),list.end(),compareAverage_Less);
            on_lineEdit_search_textChanged(ui->lineEdit_search->text());
            break;
        }
        if(sortType==ByAverageLess)
        {
            sortType=ByNameLess;
            std::sort(list.begin(),list.end(),compareLastName_Less);
            on_lineEdit_search_textChanged(ui->lineEdit_search->text());
            break;
        }
    }
}
void MainWindow::showDataAtTableWidget(QTableWidget &table,const int row, const int numOfColumns,const Student& obj)
{
    int j=0;
    table.setItem(row,j, new QTableWidgetItem(obj.getLastName()));
    ++j;
    table.setItem(row,j, new QTableWidgetItem(obj.getFirstName()));
    ++j;
    for(;j<numOfColumns;++j)
    {
        table.setItem(row,j, new QTableWidgetItem(QString::number(obj.getMark(j-2))));
    }
}
void MainWindow::showDataAtTableWidget(QTableWidget &table,const QList<Student> list, const QBrush &brush)
{
    int rows=table.rowCount();
    int columns=table.columnCount();
    int numOfElem=list.size();
    int i;
    for(i=0;i<rows&&i<numOfElem;++i)
    {
        showDataAtTableWidget(*(ui->tableWidget),i,columns,list.at(i));
        if(i%2)
        {
        setRowBackground(brush,table.model(),i);
        }

    }
    while(i<numOfElem)
    {
        ui->tableWidget->setRowCount(rows+1);
        ++rows;
        showDataAtTableWidget(*(ui->tableWidget),i,columns,list.at(i));
        if(i%2)
        {
        setRowBackground(brush,table.model(),i);
        }

    }
}
void MainWindow::readDataFromTableWidget(const QTableWidget& table,QList<Student> &list)
{
    Student tmp;
    int rows= table.rowCount();
    int columns= table.columnCount();
    if(!table.itemAt(0,0))
    {
        return;
    }
    for(int i=0;i<rows;++i)
    {
        if(table.itemAt(i,0)->text().isEmpty())
        {
            return;
        }
        for(int j=0; j<columns;++j)
        {
            tmp.setLastName(table.item(i,j)->text());
            ++j;
            tmp.setFirstName(table.item(i,j)->text());
            ++j;

            for(int k=0;k<NUMOFMARKS;++k,++j)
            {
                tmp.setMark(k,table.item(i,j)->text().toInt());
            }
        }
        if(tmp.getLastName()=="")
        {
            continue;
        }
        list.append(tmp);
    }
}
void MainWindow::clearTableWidget(QTableWidget &table,const QBrush &brush)
{
    int rows=table.rowCount();
    int columns=table.columnCount();
    for(int i=0;i<rows;++i)
    {
        for(int j=0; j<columns;++j)
        {
            table.setItem(i,j,new QTableWidgetItem(""));
        }
        if(i%2)
        {
        setRowBackground(brush,table.model(),i);
        }
    }
}
void MainWindow::on_lineEdit_search_textChanged(const QString &arg1)
{
    static int i=0;
    qInfo()<<i;
    ++i;
    int numOfElem=list.size();
    QList<Student> tmp;
    for(int i=0; i<numOfElem;++i)
    {
        if(list.at(i).getLastName().toUpper().contains(arg1.toUpper()))
        {
            if(ExcellentType==yes)
            {
                if(list.at(i).isExcellentStudent())
                {

                    tmp.append(list.at(i));
                }
            }
            else
            {
                tmp.append(list.at(i));
            }
        }
    }
    clearTableWidget(*(ui->tableWidget), QColor(222,222,222));
    showDataAtTableWidget(*(ui->tableWidget), tmp,QColor(222,222,222));
}

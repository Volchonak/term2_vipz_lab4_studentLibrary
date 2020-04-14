#include "getlinedialog.h"
#include "ui_getlinedialog.h"
#include "studentlist.h"
#include "QList"
#include "mainwindow.h"
extern QString filename;
extern QList<Student> list;
getLineDialog::getLineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getLineDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText("student_library");
    ui->radioButton_keep->setChecked(true);
}

getLineDialog::~getLineDialog()
{
    delete ui;
}

void getLineDialog::on_button_setDataToCreateFile_clicked()
{

    filename=ui->lineEdit->text() +".txt";
    if(ui->radioButton_clear->isChecked())
    {
        list.clear();
    }
    this->close();
}

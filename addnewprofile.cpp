#include "addnewprofile.h"
#include "ui_addnewprofile.h"
#include "QValidator"
#include "QList"
#include "studentlist.h"

extern QString asd;
extern QList<Student> list;
addNewProfile::addNewProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewProfile)
{
    ui->setupUi(this);

    QIntValidator *markValidator= new QIntValidator(0,5);
    QRegExpValidator *nameValidator = new QRegExpValidator( QRegExp( "[А-і-я]{1,40}" ) ) ;
    ui->lineEdit_lastName->setPlaceholderText("Прізвище");
    ui->lineEdit_lastName->setValidator(nameValidator);
    ui->lineEdit_firstName->setPlaceholderText("Ім'я");
     ui->lineEdit_firstName->setValidator(nameValidator);
    ui->lineEdit_1->setPlaceholderText("ООП(0-5)");
    ui->lineEdit_1->setValidator(markValidator);
    ui->lineEdit_2->setPlaceholderText("ЛААГ(0-5)");
    ui->lineEdit_2->setValidator(markValidator);
    ui->lineEdit_3->setPlaceholderText("Чисельні методи(0-5)");
    ui->lineEdit_3->setValidator(markValidator);
    ui->lineEdit_4->setPlaceholderText("Англійська мова(0-5)");
    ui->lineEdit_4->setValidator(markValidator);
    ui->lineEdit_5->setPlaceholderText("ВІПЗ(0-5)");
    ui->lineEdit_5->setValidator(markValidator);
    ui->lineEdit_6->setPlaceholderText("Фізика(0-5)");
    ui->lineEdit_6->setValidator(markValidator);
    ui->lineEdit_7->setPlaceholderText("Українська мова(0-5)");
    ui->lineEdit_7->setValidator(markValidator);

}

addNewProfile::~addNewProfile()
{
    delete ui;
}

void addNewProfile::on_lineEdit_1_textChanged()
{
    if(!ui->lineEdit_1->hasAcceptableInput())
    {
        ui->lineEdit_1->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_1->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_2_textChanged()
{
    if(!ui->lineEdit_2->hasAcceptableInput())
    {
        ui->lineEdit_2->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_2->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_3_textChanged()
{
    if(!ui->lineEdit_3->hasAcceptableInput())
    {
        ui->lineEdit_3->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_3->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_4_textChanged()
{
    if(!ui->lineEdit_4->hasAcceptableInput())
    {
        ui->lineEdit_4->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_4->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_5_textChanged()
{
    if(!ui->lineEdit_5->hasAcceptableInput())
    {
        ui->lineEdit_5->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_5->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_6_textChanged()
{
    if(!ui->lineEdit_6->hasAcceptableInput())
    {
        ui->lineEdit_6->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_6->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_7_textChanged()
{
    if(!ui->lineEdit_7->hasAcceptableInput())
    {
        ui->lineEdit_7->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_7->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_lastName_textChanged()
{
    if(!ui->lineEdit_lastName->hasAcceptableInput())
    {
        ui->lineEdit_lastName->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_lastName->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_lineEdit_firstName_textChanged()
{
    if(!ui->lineEdit_firstName->hasAcceptableInput())
    {
        ui->lineEdit_firstName->setStyleSheet(STYLESHEETERROR);
    }
    else
    {
        ui->lineEdit_firstName->setStyleSheet(STYLESHEETDEFAULT);
    }
}

void addNewProfile::on_button_saveAndAddProfile_clicked()
{
    bool correctInput=true;
    QString lastName,firstName;
    int marks[NUMOFMARKS];
    int index=NUMOFMARKS-1;
    do
    {
        if(!ui->lineEdit_firstName->hasAcceptableInput())
        {
            ui->lineEdit_firstName->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_lastName->setStyleSheet(STYLESHEETDEFAULT);
            firstName=ui->lineEdit_firstName->text();
        }
        if(!ui->lineEdit_lastName->hasAcceptableInput())
        {
            ui->lineEdit_lastName->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_firstName->setStyleSheet(STYLESHEETDEFAULT);
            lastName=ui->lineEdit_lastName->text();
        }
        if(!ui->lineEdit_7->hasAcceptableInput())
        {
            ui->lineEdit_7->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_7->setStyleSheet(STYLESHEETDEFAULT);
            marks[index]=ui->lineEdit_7->text().toInt();
            --index;
        }
        if(!ui->lineEdit_6->hasAcceptableInput())
        {
            ui->lineEdit_6->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_6->setStyleSheet(STYLESHEETDEFAULT);
            marks[index]=ui->lineEdit_6->text().toInt();
            --index;
        }
        if(!ui->lineEdit_5->hasAcceptableInput())
        {
            ui->lineEdit_5->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_5->setStyleSheet(STYLESHEETDEFAULT);
            marks[index]=ui->lineEdit_5->text().toInt();
            --index;
        }
        if(!ui->lineEdit_4->hasAcceptableInput())
        {
            ui->lineEdit_4->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_4->setStyleSheet(STYLESHEETDEFAULT);
            marks[index]=ui->lineEdit_4->text().toInt();
            --index;
        }
        if(!ui->lineEdit_3->hasAcceptableInput())
        {
            ui->lineEdit_3->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_3->setStyleSheet(STYLESHEETDEFAULT);
            marks[index]=ui->lineEdit_3->text().toInt();
            --index;
        }
        if(!ui->lineEdit_2->hasAcceptableInput())
        {
            ui->lineEdit_2->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_2->setStyleSheet(STYLESHEETDEFAULT);
            marks[index]=ui->lineEdit_2->text().toInt();
            --index;
        }
        if(!ui->lineEdit_1->hasAcceptableInput())
        {
            ui->lineEdit_1->setStyleSheet(STYLESHEETERROR);
            correctInput=false;
        }
        else
        {
            ui->lineEdit_1->setStyleSheet(STYLESHEETDEFAULT);
            marks[index]=ui->lineEdit_1->text().toInt();
            --index;
        }
    }while(0);
    if(correctInput)
    {
        Student tmp(lastName,firstName);
        for(int i=0;i<NUMOFMARKS;++i)
        {
            tmp.setMark(i,marks[i]);
        }
        list.append(tmp);
        this->close();
    }
}

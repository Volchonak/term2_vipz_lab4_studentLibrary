#ifndef ADDNEWPROFILE_H
#define ADDNEWPROFILE_H
#define STYLESHEETERROR "QLineEdit{background-color:white;margin-right:3%;\
margin-top:5px;border-width:1px;border-style:solid;border-color:rgb(255, 0, 0);\
border-radius:10px;padding: 5px 9px;font: italic 12pt \"Times New Roman\";color:rgb(255, 0, 0);\
}QLineEdit:hover {border-bottom: 3px solid rgb(255, 0, 0);}"
#define STYLESHEETDEFAULT "QLineEdit{background-color:white;margin-right:3%;\
margin-top:5px;border-width:1px;border-style:solid;border-color:rgb(204, 204, 204);\
border-radius:10px;padding: 5px 9px;font: italic 12pt \"Times New Roman\";color:rgb(64, 65, 66);\
}QLineEdit:hover {border-bottom: 3px solid rgb(204, 204, 204);}"
#include <QDialog>

namespace Ui {
class addNewProfile;
}

class addNewProfile : public QDialog
{
    Q_OBJECT

public:
    explicit addNewProfile(QWidget *parent = nullptr);
    ~addNewProfile();

private slots:


    void on_lineEdit_1_textChanged();

    void on_lineEdit_2_textChanged();

    void on_lineEdit_3_textChanged();

    void on_lineEdit_4_textChanged();

    void on_lineEdit_5_textChanged();

    void on_lineEdit_6_textChanged();

    void on_lineEdit_7_textChanged();

    void on_lineEdit_lastName_textChanged();

    void on_lineEdit_firstName_textChanged();

    void on_button_saveAndAddProfile_clicked();

private:
    Ui::addNewProfile *ui;
};

#endif // ADDNEWPROFILE_H

#ifndef GETLINEDIALOG_H
#define GETLINEDIALOG_H

#include <QDialog>

namespace Ui {
class getLineDialog;
}

class getLineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getLineDialog(QWidget *parent = nullptr);
    ~getLineDialog();

private slots:
    void on_button_setDataToCreateFile_clicked();

private:
    Ui::getLineDialog *ui;
};

#endif // GETLINEDIALOG_H

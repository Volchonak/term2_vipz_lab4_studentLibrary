
#include "QTableWidget"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QAbstractItemModel"
#include "studentlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setRowBackground(const QBrush& brush, QAbstractItemModel* model,
                          int row, const QModelIndex& parent = QModelIndex() );
    void showDataAtTableWidget(QTableWidget &table,const int row, const int numOfColumns,const Student& obj);
    void readDataFromTableWidget(const QTableWidget& table,QList<Student>& list);
    void showDataAtTableWidget(QTableWidget& table,const QList<Student> list, const QBrush &brush);
    void clearTableWidget(QTableWidget& table,const QBrush &brush);


private slots:
    void on_box1_button_addNewProf_clicked();


    void on_box1_button_addFile_clicked();

    void on_box1_button_open_clicked();

    void on_box1_button_save_clicked();

    void on_box1_button_close_clicked();

    void on_box1_button_delete_clicked();

    void on_box1_button_sort_clicked();

    void on_box1_buttonShowExcellent_clicked();

    void on_lineEdit_search_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

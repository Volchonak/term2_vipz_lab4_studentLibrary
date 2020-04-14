#include "mainwindow.h"
#include "QDesktopWidget"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget dw;
    int x=dw.width()*0.7;
    int y=dw.height()*0.7;
    MainWindow w;
    w.setFixedSize(x,y);
    w.show();
    return a.exec();
}

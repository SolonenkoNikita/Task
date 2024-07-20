#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    const QString str = "Moscow";
    QApplication a(argc, argv);
    MainWindow w(str);
    w.show();
    return a.exec();
}

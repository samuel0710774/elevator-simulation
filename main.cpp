#include "mainwindow.h"

#include <QApplication>
#include <qsqldatabase.h>
#include <qsqlquery.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

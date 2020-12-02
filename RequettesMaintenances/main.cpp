#include "mainwindow.h"
#include "Connection.h"
#include "QApplication"
#include "QMessageBox"
#include "QDebug"
#include <QIcon>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection C;
    bool test=C.createConnection();
    QIcon iconwindow;
    iconwindow.addFile("UtopiaSft.png");
    MainWindow w;
    w.setFixedSize(816,693);
    w.setWindowIcon(iconwindow);
    w.setWindowTitle("Gestion Requettes et Equipes");
    if(test)
    {
        w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("connection successful\n""click cancel"),QMessageBox::Cancel);
    }
    else
    {
        w.show();
    QMessageBox::information(nullptr,QObject::tr("database is error"),QObject::tr("connection unsuccessful\n""click cancel"),QMessageBox::Cancel);
    }
    w.show();
    return a.exec();
}

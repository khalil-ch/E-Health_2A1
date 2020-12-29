#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
//test

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   connection c;
    bool verifConnexion = c.createconnect();
    MainWindow w;
    if(verifConnexion)
    {
        w.show();
        w.statusBar()->showMessage("DATABASE CONNECTED");
    }
    return a.exec();
}

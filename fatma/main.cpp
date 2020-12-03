#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion Cnx;

    if(Cnx.ouvrirConnexion())
    {
        QMessageBox msgBox;
        msgBox.setText("Connexion Avec Success!");
        msgBox.exec();
        w.show();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Echec!");
        msgBox.exec();
    }
 return a.exec();
}

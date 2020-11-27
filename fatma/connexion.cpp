#include "connexion.h"
#include <exception>
#include <QDebug>
#include <QSqlError>
#include<QSqlQuery>

Connexion::Connexion()
{

}

bool Connexion::ouvrir()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("EHEALTH");
    db.setUserName("system");
    db.setPassword("0000");
    if(db.open())
        test=true;

    return  test;
}
void Connexion::fermer()
{
    db.close();
}

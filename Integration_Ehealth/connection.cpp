#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test4");//inserer le nom de la source de données ODBC
db.setUserName("khalil3");//inserer nom de l'utilisateur
db.setPassword("khalil3");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

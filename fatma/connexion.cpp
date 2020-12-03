#include "connexion.h"

Connexion::Connexion()
{

}


bool Connexion::ouvrirConnexion(){

db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("fatma");
db.setPassword("fatma1231");
if(db.open())
    return true;

return false;

}


bool Connexion::fermeConnexion()
{
db.close();
return true;


}

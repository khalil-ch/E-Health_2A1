#include "chefservice.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
Chefservice::Chefservice()
{
    this->id=0;
    this->nom="nom";
    this->prenom="prenom";
}
Chefservice::Chefservice(int id,QString nom,QString prenom)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;

}
bool Chefservice::ajouterChefSv()
{
    QSqlQuery query;
     //QSqlQuery *query = new QSqlQuery(db);
    query.prepare("INSERT into Chefservice (id,nom,prenom)""VALUE(:id,:nom,:prenom)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    return query.exec();
}
QSqlQueryModel * Chefservice::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Chefservice");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    return model;
}


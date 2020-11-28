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

    query.prepare("INSERT into Chefservice (id,nom,prenom) ""values(:id,:nom,:prenom)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    return query.exec();
}
bool Chefservice::modifierChefSv(int idd)
{
    QString res= QString::number(idd);
    QString nom="khalillooo";
    QString prenom="kh";
    QSqlQuery query;
    //query.prepare("UPDATE Chefservice SET nom ="+nom+",prenom = "+prenom+ " WHERE ID = 457");
    query.prepare("UPDATE Chefservice SET nom = 'san pedro' ,prenom = 'lucio' WHERE ID = 457");
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
bool Chefservice::supprimerChefSv(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from Chefservice where ID = :id");
    query.bindValue(":id", res);
    return query.exec();
}
QSqlQueryModel * Chefservice::rechercheChefSv(int idd)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res= QString::number(idd);
    model->setQuery("select * from Chefservice where ID ="+res);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    return model;
}

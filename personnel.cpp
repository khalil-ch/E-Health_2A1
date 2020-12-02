#include "personnel.h"
#include <QDebug>
#include <QString>
personnel::personnel()
{
cin=0;
nom="";
prenom="";
type="";

}
personnel::personnel(int cin,QString type,QString nom , QString prenom)
{
  this->cin=cin;
    this->nom=type;
    this->prenom=nom;
  this->type=prenom;

}
QString personnel::get_type(){return  type;}

int personnel::get_cin(){return  cin;}
QString personnel::get_nom(){return  nom;}
QString personnel::get_prenom(){return  prenom;}


bool personnel::ajouter()
{
QSqlQuery query;
QString res1= QString::number(cin);

query.prepare("INSERT INTO personnel (CIN, NOM, PRENOM ,TYPE) "
                    "VALUES (:cin, :nom, :prenom, :type)");
query.bindValue(":cin", res1);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);


query.bindValue(":type", type);

return    query.exec();
}

bool personnel::supprimer(int cin)
{
QSqlQuery query;
QString res1= QString::number(cin);
query.prepare("Delete from personnel where CIN = :cin ");
query.bindValue(":cin", res1);
return    query.exec();
}
QSqlQueryModel * personnel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personnel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}
QSqlQueryModel *personnel::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from PERSONNEL where CIN LIKE '"+rech+"%' or NOM LIKE '"+rech+"%' or PRENOM LIKE '"+rech+"%'");



    return model;
}

QSqlQueryModel * personnel::tri()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from PERSONNEL order by CIN desc");
    q->exec();
    model->setQuery(*q);
    return  model;
}









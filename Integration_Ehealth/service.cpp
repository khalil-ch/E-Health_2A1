#include "service.h"
#include <QDebug>
#include <QString>
service::service()
{
idservice=0;

cinchef=0;
typeservice="";


}
service::service(int idservice, int cinchef  ,QString typeservice )
{
  this->idservice=idservice;

    this->cinchef=cinchef;
  this->typeservice=typeservice;


}
QString service::get_typeservice(){return  typeservice;}


int service::get_idservice(){return  idservice;}

int service::get_cinchef(){return  cinchef;}

bool service::ajouter()
{
QSqlQuery query;
QString res11= QString::number(idservice);
QString res22= QString::number(cinchef);

query.prepare("INSERT INTO service (ID_SERVICE, CIN_CHEF ,TYPE_SERVICE) "
                    "VALUES (:idservice,  :cinchef, :typeservice )");
query.bindValue(":idservice", res11);
query.bindValue(":cinchef", res22);


query.bindValue(":typeservice", typeservice);



return    query.exec();
}

bool service::supprimer(int idservice)
{
    QSqlQuery query;
      QString res= QString::number(idservice);
      query.prepare("Delete from SERVICE where ID_SERVICE = :idservice ");
      query.bindValue(":idservice", res);
      return    query.exec();

}
QSqlQueryModel * service::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from service");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SERVICE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN_CHEF "));

model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE_SERVICE"));
    return model;
}
bool service::modifier(int idvehicule ,QString typepanne)
{
    QSqlQuery query;
    QString res= QString::number(idvehicule);
    query.prepare("update panne set idvehicule = :c where typepanne = :i");
    query.bindValue(":i", typepanne);
    query.bindValue(":c", res);



    return query.exec();
}
QSqlQueryModel *service::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from SERVICE where ID_SERVICE LIKE '"+rech+"%' or CIN_CHEF LIKE '"+rech+"%' or TYPE_SERVICE LIKE '"+rech+"%'");



    return model;
}

QSqlQueryModel * service::tri()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from SERVICE order by ID_SERVICE desc");
    q->exec();
    model->setQuery(*q);
    return  model;
}





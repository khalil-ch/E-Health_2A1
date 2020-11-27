#include "equipement.h"

equipement::equipement()
{

}



equipement::equipements(QString n,QString t, QString m, QString c,int num ){
  this->nom=n;
  this->type=t;
   this->modele=m;
   this->condition=c;
   this->numdeserie=num;

}


bool equipement::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO EQUIPEMENTS (nom,type,modele,condition,numdeserie) "
                        "VALUES (:nom, :type, :modele,:condition,:numdeserie)");
    query.bindValue(":nom", nom);
    query.bindValue(":type",type);
    query.bindValue(":modele", modele);
    query.bindValue(":condition", condition);
    query.bindValue(":numdeserie", numdeserie);

    return    query.exec();

}

bool equipement::supprimer(int) nds){

    {
        QSqlQuery query;

        query.prepare("DELETE FROM EQUIPEMENTS WHERE numdeserie = :nds ");
        query.bindValue(":id", id);

        return    query.exec();
    }

    QSqlQueryModel * equipement::afficher()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from EQUIPEMENTS");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("numdeserie"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("condition"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("modele"));
        return model;
    }
    bool equipement::modifier(int num,QString n ,QString m,QString c, QString t)
    {
        QSqlQuery query;
        query.prepare("update EQUIPEMENTS set  numdeserie = :num, nom= :n , modele= :m, condition=c, type= :t  WHERE numdeserie = :nds") ;
        query.bindValue(":nds", num);
        query.bindValue(":n", n);
        query.bindValue(":t", t);
        query.bindValue(":c", c);
         query.bindValue(":m", m);
        return    query.exec();
    }

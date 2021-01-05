#include "equipement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
equipement::equipement()
 {



}

equipement::equipement(QString num,QString nom,QString type,QString modele,QString cond, QString desc)
    {
        this->numdeserie=num;
        this->nom=nom;
        this->modele=modele;
        this->type=type;
        this->description=desc;
        this->condition=cond;

    }



QString equipement::getnom() const
{
    return nom;
}

void equipement::setnom(const QString &value)
{
    nom = value;
}


QString equipement::getnumdeserie() const
{
    return numdeserie;
}

void equipement::setnumdeserie(const QString &value)
{
    numdeserie = value;
}

QString equipement::getmodele() const
{
    return modele;
}

void equipement::setmodele(const QString &value)
{
    modele = value;
}

QString equipement::gettype() const
{
    return type;
}

void equipement::settype(const QString &value)
{
    type = value;
}

QString equipement::getcondition() const
{
    return condition;
}

void equipement::setcondition(const QString &value)
{
    condition = value;
}
QString equipement::getdescription() const
{
    return description;
}

void equipement::setdescription(const QString &value)
{
    description = value;
}

bool equipement::Ajouterequipement()
{

    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPEMENTS (NUMDESERIE, NOM, MODELE, TYPE, CONDITION, DESCRIPTION) "
                      "VALUES (:numdeserie, :nom, :modele, :type, :condition, :description)");

    query.bindValue(":numdeserie",numdeserie);
    query.bindValue(":nom",nom);
    query.bindValue(":modele",modele);
    query.bindValue(":type",type);
    query.bindValue(":condition",condition);
    query.bindValue(":description",description);

    return query.exec();
}



QSqlQueryModel* equipement::Afficherequipement(QString var){

QSqlQueryModel* model = new QSqlQueryModel;
QString Quer="SELECT * FROM EQUIPEMENTS ORDER BY "+var+"";
qDebug()<< Quer;
model->setQuery(Quer    );
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUMDESERIE"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
  model->setHeaderData(4,Qt::Horizontal, QObject::tr("CONDITION"));
  model->setHeaderData(5,Qt::Horizontal, QObject::tr("DESCRIPTION"));
  return model;

}

QSqlQueryModel *equipement::Searchequipement(QString eqp)
{
    QSqlQueryModel* model = new QSqlQueryModel;

    model->setQuery("SELECT * FROM EQUIPEMENTS where UPPER(NUMDESERIE) like upper('%"+eqp+"%')"
                    "OR UPPER(NOM) like upper('%"+eqp+"%')"
                    "OR UPPER(MODELE) like upper('%"+eqp+"%')"
                    "OR UPPER(TYPE) like upper('%"+eqp+"%')"
                    "OR UPPER(CONDITION) like upper('%"+eqp+"%')"
                    "OR UPPER(DESCRIPTION) like upper('%"+eqp+"%')");

                    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMDESERIE"));
                    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
                    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODELE"));
                    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE"));
                    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CONDITION"));
                    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DESCRIPTION"));
                    return model;
}

bool equipement::Supprimerequipement(QString epq)
{
    qDebug() << epq;
    QSqlQuery query;
    query.prepare("Delete from EQUIPEMENTS where NUMDESERIE= :numdeserie");
    query.bindValue(":numdeserie",epq);
    return  query.exec();
}

bool equipement::modifierequipement(QString n)
{
    QSqlQuery query;

    query.prepare("UPDATE EQUIPEMENTS SET NUMDESERIE=:numdeserie, NOM=:nom, MODELE=:modele, TYPE=:type, CONDITION=:condition, DESCRIPTION=:description where NUMDESERIE=:n");
    query.bindValue(":numdeserie",n);
    query.bindValue(":nom",nom);
    query.bindValue(":modele",modele);
    query.bindValue(":type",type);
    query.bindValue(":condition",condition);
     query.bindValue(":description",description);

    return  query.exec();
}




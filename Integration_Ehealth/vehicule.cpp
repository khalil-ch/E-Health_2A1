#include "vehicule.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
 vehicule::vehicule()
  {



}
vehicule::vehicule(QString nom,QString desinf,QString categorie,QString modele,QString desc)
{
    this->nom=nom;
    this->desinfectation=desinf;
    this->modele=modele;
    this->categorie=categorie;
    this->description=desc;

}


QString vehicule::getnom() const
{
    return nom;
}

void vehicule::setnom(const QString &value)
{
    nom = value;
}

QString vehicule::getmodele() const
{
    return modele;
}

void vehicule::setmodele(const QString &value)
{
    modele = value;
}

QString vehicule::getcategorie() const
{
    return categorie;
}

void vehicule::setcategorie(const QString &value)
{
    categorie = value;
}

QString vehicule::getdesinfectation() const
{
    return desinfectation;
}

void vehicule::setdesinfectation(const QString &value)
{
    desinfectation = value;
}
QString vehicule::getdescription() const
{
    return description;
}

void vehicule::setdescription(const QString &value)
{
    description = value;
}

bool vehicule::Ajoutervehicule()
{

    QSqlQuery query;
    query.prepare("INSERT INTO VEHICULES (NOM, CATEGORIE, MODELE, DESINFECTATION, DESCRIPTION) "
                      "VALUES (:nom, :categorie, :modele, :desinfectation, :description)");

    query.bindValue(":nom",nom);
    query.bindValue(":categorie",categorie);
    query.bindValue(":modele",modele);
    query.bindValue(":desinfectation",desinfectation);
   query.bindValue(":description",description);
    return query.exec();
}



QSqlQueryModel* vehicule::Affichervehicule(QString var){

QSqlQueryModel* model = new QSqlQueryModel;
QString Quer="SELECT * FROM VEHICULES ORDER BY "+var+"";
qDebug()<< Quer;
model->setQuery(Quer    );

  model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("CATEGORIE"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODELE"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESINFECTATION"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESCRIPTION"));
  return model;
}

QSqlQueryModel *vehicule::Searchvehicule(QString veh)
{
    QSqlQueryModel* model = new QSqlQueryModel;

    model->setQuery("SELECT * FROM VEHICULES where UPPER(NOM) like upper('%"+veh+"%')"
                    "OR UPPER(CATEGORIE) like upper('%"+veh+"%')"
                    "OR UPPER(MODELE) like upper('%"+veh+"%')"
                    "OR UPPER(DESINFECTATION) like upper('%"+veh+"%')"
                   "OR UPPER(DESCRIPTION) like upper('%"+veh+"%')");

                    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CATEGORIE"));
                    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MODELE"));
                    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DESINFECTATION"));
                    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DESCRIPTION"));
                    return model;
}

bool vehicule::Supprimervehicule(QString v)
{
    qDebug() << v;
    QSqlQuery query;
    query.prepare("Delete from VEHICULES where NOM= :nom");
    query.bindValue(":nom",v);
    return  query.exec();
}

bool vehicule::modifiervehicule(QString n)
{
    QSqlQuery query;

    query.prepare("UPDATE VEHICULES SET NOM=:nom, CATEGORIE=:categorie, MODELE=:modele, DESINFECTATION=:desinfectation, DESCRIPTION=:description where NOM=:n");
    query.bindValue(":nom",n);
    query.bindValue(":categorie",categorie);
    query.bindValue(":modele",modele);
    query.bindValue(":desinfectation",desinfectation);
    query.bindValue(":description",description);

    return  query.exec();
}

#include "equipemaintenance.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
EquipeMaintenance::EquipeMaintenance()
{
    this->IdEquipe="0";
    this->ChefEquipe="ChefEq";
    this->Specialitee="Specialite";
    this->NbReq="0";
}
EquipeMaintenance::EquipeMaintenance(QString equipeid,QString ChefEq,QString Specialite,QString NbRq)
{
    this->IdEquipe=equipeid;
    this->ChefEquipe=ChefEq;
    this->Specialitee=Specialite;
    this->NbReq=NbRq;
}
bool EquipeMaintenance::AjouterEq()
{
    QSqlQuery query;
    query.prepare("INSERT into Equipemaintenance (EQUIPEID,CHEFEQUIPE,SPECIALITEE,NOMBREREQUETTES)""values(:EQUIPEID,:CHEFEQUIPE,:SPECIALITEE,:NOMBREREQUETTES) ");
    query.bindValue(":EQUIPEID",IdEquipe);
    query.bindValue(":CHEFEQUIPE",ChefEquipe);
    query.bindValue(":SPECIALITEE",Specialitee);
    query.bindValue(":NOMBREREQUETTES",NbReq);
    return query.exec();
}
QSqlQueryModel* EquipeMaintenance::AfficherEq()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from EquipeMaintenance");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CHEFEQUIPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("SPECIALITEE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMBREREQUETTES"));
    return model;
}
bool EquipeMaintenance::SupprimerEq(QString equipeid)
{
    QSqlQuery query;
    query.prepare("Delete from EQUIPEMAINTENANCE where EQUIPEID = :EQUIPEID");
    query.bindValue(":EQUIPEID", equipeid);
    return query.exec();
}
bool EquipeMaintenance::ModifierEq(QString chefeq,QString spec,QString nbrq)
{
    QSqlQuery query;
    query.prepare("UPDATE Equipemaintenance SET chefequipe = '"+chefeq+ "' , specialitee= '"+spec+"' , nombrerequettes= '"+nbrq+"' WHERE equipeid ="+infotmp);
    return query.exec();
}
QSqlQueryModel * EquipeMaintenance::RechercheEqbyId()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from Equipemaintenance WHERE equipeid='"+infotmp+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CHEFEQUIPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("SPECIALITEE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMBREREQUETTES"));
    return model;
}
QSqlQueryModel * EquipeMaintenance::RechercheEqbySpec()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from Equipemaintenance WHERE specialitee='"+infotmp+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CHEFEQUIPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("SPECIALITEE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMBREREQUETTES"));
    return model;
}
QSqlQueryModel * EquipeMaintenance::TrierNom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from Equipemaintenance ORDER BY CHEFEQUIPE DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CHEFEQUIPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("SPECIALITEE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMBREREQUETTES"));
    return model;
}
QSqlQueryModel * EquipeMaintenance::TrierRequettes()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from Equipemaintenance ORDER BY NOMBREREQUETTES DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("CHEFEQUIPE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("SPECIALITEE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMBREREQUETTES"));
    return model;
}

#include "requette.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
Requette::Requette()
{
    this->ref="0";
    this->EquipeId="ideq";
    this->Service="Urgence";
    this->TypeMaintenance="typem";
    this->Etat="etat";
}
Requette::Requette(QString ref,QString ideq,QString service,QString typem,QString etat)
{
    this->ref=ref;
    this->EquipeId=ideq;
    this->Service=service;
    this->TypeMaintenance=typem;
    this->Etat=etat;
}
Requette::Requette(QString ref,QString ideq,QString service,QString typem,QString etat,QDate date)
{
    this->ref=ref;
    this->EquipeId=ideq;
    this->Service=service;
    this->TypeMaintenance=typem;
    this->Etat=etat;
    this->DateRq=date;
}
bool Requette::AjouterReq()
{
QSqlQuery query;
query.prepare("INSERT into Requettes (REFERENCE,EQUIPEID,TYPEMAINTENANCE,ETAT,SERVICE,DATEAAJOUT)""values(:REFERENCE,:EQUIPEID,:TYPEMAINTENANCE,:ETAT,:SERVICE,:DATEAAJOUT) ");
query.bindValue(":REFERENCE",ref);
query.bindValue(":EQUIPEID",EquipeId);
query.bindValue(":TYPEMAINTENANCE",TypeMaintenance);
query.bindValue(":ETAT",Etat);
query.bindValue(":SERVICE",Service);
query.bindValue(":DATEAAJOUT",DateRq);
return query.exec();
}
QSqlQueryModel * Requette::AfficherReq()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Requettes");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPEMAINTENANCE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SERVICE"));
    return model;
}
bool Requette::SupprimerReq(QString ref)
{
    QSqlQuery query;
    query.prepare("Delete from REQUETTES where REFERENCE = :reference");
    query.bindValue(":reference", ref);
    return query.exec();
}

bool Requette::ModifierReq(QString EqId,QString TypeM,QString Et,QString Serv)
{
    QSqlQuery query;
    //query.prepare("UPDATE Requettes SET equipeid ='"+EqId+"', typemaintenance = '"+TypeM+ "' , etat= '"+Et+"' , service= '"+Serv+"' WHERE reference ="+infotmp);
    query.prepare("UPDATE Requettes SET equipeid=:equipeid,typemaintenance=:typemaintenance,etat=:etat,service=:service WHERE reference=:val");
    query.bindValue(":equipeid",EqId);
    query.bindValue(":typemaintenance",TypeM);
    query.bindValue(":etat",Et);
    query.bindValue(":service",Serv);
    query.bindValue(":val",infotmp);

    return query.exec();
}
QSqlQueryModel * Requette::RechercheReqbyRef()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from Requettes WHERE reference='"+infotmp+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPEMAINTENANCE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SERVICE"));
    return model;
}
QSqlQueryModel * Requette::RechercheReqbyService()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from Requettes WHERE service='"+infotmp+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPEMAINTENANCE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SERVICE"));
    return model;
}
QSqlQueryModel * Requette::RechercheReqbyEtat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from Requettes WHERE ETAT='"+infotmp+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPEMAINTENANCE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SERVICE"));
    return model;
}
QSqlQueryModel * Requette::TrierParREF()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from REQUETTES ORDER BY REFERENCE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPEMAINTENANCE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SERVICE"));
    return model;
}
QSqlQueryModel * Requette::TrierParDATE()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from REQUETTES ORDER BY REFERENCE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("REFERENCE"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEID"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPEMAINTENANCE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SERVICE"));
    return model;
}

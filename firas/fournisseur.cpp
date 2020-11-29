#include "fournisseur.h"

fournisseur::fournisseur()
{

}


fournisseur::fournisseur(QString n, QString m,QString a):NOM(n),MATRICULE(m),ADRESSE(a)
{

}
bool fournisseur::ajouter()
{
    QSqlQuery query;



    query.prepare("INSERT INTO fournisseur (NOM,MATRICULE,ADRESSE)"
                  "VALUES (:NOM,:MATRICULE,:ADRESSE)");

    query.bindValue(":NOM",NOM);
    query.bindValue(":MATRICULE",MATRICULE);
    query.bindValue(":ADRESSE",ADRESSE);
    return query.exec();
}


QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select * from fournisseur");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}


bool fournisseur::supprimer(QString NOM)
{
    QSqlQuery qry;
    qry.prepare("Delete from fournisseur where NOM = :NOM");
    qry.bindValue(":NOM",NOM);
    return qry.exec();
}

QSqlQueryModel * fournisseur::chercher_four(QString chaine,int valeur)
{
    QSqlQuery q;
    if (valeur==1)
    {   q.prepare("select * from fournisseur where MATRICULE=:chaine");
        q.bindValue(":chaine", chaine);
        q.exec();
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(q);
        QSqlRecord rec=model->record(0);
        QString ch=rec.value("MATRICULE").toString();
        if(ch==chaine)
                return model;
    }
    else  if (valeur==2)
    {   q.prepare("select * from fournisseur where NOM=:chaine");
        q.bindValue(":chaine", chaine);
        q.exec();
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(q);
        QSqlRecord rec=model->record(0);
        QString ch=rec.value("NOM").toString();
        if (ch==chaine)
                return model;
    }
    else  if (valeur==3)
    {   q.prepare("select * from fournisseur where ADRESSE=:chaine");
        q.bindValue(":chaine", chaine);
        q.exec();
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(q);
        QSqlRecord rec=model->record(0);
        QString ch=rec.value("ADRESSE").toString();
        if (ch==chaine)
                return model;
    }
        return nullptr;



}


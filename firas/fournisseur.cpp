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

    model->setQuery("SELECT * FROM FOURNISSEUR");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MATRICULE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    return model;
}


bool fournisseur::supprimer(QString MATRICULE)
{
    QSqlQuery qry;
    qry.prepare("Delete from FOURNISSEUR where MATRICULE = :MATRICULE");
    qry.bindValue(":MATRICULE",MATRICULE);
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
QSqlQueryModel * fournisseur::trier_four(QString critere,int ordre)
{
   QSqlQuery *qry=new QSqlQuery();
   QSqlQueryModel *model=new QSqlQueryModel();
   if(critere=="NOM")
    {
       if(ordre==1)
            qry->prepare("select * from FOURNISSEUR order by NOM ASC");
       else
           qry->prepare("select * from FOURNISSEUR order by NOM DESC");
       }
   else if(critere=="MATRICULE")
   {
      if(ordre==1)
           qry->prepare("select * from FOURNISSEUR order by MATRICULE ASC");
      else
          qry->prepare("select * from FOURNISSEUR order by MATRICULE DESC");
      }
   else if(critere=="ADRESSE")
   {
      if(ordre==1)
           qry->prepare("select * from FOURNISSEUR order by ADRESSE ASC");
      else
          qry->prepare("select * from FOURNISSEUR order by ADRESSE DESC");
      }
   qry->exec();
   model->setQuery(*qry);
   return model;
}




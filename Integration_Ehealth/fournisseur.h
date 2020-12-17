#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

class fournisseur
{

       QString NOM;
       QString MATRICULE;
       QString ADRESSE;
public:
       fournisseur();
       fournisseur(QString,QString,QString);
       QString get_NOM(){return NOM;}
       QString get_MATRICULE(){return MATRICULE;}
       QString get_ADRESSE(){return ADRESSE;}

       void set_NOM(QString n){NOM=n;}
       void set_MATRICULE(QString m){MATRICULE=m;}
       void set_ADRESSE(QString a){ADRESSE=a;}

       bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(QString);
       QSqlQueryModel * chercher_four(QString,int);
       QSqlQueryModel * trier_four(QString,int);

};

#endif // FOURNISSEUR_H

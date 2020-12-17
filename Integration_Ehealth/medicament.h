#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QTableView>
#include <QFileDialog>
#include<QCoreApplication>
#include<QTextStream>
class Medicament
{

       QString NOM;
       QString TYPE;
       int QUANTITE;
       QDate DATE_EXP;
       QString FOURNISSEUR;
       QString REFERENCE;
public:
       Medicament();
       Medicament(QString,QString,int,QString,QDate,QString);
       QString get_NOM(){return NOM;}
       int get_QUANTITE(){return QUANTITE;}
       QDate get_DATE_EXP(){return DATE_EXP;}
       QString get_TYPE(){return TYPE;}
       QString get_FOURNISSEUR(){return FOURNISSEUR;}
       QString get_REFERENCE(){return REFERENCE;}

       void set_NOM(QString n){NOM=n;}
       void set_QUANTITE(int q){QUANTITE=q;}
       void set_DATE_EXP(QDate d){DATE_EXP=d;}
       void set_TYPE(QString t){TYPE=t;}
       void set_FOURNISSEUR(QString f){FOURNISSEUR=f;}
       void set_REFERENCE(QString r){REFERENCE=r;}

       bool ajouter();
       QSqlQueryModel * afficher();
       bool supprimer(QString);
       QSqlQueryModel * chercher_med(QString,int);
       void exporter(QTableView* tableau);

};

#endif // MEDICAMENT_H

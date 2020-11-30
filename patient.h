#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include<QSqlRecord>
#include<QTableView>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QApplication>

class patient
{
public:
    patient();
    patient(QString ,QString,int , int ,QDate, QString ,QString);
    QString getcin(){return cin;}
    QString getid(){return id;}
    int getage(){return age;}
    int getduree(){return duree;}
    QDate getdate_entrer(){return Date_entrer;}
    QString getnom() {return nom;}
    QString getprenom() {return prenom;}
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(QString);
bool update(QString ,QString,int,int, QDate  ,QString ,QString);
QSqlQueryModel *rechercher_patient(QString,QString,QString);
QSqlQueryModel *trier(QString crit);
void exporter(QTableView *table);

private:
    QString cin ;
    QString id;
    int age;
    int duree;
    QDate Date_entrer;
    QString nom, prenom;
};

#endif // PATIENT_H

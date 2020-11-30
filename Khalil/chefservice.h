#ifndef CHEFSERVICE_H
#define CHEFSERVICE_H
#include <QString>
#include <QSqlQueryModel>


class Chefservice
{
    int id;
    QString nom,prenom,idstring;


public:
    Chefservice();
    Chefservice(int,QString,QString);
    Chefservice(QString,QString,QString);
    void setIDtmp(int);
    void setStringtmp(QString);
    int getId(){return id;}
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    bool ajouterChefSv();
    bool supprimerChefSv(int);
    bool modifierChefSv(QString,QString);
    QSqlQueryModel * searchChefSvAvanceeSV(QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercheChefSv(QString);

};

#endif // CHEFSERVICE_H

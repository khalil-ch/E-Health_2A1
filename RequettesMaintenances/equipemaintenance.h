#ifndef EQUIPEMAINTENANCE_H
#define EQUIPEMAINTENANCE_H
#include <QString>
#include <QSqlQueryModel>

class EquipeMaintenance
{
protected:
    QString IdEquipe,infotmp;
    QString ChefEquipe;
    QString Specialitee;
    QString NbReq;
public:
    QString test(){return "hello world";}
    EquipeMaintenance();
    EquipeMaintenance(QString,QString,QString,QString);
    QSqlQueryModel * AfficherEq();
    void SetInfotmp2(QString newinfo){infotmp=newinfo;}
    bool AjouterEq();
    bool SupprimerEq(QString);
    bool ModifierEq(QString,QString,QString,QString);
    QSqlQueryModel * RechercheEqbyId();
    QSqlQueryModel * RechercheEqbySpec();
};

#endif // EQUIPEMAINTENANCE_H

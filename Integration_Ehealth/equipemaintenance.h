#ifndef EQUIPEMAINTENANCE_H
#define EQUIPEMAINTENANCE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class EquipeMaintenance
{
protected:
    QString IdEquipe,infotmp;
    QString ChefEquipe;
    QString Specialitee;
    QString NbReq;

public:
    QString test(){return "";}
    EquipeMaintenance();
    EquipeMaintenance(QString,QString,QString,QString);
    QSqlQueryModel * AfficherEq();
    void SetInfotmp2(QString newinfo){infotmp=newinfo;}
    bool AjouterEq();
    bool SupprimerEq(QString);
    bool ModifierEq(QString,QString,QString);
    bool Login(int,QString);
    QSqlQueryModel * RechercheEqbyId();
    QSqlQueryModel * RechercheEqbySpec();
    QSqlQueryModel * TrierNom();
    QSqlQueryModel * TrierRequettes();
};

#endif // EQUIPEMAINTENANCE_H

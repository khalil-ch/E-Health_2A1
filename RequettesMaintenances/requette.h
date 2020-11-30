#ifndef REQUETTE_H
#define REQUETTE_H
#include <QString>
#include <QSqlQueryModel>

class Requette
{
protected:
    QString ref,infotmp;
    QString EquipeId;
    QString Service;
    QString TypeMaintenance;
    QString Etat;
public:
    Requette();
    Requette(QString,QString,QString,QString,QString);
    void SetInfotmp(QString newref){infotmp=newref;}
    bool AjouterReq();
    QSqlQueryModel * AfficherReq();
    bool SupprimerReq(QString);
    bool ModifierReq(QString,QString,QString,QString);
    QSqlQueryModel * RechercheReqbyRef();
    QSqlQueryModel * RechercheReqbyService();
};

#endif // REQUETTE_H

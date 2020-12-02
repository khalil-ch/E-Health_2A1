#ifndef REQUETTE_H
#define REQUETTE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
class Requette
{
protected:
    QString ref,infotmp;
    QString EquipeId;
    QString Service;
    QString TypeMaintenance;
    QString Etat;
    QDate DateRq;
public:
    Requette();
    Requette(QString,QString,QString,QString,QString);
    Requette(QString ,QString ,QString ,QString ,QString ,QDate );
    void SetInfotmp(QString newref){infotmp=newref;}
    bool AjouterReq();
    QSqlQueryModel * AfficherReq();
    bool SupprimerReq(QString);
    bool ModifierReq(QString,QString,QString,QString);
    QSqlQueryModel * RechercheReqbyRef();
    QSqlQueryModel * RechercheReqbyService();
    QSqlQueryModel * TrierParREF();
    QSqlQueryModel * TrierParDATE();
};

#endif // REQUETTE_H

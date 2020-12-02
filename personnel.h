#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class personnel
{public:
    personnel();
    personnel(int,QString,QString,QString);
    QString get_type();
    QString get_nom();
    QString get_prenom();


    int get_cin();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
QSqlQueryModel * rechercher(QString);
QSqlQueryModel *tri();

private:

    int cin;

      QString type;
      QString nom;
      QString prenom;
};
;
#endif // PERSONNEL_H

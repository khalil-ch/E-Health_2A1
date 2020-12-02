#ifndef SERVICE_H
#define SERVICE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class service
{public:
    service();
    service(int,int,QString);
    QString get_typeservice();


    int get_idservice();
    int get_cinchef();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int , QString  );
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel *tri();

private:

    int idservice;
     int cinchef;

      QString typeservice;

};
#endif // SERVICE_H

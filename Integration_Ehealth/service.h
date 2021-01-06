#ifndef SERVICE_H
#define SERVICE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QDir>
#include <QApplication>
#include<QTableView>



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
    void excelaziz(QTableView *table);

private:

    int idservice;
     int cinchef;

      QString typeservice;

};
#endif // SERVICE_H

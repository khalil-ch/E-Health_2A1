#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>


class equipement
{
public:
    equipement();
  equipement(QString,QString,QString,QString,int);
  QString get_nom();
  QString get_type;
  QString get_modele();
  QString get_condition();
  int get_numdeserie();
  bool ajouter();
      bool modifier(int);
       QSqlQueryModel * afficher();
        bool supprimer(int);
private:
     QString nom, type, condition, modele;
     int numdeserie;


};

#endif // EQUIPEMENT_H

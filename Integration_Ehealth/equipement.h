#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class equipement
{



private:
QString nom;
QString numdeserie;
QString modele;
QString type;
QString condition;
QString description;
public:
  equipement();
  equipement(QString,QString,QString,QString,QString,QString);
  QString getnom() const;
  void setnom(const QString &value);

  QString getnumdeserie() const;
  void setnumdeserie(const QString &value);
  QString getmodele() const;
  void setmodele(const QString &value);
  QString gettype() const;
  void settype(const QString &value);
  QString getcondition() const;
  void setcondition(const QString &value);
  QString getdescription() const;
  void setdescription(const QString &value);








  bool Ajouterequipement();

  QSqlQueryModel* Afficherequipement(QString);

  QSqlQueryModel* Searchequipement(QString);


  bool Supprimerequipement(QString);

  bool modifierequipement(QString);

  //void SortByHeader(int);
};

#endif // VOITURE_H

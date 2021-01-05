#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class vehicule
{



private:
QString nom;
QString modele;
QString categorie;
QString desinfectation;
QString description;;
public:
  vehicule();
   vehicule(QString,QString,QString,QString,QString);
  QString getnom() const;
  void setnom(const QString &value);
  QString getmodele() const;
  void setmodele(const QString &value);
  QString getcategorie() const;
  void setcategorie(const QString &value);
  QString getdesinfectation() const;
  void setdesinfectation(const QString &value);

  QString getdescription() const;
  void setdescription(const QString &value);





  bool Ajoutervehicule();

  QSqlQueryModel* Affichervehicule(QString);

  QSqlQueryModel* Searchvehicule(QString);


  bool Supprimervehicule(QString);

  bool modifiervehicule(QString);

  //void SortByHeader(int);
};

#endif // VOITURE_H

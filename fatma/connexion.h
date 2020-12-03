#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class Connexion
{
    QSqlDatabase db;
public:
    Connexion();
    bool ouvrirConnexion();
    bool fermeConnexion();
};

#endif // CONNEXION_H

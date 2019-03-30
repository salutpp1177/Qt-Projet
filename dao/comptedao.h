#ifndef COMPTEDAO_H
#define COMPTEDAO_H

#include <QSqlDatabase>
#include <QSqlError>
#include <model/compte.h>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <QObject>
#include <vector>
#include "connectdatabase.h"

class compteDao
{
private:
    QSqlDatabase db;
public:
    compteDao();
    ~compteDao();
    bool addCompte(int id_res, QString login, QString pwd);
    bool modifyCompte(Compte &cpt);
    Compte selectCompteById(int id);
    Compte selectCompteByIdRessource(int id);
    Compte selectCompteByLogin(QString login, QString mdp);
    bool deleteCompteByIdRessource(int id);
};

#endif // COMPTEDAO_H

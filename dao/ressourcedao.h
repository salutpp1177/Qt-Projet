#ifndef RESSOURCEDAO_H
#define RESSOURCEDAO_H

#include <QSqlDatabase>
#include <QSqlError>
#include <model/ressource.h>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <QObject>
#include <vector>
#include "connectdatabase.h"

using namespace std;
class ressourceDao
{
private:
    QSqlDatabase db;
public:
    ressourceDao();
    ~ressourceDao();


    bool addRessource(Ressource &res);
    bool addRessource(int id, QString nom, QString prenom, int type);
    bool deleteRessouceById(int id);
    bool modifyRessouce(Ressource &res);
    Ressource selectRessourceById(int id);
    Ressource selectRessourceByNom(QString nom, QString prenom, int id_type);
    vector<Ressource> selectAllRessource() const;
    int getMaxId();


};

#endif // RESSOURCEDAO_H

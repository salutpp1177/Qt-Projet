#ifndef CONSULTDAO_H
#define CONSULTDAO_H
#include <QSqlDatabase>
#include <QSqlError>
#include <model/consult.h>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <iostream>
#include <QObject>
#include <vector>
#include "connectdatabase.h"

class consultDao
{
private:
    QSqlDatabase db;
public:
    consultDao();
    ~consultDao();
    bool addConsult(int id_pat, int id_res);
    bool deleteConsultById(int id);
    bool deleteConsultById(int id_pat, int id_res);
    bool modifyConsult(int id, int id_pat, int id_res);
    Consult selectConsultById(int id);
    Consult selectConsultById(int id_pat, int id_res);
    vector<Consult> selectAllConsult();
    int getMaxId();
    vector<int> selectRessourceByIdPatient(int ipat);
};

#endif // CONSULTDAO_H

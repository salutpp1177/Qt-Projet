#ifndef TYPEPARMIDAO_H
#define TYPEPARMIDAO_H

#include <QSqlDatabase>
#include <QSqlError>
#include <model/typeparmi.h>
#include <QString>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <vector>
#include "connectdatabase.h"

using namespace std;
class typeparmiDao
{
private:
    QSqlDatabase db;
public:
    typeparmiDao();
    ~typeparmiDao();

    TypeParmi selectTypeById(int id);
    TypeParmi selectTypeByName(QString name);
    vector<TypeParmi> selectAllType();

};

#endif // TYPEPARMIDAO_H

#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H

#include <QSqlQuery>
#include <QDebug>
#include <vector>
#include <QSqlError>


class connectDataBase
{
private:
    static connectDataBase *ConnectDataBase;
    QSqlDatabase db;
    connectDataBase();

public:
    static connectDataBase *getConnection();
    bool disconnectDB();
    QSqlDatabase& getDb() { return db; }
};

#endif // CONNECTDATEBASE_H

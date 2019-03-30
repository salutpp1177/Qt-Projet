#include "connectdatabase.h"

connectDataBase* connectDataBase::ConnectDataBase = NULL;

/**
 * @brief constructor to realize connection to data base
 */
connectDataBase::connectDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    if(db.isValid())
    {
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("password");
        db.setDatabaseName("base_tmp.sqli");
        db.open();
        if(!db.open()) {
            qDebug() << "Error: connection with database failed";
        } else {
            qDebug() << "Database: connection ok";
        }
    }
}

/**
 * @brief build the connection
 * @return a point of connectDataBase
 */
connectDataBase* connectDataBase::getConnection()
{
    if(ConnectDataBase == NULL) {
        ConnectDataBase = new connectDataBase();
    }
    return ConnectDataBase;
}

/**
 * @brief disconnect from data base
 * @return a flag representing whether manipulation works or not
 */
bool connectDataBase::disconnectDB()
{
    db.close();
    db.removeDatabase("QSQLITE");
    return true;
}

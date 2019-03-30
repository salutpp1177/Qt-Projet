#include "typeparmidao.h"
/**
 * @brief constructor which is in charge of connecting data base
 */
typeparmiDao::typeparmiDao()
{
    connectDataBase *conn = connectDataBase::getConnection();
    db = conn->getDb();
}

/**
 * @brief desctructor
 */
typeparmiDao::~typeparmiDao()
{

}

/**
 * @brief select a type label by id
 */
TypeParmi typeparmiDao::selectTypeById(int id)
{    TypeParmi type;
     QSqlQuery query(db);
     query.prepare("SELECT * FROM TType WHERE Id = :id");
     query.bindValue(":id",id);
     query.exec();
     while (query.next()) {
        int i = query.value(0).toInt();
        QString type_name = query.value(1).toString();
        type.setIdTypeParmi(i);
        type.setTypeName(type_name);
     }
     return type;
}

/**
 * @brief select a type label by label
 */
TypeParmi typeparmiDao::selectTypeByName(QString name)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TType WHERE Label = :label");
    query.bindValue(":label", name);
    query.exec();
    TypeParmi type;
    while (query.next()) {
        int id = query.value(0).toInt();
        QString type_name = query.value(1).toString();
        type.setIdTypeParmi(id);
        type.setTypeName(name);
    }
    return type;
}

/**
 * @brief select all the types
 */
vector<TypeParmi> typeparmiDao::selectAllType()
{
    vector<TypeParmi> vec;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TType");
    query.exec();
    while (query.next()) {
        int id = query.value(0).toInt();
        QString label = query.value(1).toString();
        TypeParmi type;
        type.setTypeName(label);
        type.setIdTypeParmi(id);
        vec.push_back(type);
    }
    return vec;
}




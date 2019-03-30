#include "consultdao.h"
/**
 * @brief constructor which is in charge of connecting data base
 */
consultDao::consultDao()
{
    connectDataBase *conn = connectDataBase::getConnection();
    db = conn->getDb();
}

/**
 * @brief desctructor
 */
consultDao::~consultDao()
{

}

/**
 * @brief add a consult
 * @param id_pat
 * @param id_res
 * @return a flag representing whether manipulation works or not
 */
bool consultDao::addConsult(int id_pat, int id_res)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("INSERT INTO TConsult (IdPatient, IdRessource) VALUES (:ipat, :ires);");
    query.bindValue(":ipat", id_pat);
    query.bindValue(":ires", id_res);
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    auto bla = query.executedQuery();
    return success;

}

/**
 * @brief delete a consult by id
 * @param id
 * @return a flag representing whether manipulation works or not
 */
bool consultDao::deleteConsultById(int id)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM TConsult WHERE Id =:id;");
    query.bindValue(":id", id);
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}

/**
 * @brief delete consult
 * @param
 * @param
 * @return a flag representing whether manipulation works or not
 */
bool consultDao::deleteConsultById(int id_pat, int id_res)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM TConsult WHERE IdPatient =:ipat AND IdRessource =:ires;");
    query.bindValue(":ipat", id_pat);
    query.bindValue(":ires", id_res);
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}
/**
 * @brief Modify a consult
 * @param pat
 * @return a flag representing whether manipulation works or not
 */
bool consultDao::modifyConsult(int id, int id_pat, int id_res)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("UPDATE TConsult SET IdPatient = :ipat, IdRessource = :ires WHERE Id = :id;");
    query.bindValue(":ipat", id_pat);
    query.bindValue(":ires", id_res);
    query.bindValue(":id",id);
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}

/**
 * @brief select a consult by id
 * @param id
 * @return a consult
 */
Consult consultDao::selectConsultById(int id)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TConsult where Id = ?");
    query.addBindValue(id);
    query.exec();
    qDebug() << query.lastQuery();
    Consult cst;
    while ( query.next() ) {
        int i = query.value(0).toInt();
        int ipat = query.value(1).toInt();
        int ires = query.value(2).toInt();
        cst.setIdConsult(i);
        cst.setPatient(ipat);
        cst.setRessource(ires);
    }
    return cst;

}

/**
 * @brief select a consult
 * @param
 * @param
 * @return a consult
 */
Consult consultDao::selectConsultById(int id_pat, int id_res)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TConsult where IdPatient = :ipat AND IdRessource = :ires;");
    query.bindValue("ipat", id_pat);
    query.bindValue(":ires", id_res);
    query.exec();
    qDebug() << query.lastQuery();
    Consult cst;
    while ( query.next() ) {
        int i = query.value(0).toInt();
        int ipat = query.value(1).toInt();
        int ires = query.value(2).toInt();
        cst.setIdConsult(i);
        cst.setPatient(ipat);
        cst.setRessource(ires);
    }
    return cst;
}

/**
 * @brief select all consults
 * @return a vector of all consults
 */
vector<Consult> consultDao::selectAllConsult()
{
    vector<Consult> vec_cst;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TConsult");
    query.exec();
    while (query.next()) {
        int id = query.value(0).toInt();
        int ipat = query.value(1).toInt();
        int ires = query.value(2).toInt();
        Consult cst;
        cst.setIdConsult(id);
        cst.setPatient(ipat);
        cst.setRessource(ires);
        vec_cst.push_back(cst);
    }
    return vec_cst;
}

/**
 * @brief Select the maximum of Id
 * @return max.id
 */
int consultDao::getMaxId()
{
    QSqlQuery query(db);
    query.prepare("SELECT MAX(Id) FROM TConsult;");
    query.exec();
    qDebug() << query.lastQuery();
    int max_id = 0;
    while ( query.next() ) {
        max_id = query.value(0).toInt();
    }
    return max_id;

}

/**
 * @brief select the consults by id_pat
 * @param id
 * @return a vector of all consults
 */
vector<int> consultDao::selectRessourceByIdPatient(int ipat)
{    vector<int> vec;
     QSqlQuery query(db);
     query.prepare("SELECT IdRessource FROM TConsult WHERE IdPatient = :id");
     query.bindValue(":id", ipat);
     query.exec();
     while (query.next()) {
         int ires = query.value(0).toInt();
         vec.push_back(ires);
     }
     return vec;

}

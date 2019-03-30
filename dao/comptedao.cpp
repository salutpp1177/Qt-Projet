#include "comptedao.h"
/**
 * @brief constructor which is in charge of connecting data base
 */
compteDao::compteDao()
{
    connectDataBase *conn = connectDataBase::getConnection();
    db = conn->getDb();
}

/**
 * @brief desctructor
 */
compteDao::~compteDao()
{

}

/**
 * @brief Add an account
 * @param id_res
 * @param login
 * @param pwd
 * @return a flag representing whether manipulation works or not
 */
bool compteDao::addCompte(int id_res, QString login, QString pwd)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("INSERT INTO TCompte (IdRessource, Login, Mdp) VALUES (:id, :log, :mdp)");
    query.bindValue(":id",id_res);
    query.bindValue(":log", login);
    query.bindValue(":mdp", pwd);
    if(query.exec()) {
        success = true;
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}

/**
 * @brief Modify an account
 * @param cpt
 * @return a flag representing whether manipulation works or not
 */
bool compteDao::modifyCompte(Compte &cpt)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("UPDATE TCompte SET IdRessource = :id_res , Login = :log , MdP = :mdp WHERE Id = :id");
    query.bindValue(":id_res", cpt.getIdRessource());
    query.bindValue(":log", cpt.getIdCompte());
    query.bindValue(":mdp", cpt.getMotdepasse());
    query.bindValue(":id", cpt.getIdCompte());
    if(query.exec()) {
        success = true;
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}

Compte compteDao::selectCompteById(int id)
{
    Compte cpt;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TCompte WHERE Id = :id");
//    query.prepare("SELECT * FROM TCompte WHERE IdRessource = :id");
    query.bindValue(":id", id);
    if(query.exec()) {
        while(query.next()) {
            int i = query.value(0).toInt();
            int id_res = query.value(1).toInt();
            QString login = query.value(2).toString();
            QString mdp = query.value(3).toString();
            cpt.setIdCompte(i);
            cpt.setRessource(id_res);
            cpt.setLogin(login);
            cpt.setMotdepasse(mdp);
        }
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return cpt;
}

Compte compteDao::selectCompteByLogin(QString login, QString mdp)
{
    Compte cpt;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TCompte WHERE Login = :login AND MdP = :mdp");
    query.bindValue(":login", login);
    query.bindValue(":mdp", mdp);
    if(query.exec()) {
        while(query.next()) {
            int i = query.value(0).toInt();
            int id_res = query.value(1).toInt();
            QString login = query.value(2).toString();
            QString mdp = query.value(3).toString();
            cpt.setIdCompte(i);
            cpt.setRessource(id_res);
            cpt.setLogin(login);
            cpt.setMotdepasse(mdp);
        }
    } else {
            qDebug() << "error :" << query.lastError().text();
    }
    return cpt;
}

Compte compteDao::selectCompteByIdRessource(int id)
{
    Compte cpt;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TCompte WHERE IdRessource = :id");
    query.bindValue(":id", id);
    if(query.exec()) {
        while(query.next()) {
            int i = query.value(0).toInt();
            int id_res = query.value(1).toInt();
            QString login = query.value(2).toString();
            QString mdp = query.value(3).toString();
            cpt.setIdCompte(i);
            cpt.setRessource(id_res);
            cpt.setLogin(login);
            cpt.setMotdepasse(mdp);
        }
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return cpt;
}

/**
 * @brief Delete an account by IdRessource
 * @param id
 * @return a flag representing whether manipulation works or not
 */
bool compteDao::deleteCompteByIdRessource(int id)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM TCompte WHERE IdRessource = :id;");
    query.bindValue(":id", id);
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}




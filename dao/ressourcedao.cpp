#include "ressourcedao.h"
/**
 * @brief constructor which is in charge of connecting data base
 */
ressourceDao::ressourceDao()
{
    connectDataBase *conn = connectDataBase::getConnection();
    db = conn->getDb();
}

/**
 * @brief desctructor
 */
ressourceDao::~ressourceDao()
{

}
/**
 * @brief inserter une ressource
 */
bool ressourceDao::addRessource(Ressource &res)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) VALUES (:nom, :prenom, :idtype);");
    query.bindValue(":nom", res.getNom());
    query.bindValue(":prenom", res.getPrenom());
    query.bindValue(":idtype", res.getType());
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
 * @brief ajouter une nouvelle ressource
 */
bool ressourceDao::addRessource(int id, QString nom, QString prenom, int type)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("INSERT INTO TRessource (Id, Nom, Prenom, IdType) VALUES (:id, :nom, :prenom, :idtype);");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":idtype", type);
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
 * @brief supprimer une ressource par id
 */
bool ressourceDao::deleteRessouceById(int id)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM TRessource WHERE Id =:id;");
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
 * @brief modifier une ressource
 */
bool ressourceDao::modifyRessouce(Ressource &res)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("UPDATE TRessource SET Nom = :nom, Prenom = :prenom, IdType = :idtype WHERE Id = :id;");
    query.bindValue(":nom", res.getNom());
    query.bindValue(":prenom", res.getPrenom());
    query.bindValue(":idtype", res.getType());
    query.bindValue(":id",res.getIdRessource());
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}

/**
 * @brief selectionner une ressource par id
 */
Ressource ressourceDao::selectRessourceById(int id) {
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TRessource where Id = ?");
    query.addBindValue(id);
    query.exec();
    qDebug() << query.lastQuery();
    Ressource res;
    while ( query.next() ) {
        int i = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        int type_id = query.value(3).toInt();
        res.setIdRessource(i);
        res.setNom(nom);
        res.setPrenom(prenom);
        res.setType(type_id);
    }
    return res;
}

/**
 * @brief selectionner une ressource par nom, prenom, et id_type
 */
Ressource ressourceDao::selectRessourceByNom(QString nom, QString prenom, int id_type)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TRessource WHERE IdType = :id AND Nom = :nom AND prenom = :prenom");
    query.bindValue(":id", id_type);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.exec();
    qDebug() << query.lastQuery();
    Ressource res;
    while (query.next()) {
        int i = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        int type_id = query.value(3).toInt();
        res.setIdRessource(i);
        res.setNom(nom);
        res.setPrenom(prenom);
        res.setType(type_id);
    }
    return res;
}

/**
 * @brief selectionner toutes les ressources
 */
vector<Ressource> ressourceDao::selectAllRessource() const {
    vector<Ressource> vec_res;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TRessource");
    query.exec();
    while (query.next()) {
        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        int type_id = query.value(3).toInt();
        Ressource res;
        res.setIdRessource(id);
        res.setNom(nom);
        res.setPrenom(prenom);
        res.setType(type_id);
        vec_res.push_back(res);
    }
    return vec_res;
}

/**
 * @brief Select the maximum of Id
 * @return max.id
 */
int ressourceDao::getMaxId()
{
    QSqlQuery query(db);
    query.prepare("SELECT MAX(Id) FROM TRessource;");
    query.exec();
    qDebug() << query.lastQuery();
    int max_id = 0;
    while ( query.next() ) {
        max_id = query.value(0).toInt();
    }
    return max_id;

}


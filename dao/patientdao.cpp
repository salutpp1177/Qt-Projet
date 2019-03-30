#include "patientdao.h"

/**
 * @brief constructor which is in charge of connecting data base
 */
patientDao::patientDao()
{
    connectDataBase *conn = connectDataBase::getConnection();
    db = conn->getDb();
}

/**
 * @brief desctructor
 */
patientDao::~patientDao()
{

}

/**
 * @brief Add a patient without defining Id
 * @param pat
 */
void patientDao::addPatient(Patient &pat)
{

    QSqlQuery query(db);
    QString sqlString = "INSERT INTO TPatient"
                        "(Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite)"
                        "VALUES ( :Nom, :Prenom, :Adresse, :Ville, :CP, :Commentaire, :Tel, :DateConsul, :DureeConsul, :Priorite)";
    query.prepare(sqlString);
    query.bindValue(":Nom",pat.getNom());
    query.bindValue(":Prenom", pat.getPrenom());
    query.bindValue(":Adresse", pat.getAdress());
    query.bindValue(":Ville", pat.getVille());
    query.bindValue(":CP", pat.getCodePostale());
    query.bindValue(":DateConsul",pat.getDate());
    query.bindValue(":DureeConsul", pat.getDuree());
    query.bindValue(":Priorite", pat.getPriorite());
    query.bindValue(":Commentaire", pat.getComments());
    query.bindValue(":Tel", pat.getTelephone());
    if(query.exec()) {
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }


}

/**
 * @brief Add a patient
 * @param pat
 */
void patientDao::addPatient(Patient &pat, int id)
{
    QSqlQuery query(db);
    QString sqlString = "INSERT INTO TPatient"
                        "(Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite)"
                        "VALUES (:Id, :Nom, :Prenom, :Adresse, :Ville, :CP, :Commentaire, :Tel, :DateConsul, :DureeConsul, :Priorite)";
    query.prepare(sqlString);
    query.bindValue(":Id",id);
    query.bindValue(":Nom",pat.getNom());
    query.bindValue(":Prenom", pat.getPrenom());
    query.bindValue(":Adresse", pat.getAdress());
    query.bindValue(":Ville", pat.getVille());
    query.bindValue(":CP", pat.getCodePostale());
    query.bindValue(":DateConsul",pat.getDate());
    query.bindValue(":DureeConsul", pat.getDuree());
    query.bindValue(":Priorite", pat.getPriorite());
    query.bindValue(":Commentaire", pat.getComments());
    query.bindValue(":Tel", pat.getTelephone());
    if(query.exec()) {
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
}

/**
 * @brief Select a patient by Id
 * @param id
 * @return a patient
 */
Patient patientDao::selectPatientById(int id) const{
    QSqlQuery query(db);
    QString sqlString  = "select * from TPatient where Id = :id";
    query.prepare(sqlString);
    query.bindValue(":id",id);
    query.exec();
    Patient pat;
    while(query.next()){
        int id  = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        QString adresse = query.value(3).toString();
        QString ville = query.value(4).toString();
        int cp = query.value(5).toInt();
        QString commentaire = query.value(6).toString();
        int tel = query.value(7).toInt();
        QDate dateConsul = query.value(8).toDate();
        int dureeConsul = query.value(9).toInt();
        int priorite = query.value(10).toInt();
        pat.setIdPatient(id);
        pat.setNom(nom);
        pat.setPrenom(prenom);
        pat.setAdress(adresse);
        pat.setVille(ville);
        pat.setCodePostale(cp);
        pat.setComments(commentaire);
        pat.setTelephone(tel);
        pat.setDate(dateConsul);
        pat.setDuree(dureeConsul);
        pat.setPriorite(priorite);
    }
    return pat;
}

/**
 * @brief Select a patient by query
 * @param id
 * @return a patient
 */
Patient patientDao::getPatientByQuery(QSqlQuery query)
{
    Patient pat;

    int id  = query.value(0).toInt();
    QString nom = query.value(1).toString();
    QString prenom = query.value(2).toString();
    QString adresse = query.value(3).toString();
    QString ville = query.value(4).toString();
    int cp = query.value(5).toInt();
    QString commentaire = query.value(6).toString();
    int tel = query.value(7).toInt();
    QDate dateConsul = query.value(8).toDate();
    int dureeConsul = query.value(9).toInt();
    int priorite = query.value(10).toInt();

    pat.setIdPatient(id);
    pat.setNom(nom);
    pat.setPrenom(prenom);
    pat.setAdress(adresse);
    pat.setVille(ville);
    pat.setCodePostale(cp);
    pat.setComments(commentaire);
    pat.setTelephone(tel);
    pat.setDate(dateConsul);
    pat.setDuree(dureeConsul);
    pat.setPriorite(priorite);

    return pat;
}

/**
 * @brief Modify a patient
 * @param pat
 * @return a flag representing whether modification succeeds or not
 */
bool patientDao::modifyPatient(Patient pat)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("UPDATE TPatient SET Nom=:nom, Prenom=:prenom, Adresse=:add, Ville=:v, CP=:cp, Commentaire=:comm, Tel=:t, DateConsultation=:data, DureeConsultation=:cst, Priorite=:p WHERE Id = :id;");
    query.bindValue(":nom", pat.getNom());
    query.bindValue(":prenom", pat.getPrenom());
    query.bindValue(":add", pat.getAdress());
    query.bindValue(":v", pat.getVille());
    query.bindValue(":cp", pat.getCodePostale());
    query.bindValue(":date",pat.getDate());
    query.bindValue(":cst", pat.getDuree());
    query.bindValue(":p", pat.getPriorite());
    query.bindValue(":comm", pat.getComments());
    query.bindValue(":t", pat.getTelephone());
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}

/**
 * @brief Modify a patient
 * @param pat
 * @return a flag representing whether manipulation works or not
 */
bool patientDao::deletePatientById(int id)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM TPatient WHERE Id =:id;");
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
 * @brief Delete a patient
 * @param nom
 * @param prenom
 * @return a flag representing whether manipulation works or not
 */
bool patientDao::deletePatientByName(QString nom, QString prenom)
{
    bool success = false;
    QSqlQuery query(db);
    query.prepare("DELETE FROM TPatient WHERE Nom =:nom AND Prenom = :prenom");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    if(query.exec()) {
        success = true;
        qDebug() << query.lastQuery();
    } else {
        qDebug() << "error :" << query.lastError().text();
    }
    return success;
}

/**
 * @brief Select all patients
 * @return a vector of all patients
 */
vector<Patient> patientDao::selectAllPatient()
{
    vector<Patient> vec_pat;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TPatient;");
    query.exec();
    while (query.next()) {
        vec_pat.push_back(getPatientByQuery(query));
    }
    return vec_pat;
}

/**
 * @brief Select the maximum of Id
 * @return max.id
 */
int patientDao::selectMaxId(){
    QSqlQuery query(db);
    QString sqlString  = "select MAX(Id) from TPatient";
    query.prepare(sqlString);
    query.exec();

    if(query.next()){
        return query.value(0).toInt();
    }else{
        return 0;
    }
}


/**
 * @brief Return all the patients queried by first name and last name
 * @param nom
 * @param prenom
 * @return a vector of all the query results
 */
vector<Patient> patientDao::selectPatientByName(QString nom, QString prenom)
{
    vector<Patient> vec_pat;
    QSqlQuery query(db);
    QString sql;
    if(prenom == nullptr) {
        sql = QString("SELECT * FROM TPatient WHERE Nom =:nom ORDER BY DateConsultation ASC;");
        query.prepare(sql);
        query.bindValue(":nom",nom);

    } else if(nom == nullptr) {
        sql = QString("SELECT * FROM TPatient WHERE Prenom =:prenom ORDER BY DateConsultation ASC;");
        query.prepare(sql);
        query.bindValue(":prenom",prenom);
    } else {
        sql = QString("SELECT * FROM TPatient WHERE Nom =:nom OR Prenom =:prenom ORDER BY DateConsultation ASC;");
        query.prepare(sql);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom", prenom);
    }
    query.exec();
    while (query.next()) {
        vec_pat.push_back(getPatientByQuery(query));
    }
    return vec_pat;

}

/**
 * @brief Return all the patients queried by date
 * @param begin date of begin
 * @param end date of end
 * @return a vector of all the query results
 */
vector<Patient> patientDao::selectPatientByDate(QString begin, QString end)
{
    vector<Patient> vec_pat;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TPatient WHERE DateConsultation BETWEEN :begin AND :end ORDER BY DateConsultation ASC;");
    query.bindValue(":begin", begin);
    query.bindValue(":end", end);
    query.exec();
    while (query.next()) {
        vec_pat.push_back(getPatientByQuery(query));
        qDebug() << query.lastQuery();
    }
    return vec_pat;
}

/**
 * @brief Returns all the patients queried by date and name (firstname or lastname)
 * @param begin begin-date
 * @param end ending-date
 * @param name firstname or lastname
 * @param flag to represent firstname or lastname, 0 is lastname
 * @return a vector of all the query results
 */
vector<Patient> patientDao::selectPatientByNameAndDate(QString begin, QString end, QString name, int flag)
{

    QString today = QDate::currentDate().toString();
    vector<Patient> vec_pat;
    QSqlQuery query(db);
    if(flag == 0) {
        query.prepare("SELECT * FROM TPatient WHERE Prenom = :prenom AND DateConsultation BETWEEN :begin AND :end ORDER BY DateConsultation ASC;");
        query.bindValue(":Nom",name);
    } else {
        query.prepare("SELECT * FROM TPatient WHERE Nom =:nom AND DateConsultation BETWEEN :begin AND :end ORDER BY DateConsultation ASC;");
        query.bindValue(":Prenom", name);
    }
    query.bindValue(":begin", begin);
    query.bindValue(":end", end);
    query.exec();
    while (query.next()) {
        vec_pat.push_back(getPatientByQuery(query));
    }
    return vec_pat;
}


/**
 * @brief Returns all the patients queried by name and date
 * @param nom
 * @param prenom
 * @param begin begin-date
 * @param end ending-date
 * @return a vector of all the query results
 */
vector<Patient> patientDao::selectPatientByNameAndDate(QString begin, QString end, QString nom, QString prenom)
{

    vector<Patient> vec_pat;
    QSqlQuery query(db);
    //Q 6
    query.prepare("SELECT * FROM TPatient WHERE Nom =:nom AND Prenom = :prenom AND DateConsultation BETWEEN :begin AND :end ORDER BY DateConsultation ASC;");
    query.bindValue(":Nom", nom);
    query.bindValue(":Prenom", prenom);
    if(begin== nullptr) {
        QString today = QDate::currentDate().toString();
        query.bindValue(":begin", today);
    } else {
        query.bindValue(":begin", begin);
    }
    query.bindValue(":end", end);
    query.exec();
    while (query.next()) {
        vec_pat.push_back(getPatientByQuery(query));
    }
    return vec_pat;
}



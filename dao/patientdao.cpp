#include "patientdao.h"

patientDao::patientDao()
{

}

void patientDao::addPatient(Patient &pat) {

    QSqlQuery query;
    query.prepare("INSERT INTO TPatient (Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite) "
                   "VALUES (:id, :nom, :prenom, :adresse, :ville, :cp, :commentaire, :tel, :date, :duree, :pri)");
    query.bindValue(":id", pat.getIdPatient());
    query.bindValue(":nom", pat.getNom());
    query.bindValue(":prenom", pat.getPrenom());
    query.bindValue("", );
     query.exec();
}

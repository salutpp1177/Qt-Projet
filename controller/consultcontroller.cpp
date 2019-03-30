#include "consultcontroller.h"

consultController::consultController()
{

}

/**
 * @brief Add a patient without defining Id
 * @param pat
 */
void consultController::addPatient(Patient &pat)
{
    return patDao.addPatient(pat);
}

/**
 * @brief Add a patient
 * @param pat
 */
void consultController::addPatient(Patient &pat, int id)
{
    return patDao.addPatient(pat,id);
}

/**
 * @brief Add a consult
 * @param cst
 * @return a flag representing whether modification succeeds or not
 */
bool consultController::addConsult(Consult cst)
{
    return cstDao.addConsult(cst.getPatient(),cst.getRessource());
}


/**
 * @brief Add a consult
 * @param ipat
 * @param ires
 * @return a flag representing whether modification succeeds or not
 */
bool consultController::addConsult(int ipat, int ires)
{
    return cstDao.addConsult(ipat, ires);
}

/**
 * @brief Delete a patient by id
 * @param id
 */
void consultController::deletePatientById(int id)
{
    patDao.deletePatientById(id);
}

/**
 * @brief Delete a consult by id
 * @param id
 */
void consultController::deleteConsultById(int id)
{
    cstDao.deleteConsultById(id);
}

/**
 * @brief Modify a patient
 * @param pat
 */
void consultController:: modifyPatient(Patient pat)
{
    patDao.modifyPatient(pat);
}

/**
 * @brief Modify a consult
 * @param cst
 * @return a flag representing whether modification succeeds or not
 */
bool consultController::modifyConcult(Consult cst)
{
    return cstDao.modifyConsult(cst.getIdConsult(),cst.getPatient(),cst.getRessource());
}

/**
 * @brief Select a patient by id
 * @param id
 * @return a patient
 */
Patient consultController::selectPatientById(int id)
{
    return patDao.selectPatientById(id);
}

/**
 * @brief Select a consult by id
 * @param cst
 * @return a consult
 */
Consult consultController::selectConsultById(int id)
{
    return cstDao.selectConsultById(id);
}


/**
 * @brief Select a consult by id_pat and id_res
 * @param ipat
 * @param ires
 * @return consult id
 */
int consultController::selectConsultById(int ipat, int ires)
{
    return cstDao.selectConsultById(ipat, ires).getIdConsult();
}

/**
 * @brief Select all patients
 * @return a vector of all patients
 */
vector<Patient> consultController::selectAllPatient()
{
    return patDao.selectAllPatient();
}

/**
 * @brief Select all consults
 * @return a vector of all consults
 */
vector<Consult> consultController::selectAllConsult()
{
    return cstDao.selectAllConsult();
}

/**
 * @brief Select the maximum of Id
 * @return max.id
 */
int consultController::getMaxIdPatient()
{
    return patDao.selectMaxId();
}

/**
 * @brief Select the maximum of Id
 * @return max.id
 */
int consultController::getMaxIdConsult()
{
    return cstDao.getMaxId();
}

/**
 * @brief Return all the patients queried by first name and last name
 * @param nom
 * @param prenom
 * @return a vector of all the query results
 */
vector<Patient> consultController::selectPatientByName(QString nom, QString prenom)
{
     return patDao.selectPatientByName(nom,prenom);

}

/**
 * @brief Return all the patients queried by date
 * @param begin date of begin
 * @param end date of end
 * @return a vector of all the query results
 */
vector<Patient> consultController::selectPatientByDate(QString begin, QString end)
{
    return patDao.selectPatientByDate(begin,end);
}

/**
 * @brief Returns all the patients queried by date and name (firstname or lastname)
 * @param begin begin-date
 * @param end ending-date
 * @param name firstname or lastname
 * @param flag to represent firstname or lastname, 0 is lastname
 * @return a vector of all the query results
 */
vector<Patient> consultController::selectPatientByNameAndDate(QString begin, QString end, QString name, int flag)
{
    return patDao.selectPatientByNameAndDate(begin,end,name,flag);
}


/**
 * @brief Returns all the patients queried by name and date
 * @param nom
 * @param prenom
 * @param begin begin-date
 * @param end ending-date
 * @return a vector of all the query results
 */
vector<Patient> consultController::selectPatientByNameAndDate(QString begin, QString end, QString nom, QString prenom)
{
    return patDao.selectPatientByNameAndDate(begin,end,nom,prenom);
}

list<pair<Consult, int>> consultController::sortConsult(vector<Patient> &pat)
{
    bindPatientWithRessource(pat);
    return planification::calc(pat);
}

/**
 * @brief Bind patient with ressource according to the table TConcult
 */
void consultController::bindPatientWithRessource(vector<Patient> &pat)
{
    std::vector<Patient>::iterator it;
    for (it=pat.begin(); it!=pat.end(); ++it) {
        vector<int> vec_res = cstDao.selectRessourceByIdPatient(it->getIdPatient());
        it->setIDResource(vec_res);
    }
}


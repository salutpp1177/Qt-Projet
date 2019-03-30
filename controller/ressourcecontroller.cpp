#include "ressourcecontroller.h"

ressourceController::ressourceController()
{

}

ressourceController::~ressourceController()
{

}

/**
 * @brief Add a ressource
 * @param res
 * @return a flag representing whether modification succeeds or not
 */
bool ressourceController::addRessource(Ressource &res)
{
    return resDao.addRessource(res);
}

/**
 * @brief Add a ressource
 * @param id
 * @param nom
 * @param prenom
 * @param type
 * @return a flag representing whether modification succeeds or not
 */
bool ressourceController::addRessource(int id, QString nom, QString prenom, int type)
{
    return resDao.addRessource(id,nom,prenom,type);
}

/**
 * @brief Add a ressource whose type is infomaticien
 * @param cpt
 * @return a flag representing whether modification succeeds or not
 */
bool ressourceController::addRessourceInfo(Compte &cpt)
{
    bool success = false;
    success = cptDao.addCompte(cpt.getIdRessource(), cpt.getLogin(), cpt.getMotdepasse());
    return success;
}

/**
 * @brief Select all the ressources
 * @return a vector of ressources
 */
vector<Ressource> ressourceController::showAllRessource() const
{
    return resDao.selectAllRessource();
}

/**
 * @brief Select a ressource by nom, prenom and type
 * @param
 * @return a ressource
 */
Ressource ressourceController::selectRessourceByNom(QString nom, QString prenom, int id_type)
{
    return resDao.selectRessourceByNom(nom,prenom,id_type);
}

/**
 * @brief Select a ressource by id
 * @param id
 * @return a ressource
 */
Ressource ressourceController::selectRessourceById(int id)
{
    return resDao.selectRessourceById(id);
}

/**
 * @brief Delete a ressource by id
 * @param id
 * @return a flag representing whether modification succeeds or not
 */
bool ressourceController::deleteRessourceById(int id)
{
    return resDao.deleteRessouceById(id);
}

/**
 * @brief Select the maximum of Id
 * @return max.id
 */
int ressourceController::getMaxIdRessource()
{
    return resDao.getMaxId();
}

/**
 * @brief Select a type by id
 * @return typeparmi
 */
TypeParmi ressourceController::selectTypeParmiById(int id) {
    return typeDao.selectTypeById(id);
}

/**
 * @brief Delete a compte by id_res
 * @param id
 * @return a flag representing whether modification succeeds or not
 */
bool ressourceController::deleteCompteByIdRessource(int id)
{
    return cptDao.deleteCompteByIdRessource(id);
}

/**
 * @brief Modify a ressource
 * @param res
 * @return a flag representing whether modification succeeds or not
 */
bool ressourceController::modifyRessouce(Ressource &res)
{
    return resDao.modifyRessouce(res);
}

/**
 * @brief Select a compte by id
 * @param id
 * @return a compte
 */
Compte ressourceController::selectCompteById(int id)
{
    return cptDao.selectCompteById(id);
}

/**
 * @brief Select a compte by idRessource
 * @param id
 * @return a compte
 */
Compte ressourceController::selectCompteByIdRessource(int id)
{
    return cptDao.selectCompteByIdRessource(id);
}

/**
 * @brief verify login
 * @param login
 * @param mdp
 * @return a compte
 */
Compte ressourceController::verifierLogin(QString login, QString mdp)
{
    return cptDao.selectCompteByLogin(login,mdp);
}

/**
 * @brief Modify a compte
 * @param cpt
 * @return a flag representing whether modification succeeds or not
 */
bool ressourceController::modifyCompte(Compte &cpt)
{
    return cptDao.modifyCompte(cpt);
}


/**
 * @brief Select all the types
 * @return a vector of typeparmi
 */
vector<TypeParmi> ressourceController::selectAllType()
{
    return typeDao.selectAllType();
}

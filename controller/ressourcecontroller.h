#ifndef RESSOURCECONTROLLER_H
#define RESSOURCECONTROLLER_H


#include "dao/ressourcedao.h"
#include "dao/typeparmidao.h"
#include"dao/comptedao.h"

class ressourceController
{
private:
    ressourceDao resDao;
    typeparmiDao typeDao;
    compteDao cptDao;

public:
    ressourceController();
    ~ressourceController();
    bool addRessource(Ressource &res);
    bool addRessource(int id, QString nom, QString prenom, int type);
    bool addRessourceInfo(Compte &cpt);
    vector<Ressource> showAllRessource() const;
    Ressource selectRessourceByNom(QString nom, QString prenom, int id_type);
    Ressource selectRessourceById(int id);
    bool deleteRessourceById(int id);
    int getMaxIdRessource();
    TypeParmi selectTypeParmiById(int id);
    bool deleteCompteByIdRessource(int id);
    bool modifyRessouce(Ressource &res);
    Compte selectCompteById(int id);
    Compte selectCompteByIdRessource(int id);
    Compte verifierLogin(QString login, QString mdp);
    bool modifyCompte(Compte &cpt);
    vector<TypeParmi> selectAllType();
};

#endif // RESSOURCECONTROLLER_H

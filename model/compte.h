#ifndef COMPTE_H
#define COMPTE_H

#include "ressource.h"
#include <QString>

class Compte
{
private:
    int IdCompte;
    Ressource ressource;
    QString login;
    QString motdepasse;

public:
    Compte();
    ~Compte();

    int getIdCompte() const { return IdCompte; }
    Ressource getRessource() const { return ressource; }
    int getIdRessource() const { return ressource.getIdRessource(); }
    QString getLogin() const { return login; }
    QString getMotdepasse() const { return motdepasse; }

    void setIdCompte(int id) { this->IdCompte = id; }
    void setRessource(Ressource &res) { this->ressource = res; }
    void setLogin(QString &str) { this->login = str; }
    void setMotdepasse(QString &str) { this->motdepasse = str; }

};

#endif // COMPTE_H

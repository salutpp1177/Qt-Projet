#ifndef COMPTE_H
#define COMPTE_H

#include "ressource.h"
#include <QString>

class Compte
{
private:
    int IdCompte;
    int IdRessource;
    QString login;
    QString motdepasse;

public:
    Compte();
    ~Compte();

    int getIdCompte() const { return IdCompte; }
    int getIdRessource() const { return IdRessource; }
    QString getLogin() const { return login; }
    QString getMotdepasse() const { return motdepasse; }

    void setIdCompte(int id) { this->IdCompte = id; }
    void setRessource(int res) { this->IdRessource = res; }
    void setLogin(const QString &str) { this->login = str; }
    void setMotdepasse(const QString &str) { this->motdepasse = str; }

};

#endif // COMPTE_H

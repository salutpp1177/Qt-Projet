#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include"typeparmi.h"
class Ressource
{
private:
    int idRessource;
    QString sNom;
    QString sPrenom;
    TypeParmi type;

public:
    Ressource();
    ~Ressource();

    int getIdRessource() const { return this->idRessource; }
    QString getNom() const { return  this->sNom; }
    QString getPrenom() const { return this->sPrenom; }
    TypeParmi getType() const { return this->type; }
    void setPrenom(const QString &str) { this->sPrenom = str; }
    void setNom(const QString &str) { this->sNom = str; }
    void setIdRessource(int id) { this->idRessource = id; }
    void setType(TypeParmi &t) { this->type = t; }
};

#endif // RESSOURCE_H

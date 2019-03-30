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
    int idType;

public:
    Ressource();
    ~Ressource();

    int getIdRessource() const { return this->idRessource; }
    QString getNom() const { return  this->sNom; }
    QString getPrenom() const { return this->sPrenom; }
    int getType() const { return this->idType; }
    void setPrenom(const QString &str) { this->sPrenom = str; }
    void setNom(const QString &str) { this->sNom = str; }
    void setIdRessource(int id) { this->idRessource = id; }
    void setType(int id) { this->idType = id; }
};

#endif // RESSOURCE_H

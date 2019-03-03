#ifndef SOIGNEUR_H
#define SOIGNEUR_H

#include <iostream>
#include <QString>
#include <QDateTime>
#include "typeparmi.h"


class soigneur
{
private:
    int idSoigneur;
    QString sNom;
    QString sPrenom;
    TypeParmi type;

public:
    soigneur();
    ~soigneur();

    int getIdSoigneur() const { return this->idSoigneur; }
    QString getNom() const { return  this->sNom; }
    QString getPrenom() const { return this->sPrenom; }
    TypeParmi getType() const { return this->type; }
    void setPrenom(const QString &str) { this->sPrenom = str; }
    void setNom(const QString &str) { this->sNom = str; }
    void setIdSoigner(int id) { this->idSoigneur = id; }
    void setType(TypeParmi &t) { this->type = t; }
};

#endif // SOIGNEUR_H

#ifndef CONSULT_H
#define CONSULT_H

#include<QString>
#include "patient.h"
#include "ressource.h"

class Consult
{
private:
    int IdConsult;
    Patient patient;
    Ressource ressource;

public:
    Consult();
    ~Consult();

    int getIdConsult() const { return IdConsult; }
    Patient getPatient() const { return patient; }
    int getIdPatient() const { return patient.getIdPatient(); }
    Ressource getRessource() const { return ressource; }
    int getIdRessource() const {return ressource.getIdRessource(); }

    void setIdConsult(int id) { IdConsult = id; }
    void setPatient(Patient &pat) { patient = pat; }
    void setRessource(Ressource &res ) { ressource = res; }


};

#endif // CONSULT_H

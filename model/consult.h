#ifndef CONSULT_H
#define CONSULT_H

#include<QString>
#include "patient.h"
#include "ressource.h"

class Consult
{
private:
    int IdConsult;
    int IdPatient;
    int IdRessource;

public:
    Consult();
    ~Consult();

    int getIdConsult() const { return IdConsult; }
    int getPatient() const { return IdPatient; }
    int getRessource() const { return IdRessource; }

    void setIdConsult(int id) { IdConsult = id; }
    void setPatient(int id) { IdPatient = id; }
    void setRessource(int id) { IdRessource = id; }


};

#endif // CONSULT_H

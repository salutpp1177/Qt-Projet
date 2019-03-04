#ifndef PATIENTDAO_H
#define PATIENTDAO_H

#include "model/patient.h"
#include <QString>
#include <QSqlQuery>

class patientDao
{
public:
    patientDao();
    ~patientDao();

    void addPatient(Patient &pat);
    Patient selectPatientById(int id) const;
    Patient selectPatientByName(QString nom, QString prenom);
    void modifyPatient(Patient pat);
    void deletePatientById(int id);
};

#endif // PATIENTDAO_H

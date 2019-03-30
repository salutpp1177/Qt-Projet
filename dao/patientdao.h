#ifndef PATIENTDAO_H
#define PATIENTDAO_H

#include "model/patient.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <vector>
#include <QSqlError>
#include "consultdao.h"
#include "connectdatabase.h"

class patientDao
{
private:
    QSqlDatabase db;
public:
    patientDao();
    ~patientDao();

    void addPatient(Patient &pat);
    void addPatient(Patient &pat, int id);
    Patient selectPatientById(int id) const;
    Patient getPatientByQuery(QSqlQuery query);
    bool modifyPatient(Patient pat);
    bool deletePatientById(int id);
    bool deletePatientByName(QString nom, QString prenom);
    vector<Patient> selectAllPatient();
    int selectMaxId();
    vector<Patient> selectPatientByName(QString nom, QString prenom);
    vector<Patient> selectPatientByDate(QString begin, QString end);
    vector<Patient> selectPatientByNameAndDate(QString begin, QString end, QString name, int flag);
    vector<Patient> selectPatientByNameAndDate(QString begin, QString end, QString nom, QString prenom);

};

#endif // PATIENTDAO_H

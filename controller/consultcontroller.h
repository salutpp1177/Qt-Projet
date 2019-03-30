#ifndef CONSULTCONTROLLER_H
#define CONSULTCONTROLLER_H
#include <dao/patientdao.h>
#include <dao/ressourcedao.h>
#include <dao/consultdao.h>
#include <model/planification.h>
#include <QString>

class consultController
{
private:
    patientDao patDao;
    ressourceDao resDao;
    consultDao cstDao;

public:
    consultController();
    void addPatient(Patient &pat);
    void addPatient(Patient &pat, int id);
    bool addConsult(Consult cst);
    bool addConsult(int ipat, int ires);
    void deletePatientById(int id);
    void deleteConsultById(int id);
    void modifyPatient(Patient pat);
    bool modifyConcult(Consult cst);
    Patient selectPatientById(int id);
    Consult selectConsultById(int id);
    int selectConsultById(int ipat, int ires);
    vector<Patient> selectAllPatient();
    vector<Consult> selectAllConsult();
    int getMaxIdPatient();
    int getMaxIdConsult();
    vector<Patient> selectPatientByName(QString nom, QString prenom);
    vector<Patient> selectPatientByDate(QString begin, QString end);
    vector<Patient> selectPatientByNameAndDate(QString begin, QString end, QString name, int flag);
    vector<Patient> selectPatientByNameAndDate(QString begin, QString end, QString nom, QString prenom);
    list<pair<Consult, int>> sortConsult(vector<Patient> &pat);
    void bindPatientWithRessource(vector<Patient> &pat);

};

#endif // CONSULTCONTROLLER_H

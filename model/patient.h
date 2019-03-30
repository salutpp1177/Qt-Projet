//
//  Patient.hpp
//  projectV1
//
//  Created by jiangyaqi on 2019/2/5.
//  Copyright © 2019 Yaqi. All rights reserved.
//

#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <QString>
#include <algorithm>
#include <QDate>

using namespace std;

class Patient {
    private :
        int idPateint;
        QString sNom;
        QString sPrenom;
        QString sAdress;
        QString sVille;
        QString sComments;
        int telephone;
        int codePostale;
        QDate dDate;
        int iDuree;
        int iPriorite;
        vector<int> vIDResource;

    public :
        Patient();
        ~Patient();

    int getIdPatient() const {return idPateint; }
    QString getNom() const { return sNom; }
    QString getPrenom() const { return sPrenom; }
    QString getAdress() const { return sAdress; }
    QString getVille() const { return sVille; }
    QString getComments() const { return sComments; }
    int getTelephone() const { return telephone; }
    int getCodePostale() const { return codePostale; }
    QDate getDate() const {return dDate;}
    int getDuree() const { return iDuree; }
    int getPriorite() const { return iPriorite; }
    void setIdPatient(int id);
    void setNom(QString str) ;
    void setPrenom(QString str);
    void setAdress(QString str);
    void setVille(QString str);
    void setComments(QString str);
    void setTelephone(int i);
    void setCodePostale(int codePost);
    void setDate(QDate d);
    void setDuree(int i);
    void setPriorite(int i);
    vector<int>& getIDResource() { return vIDResource; }
    void setIDResource(const vector<int> v_id);
    void addIDResource(int id);
    void triIDResource();




};
#endif /* patient_hpp */

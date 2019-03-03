//
//  Patient.hpp
//  projectV1
//
//  Created by jiangyaqi on 2019/2/5.
//  Copyright © 2019 Yaqi. All rights reserved.
//

#ifndef PATIENT_H
#define PATEINT_H

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <QString>
#include <algorithm>
using namespace std;
class Patient {
    private :
        int idPateint;
        QString sNom;
        QString sPrenom;
        QString sAdress;
        QString sVille;
        QString sComments;
        int iNumTelephone;
        int iCodePostale;
        int iDuree;
        int iPriorite;
        vector<int> vIDResource;

    public :
        Patient();
//        Patient(string nom, string prenom, string add, string ville, string comment, int tel, int post, int d, int prior);
        ~Patient();


    QString getNom() const { return sNom; }
    QString getPrenom() const { return sPrenom; }
    QString getAdress() const { return sAdress; }
    QString getVille() const { return sVille; }
    QString getComments() const { return sComments; }
    int getNumTelephone() const { return iNumTelephone; }
    int getCodePostale() const { return iCodePostale; }
    int getDuree() const { return iDuree; }
    int getPriorite() const { return iPriorite; }
    void setNom(QString &str) ;
    void setPrenom(QString &str);
    void setAdress(QString &str);
    void setVille(QString &str);
    void setComments(QString &str);
    void setNumTelephone(int i);
    void setCodePostale(int i);
    void setDuree(int i);
    void setPriorite(int i);
    vector<int>& getIDResource() { return vIDResource; }
    void addIDResource(int id);
    void triIDResource();




};
#endif /* Patient_hpp */

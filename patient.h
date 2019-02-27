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
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Patient {
    private :
        string sNom;
        string sPrenom;
        string sAdress;
        string sVille;
        string sComments;
        int iNumTelephone;
        int iCodePostale;
        int iDuree;
        int iPriorite;
        vector<int> vIDResource;

    public :
        Patient();
        Patient(string nom, string prenom, string add, string ville, string comment, int tel, int post, int d, int prior);
        ~Patient();

    const string getNom() { return sNom; };
    const string getPrenom() { return sPrenom; };
    const string getAdress() { return sAdress; };
    const string getVille() { return sVille;};
    const string getComments() { return sComments; };
    const int getNumTelephone() { return iNumTelephone; };
    const int getCodePostale() { return iCodePostale; };
    const int getDuree() { return iDuree; };
    const int getPriorite() { return iPriorite; };
    void setNom(string str) ;
    void setPrenom(string str);
    void setAdress(string str);
    void setVille(string str);
    void setComments(string str);
    void setNumTelephone(int i);
    void setCodePostale(int i);
    void setDuree(int i);
    void setPriorite(int i);
    vector<int>& getIDResource() { return vIDResource; };
    void addIDResource(int id);
    void triIDResource();




};
#endif /* Patient_hpp */

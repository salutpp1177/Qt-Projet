//
//  Patient.cpp
//  projectV1
//
//  Created by jiangyaqi on 2019/2/5.
//  Copyright © 2019 Yaqi. All rights reserved.
//

#include "Patient.h"

Patient::Patient() {
    this->sNom = "nom";
    this->sPrenom = "prenom";
    this->sVille = "ville";
    this->sAdress = "adress";
    this->sComments = "comment";
    this->iDuree = 0;
    this->iCodePostale = 0;
    this->iNumTelephone = 0;
    this->iPriorite = 0;
}

//Patient::Patient(string nom, string prenom, string add, string ville, string comment, int tel, int post, int d, int prior) {
//    this->sNom = nom;
//    this->sPrenom = prenom;
//    this->sVille = ville;
//    this->sAdress = add;
//    this->sComments = comment;
//    this->iDuree = d;
//    this->iCodePostale = post;
//    this->iNumTelephone = tel;
//    this->iPriorite = prior;
//}

Patient::~Patient() {

}

void Patient::addIDResource(int id) {
    this->vIDResource.push_back(id);
}

void Patient::triIDResource() {
    sort(this->getIDResource().begin(), this->getIDResource().end());
}



void Patient::setNom(QString &str) {
    this->sNom = str;
}

void Patient::setPrenom(QString &str) {
    this->sPrenom = str;
}

void Patient::setAdress(QString &str) {
    this->sAdress = str;
}

void Patient::setVille(QString &str) {
    this->sVille = str;
}

void Patient::setComments(QString &str) {
    this->sComments = str;
}

void Patient::setNumTelephone(int i) {
    this->iNumTelephone = i;
}

void Patient::setCodePostale(int i) {
    this->iCodePostale = i;
}

void Patient::setDuree(int i) {
    this->iDuree = i;
}

void Patient::setPriorite(int i) {
    this->iPriorite = i;
}


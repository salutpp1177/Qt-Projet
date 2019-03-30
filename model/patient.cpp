//
//  Patient.cpp
//  projectV1
//
//  Created by jiangyaqi on 2019/2/5.
//  Copyright © 2019 Yaqi. All rights reserved.
//

#include "patient.h"

Patient::Patient() {
    this->idPateint = 0;
    this->sNom = "nom";
    this->sPrenom = "prenom";
    this->sVille = "ville";
    this->sAdress = "adress";
    this->sComments = "comment";
    this->dDate =  QDate::currentDate();
    this->iDuree = 0;
    this->codePostale = 37000;
    this->telephone = 00000000;
    this->iPriorite = 0;
}

Patient::~Patient()
{

}

void Patient::setIdPatient(int id)
{
    this->idPateint = id;
}

void Patient::setNom(QString str)
{
    this->sNom = str;
}

void Patient::setPrenom(QString str)
{
    this->sPrenom = str;
}

void Patient::setAdress(QString str)
{
    this->sAdress = str;
}

void Patient::setVille(QString str)
{
    this->sVille = str;
}

void Patient::setComments(QString str)
{
    this->sComments = str;
}

void Patient::setTelephone(int telephone)
{
    this->telephone = telephone;
}

void Patient::setCodePostale(int codePost)
{
    this->codePostale = codePost;
}

void Patient::setDate(QDate d)
{
    this->dDate = d;
}

void Patient::setDuree(int i)
{
    this->iDuree = i;
}

void Patient::setPriorite(int i)
{
    this->iPriorite = i;
}

void Patient::setIDResource(const vector<int> v_id)
{
    vIDResource=v_id;
}

void Patient::triIDResource()
{
    sort(this->getIDResource().begin(), this->getIDResource().end());
}

void Patient::addIDResource(int id)
{

    vIDResource.push_back(id);
}


#ifndef PLANIFICATION_H
#define PLANIFICATION_H
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <list>
#include "model/patient.h"
#include "model/consult.h"

using namespace std;
class planification
{
public:
    planification();
    //按优先级参数排序
    static bool cmp(Patient A, Patient B);
    static list<pair<Consult, int>>  calc(vector<Patient> &pa);
};

#endif // PLANIFICATION_H




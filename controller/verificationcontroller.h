#ifndef VERIFICATIONCONTROLLER_H
#define VERIFICATIONCONTROLLER_H

#include <string.h>
#include <QString>
using namespace std;
class verificationController
{
private:
    string username;
    string passwd;
public:
    verificationController();
    bool verifierLogin(QString user, QString pwd);
};

#endif // VERIFICATIONCONTROLLER_H

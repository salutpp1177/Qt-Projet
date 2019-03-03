#include "verificationcontroller.h"

verificationController::verificationController() : username(""), passwd ("")
{
}

bool verificationController::verifierLogin(QString user, QString pwd)
{
    if(user.toStdString() == "username" && pwd.toStdString() == "passwd" ) {
        return true;
    }
    else {
        return  false;
    }
}

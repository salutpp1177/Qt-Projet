#include <QApplication>

#include "mainwindow.h"
#include "identification.h"
#include "formapropos.h"
#include "dialogajouterpatient.h"
#include "dialogajoutersoigneur.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Identification i;
//    FormAPropos i;
    MainWindow i;
    i.show();

    return a.exec();
}

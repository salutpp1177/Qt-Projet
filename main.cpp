#include <QApplication>
#include <QDialog>
#include "mainwindow.h"
#include "identification.h"
#include "formapropos.h"
#include "dialogajouterpatient.h"
#include "dialogajoutersoigneur.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Identification i;
    MainWindow w;
    i.show();

    if(i.exec() == QDialog::Accepted) {
        w.show();

    }

    return a.exec();
}

#include <QApplication>
#include <QDialog>
#include <QFile>
#include "c_init_bd.h"
#include "mainwindow.h"
#include "identification.h"
#include "formapropos.h"
#include "dialogajouterpatient.h"
#include "dialogajoutersoigneur.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //connecion de base de donnée
    if(QFile::exists("base_tmp.sqli")) {
        C_INIT_BD::Creation_BD();
    }



    Identification i;
    MainWindow w;
    i.show();

    if(i.exec() == QDialog::Accepted) {
        w.show();

    }



    return a.exec();
}

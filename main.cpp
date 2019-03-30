#include <QApplication>
#include <QDialog>
#include <QFile>
#include <QDebug>
#include "c_init_bd.h"
#include "mainwindow.h"
#include "identification.h"
#include "formapropos.h"
#include "dialogajouterpatient.h"
#include "dialogajoutersoigneur.h"
#include <QDir>
#include <QDate>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Question 1
    set<int> qSet1;
    qSet1.insert(89);
    qSet1.insert(85);
    qSet1.insert(74);
    qSet1.insert(23);
    qSet1.insert(86);
    qSet1.insert(95);

    set<int> qSet2;
    qSet2.insert(0);
    qSet2.insert(6);
    qSet2.insert(12);
    qSet2.insert(18);
    qSet2.insert(22);

    set<int> qSet3;
    qSet3.insert(qSet1.begin(), qSet1.end());
    qSet3.insert(qSet2.begin(), qSet2.end());

    set<int>::iterator ite;
    QString result = "[";
    for (int e : qSet3) {
        result += " " + QString::number(e) + " ";
    }
    result += "]";
    QMessageBox::information(0, "Résultat Question 1", "Set fusionné = " + result);

    /* find the path where the database doc is saved*/
    qDebug() << QDir::currentPath();

    /* create a data base*/
    if(!QFile::exists("base_tmp.sqli")) {
        C_INIT_BD::Creation_BD();
    }

    /* connection to data base*/
    connectDataBase *conn = connectDataBase::getConnection();

    /* show window for manipulation*/
    Identification i;
    MainWindow w;
    i.show();
    if(i.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    }

    /* disconnection from data base */
    conn->disconnectDB();
    return 0;
}

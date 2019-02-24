#include "dialogajouterpatient.h"
#include "ui_dialogajouterpatient.h"

DialogAjouterPatient::DialogAjouterPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterPatient)
{
    ui->setupUi(this);
}

DialogAjouterPatient::~DialogAjouterPatient()
{
    delete ui;
}

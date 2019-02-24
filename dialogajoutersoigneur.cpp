#include "dialogajoutersoigneur.h"
#include "ui_dialogajoutersoigneur.h"

DialogAjouterSoigneur::DialogAjouterSoigneur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterSoigneur)
{
    ui->setupUi(this);
}

DialogAjouterSoigneur::~DialogAjouterSoigneur()
{
    delete ui;
}

#include "dialogpsychologue.h"
#include "ui_dialogpsychologue.h"


DialogPsychologue::DialogPsychologue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPsychologue)
{
    ui->setupUi(this);
}

DialogPsychologue::~DialogPsychologue()
{
    delete ui;
}


//Q.3
void DialogPsychologue::on_buttonBox_accepted()
{
    if(on_lineEdit_editingFinished()&& on_lineEdit_2_editingFinished()) {


            Ressource res;
            res.setNom(ui->lineEdit->text());
            res.setPrenom(ui->lineEdit_2->text());
            res.setType(6);
            res_Ctrl.addRessource(res);

    }
}

bool DialogPsychologue::on_lineEdit_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit->text().isEmpty()){
        ui->lineEdit->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->lineEdit->setStyleSheet("background-color: white;");
    }
    return finish;

}

bool DialogPsychologue::on_lineEdit_2_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_2->text().isEmpty()){
        ui->lineEdit_2->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->lineEdit_2->setStyleSheet("background-color: white;");
    }
    return finish;
}

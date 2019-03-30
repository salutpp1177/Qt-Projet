#include "dialogajoutersoigneur.h"
#include "ui_dialogajoutersoigneur.h"
#include <QStringList>

DialogAjouterSoigneur::DialogAjouterSoigneur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterSoigneur)
{
    ui->setupUi(this);
}

DialogAjouterSoigneur::
~DialogAjouterSoigneur()
{
    delete ui;
}

/**
 * @brief action after clicking button Ok
 * @details add a new ressource and update the list pf ressource
 */
void DialogAjouterSoigneur::on_Ajouter_accepted()
{
    if(on_lineEdit_login_editingFinished() && on_lineEdit_login_editingFinished()) {
        // ajouter un infomacitien
        Compte cpt;
        cpt.setLogin(ui->lineEdit_login->text());
        cpt.setMotdepasse(ui->lineEdit_mdp->text());
        if(on_lineEdit_nom_editingFinished() &&on_lineEdit_prenom_editingFinished()) {
            Ressource res;
            int id_type = ui->comboBox->currentIndex()+1;
            res.setIdRessource(res_ctrl.getMaxIdRessource()+1);
            res.setType(id_type);
            res.setNom(ui->lineEdit_nom->text());
            res.setPrenom(ui->lineEdit_prenom->text());
            res_ctrl.addRessource(res.getIdRessource(),res.getNom(),res.getPrenom(),res.getType());
            cpt.setRessource(res.getIdRessource());
            res_ctrl.addRessourceInfo(cpt);
        }
    } else {
        if(on_lineEdit_nom_editingFinished() &&on_lineEdit_prenom_editingFinished()) {
            Ressource res;
            int id_type = ui->comboBox->currentIndex()+1;
            res.setType(id_type);
            res.setNom(ui->lineEdit_nom->text());
            res.setPrenom(ui->lineEdit_prenom->text());
            res_ctrl.addRessource(res);
        }

    }

}

/**
 * @brief jury whether nom editer is filled
 */
bool DialogAjouterSoigneur::on_lineEdit_nom_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_nom->text().isEmpty()){
        ui->lineEdit_nom->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->lineEdit_nom->setStyleSheet("background-color: white;");
    }
    return finish;
}


/**
 * @brief jury whether prenom editer is filled
 */
bool DialogAjouterSoigneur::on_lineEdit_prenom_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_prenom->text().isEmpty()){
        ui->lineEdit_prenom->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->lineEdit_prenom->setStyleSheet("background-color: white;");
    }
    return finish;
}


/**
 * @brief jury whether login editer is filled
 */
bool DialogAjouterSoigneur::on_lineEdit_login_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_login->text().isEmpty()){
        ui->lineEdit_login->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->lineEdit_login->setStyleSheet("background-color: white;");
    }
    return finish;
}


/**
 * @brief jury whether password editer is filled
 */
bool DialogAjouterSoigneur::on_lineEdit_mdp_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_mdp->text().isEmpty()){
        ui->lineEdit_mdp->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->lineEdit_mdp->setStyleSheet("background-color: white;");
    }
    return finish;

}






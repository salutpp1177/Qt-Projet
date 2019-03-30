#include "dialogmodifierressource.h"
#include "ui_dialogmodifierressource.h"

DialogModifierRessource::DialogModifierRessource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifierRessource)
{
    ui->setupUi(this);
}

DialogModifierRessource::~DialogModifierRessource()
{
    delete ui;
}

/**
 * @brief set id ressource
 */
void DialogModifierRessource::setId_Res(int id)
{
    id_res = id;
}

/**
 * @brief set id ressource
 * @return id_res
 */
int DialogModifierRessource::getId_Res() {
    return id_res;
}

/**
 * @brief action after clicking the button Ok
 * @details modify infomation of a ressource sucessfully and update the list pf ressource
 */
void DialogModifierRessource::on_buttonBox_accepted()
{
    ressourceController res_ctrl;
    Ressource res;
    Compte cpt;
    int id_type = ui->comboBox->currentIndex()+1;
    if((!ui->lineEdit_login->text().isEmpty())&&(!ui->lineEdit_mdp->text().isEmpty())) {
        cpt.setRessource(this->getId_Res());
        int id_cpt = res_ctrl.selectCompteByIdRessource(this->getId_Res()).getIdCompte();
        cpt.setIdCompte(id_cpt);
        cpt.setLogin(ui->lineEdit_login->text());
        cpt.setMotdepasse(ui->lineEdit_mdp->text());
        if((!ui->lineEdit_nom->text().isEmpty())&&(!ui->lineEdit_prenom->text().isEmpty())) {
            res.setIdRessource(this->getId_Res());
            res.setNom(ui->lineEdit_nom->text());
            res.setPrenom(ui->lineEdit_prenom->text());
            res.setType(id_type);
            res_ctrl.modifyRessouce(res);
        }
        res_ctrl.modifyCompte(cpt);
    } else {
        res.setIdRessource(this->getId_Res());
        res.setNom(ui->lineEdit_nom->text());
        res.setPrenom(ui->lineEdit_prenom->text());
        res.setType(id_type);
        res_ctrl.modifyRessouce(res);
    }
}

#include "identification.h"
#include "ui_identification.h"

Identification::Identification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Identification)
{
    ui->setupUi(this);
}

Identification::~Identification()
{
    delete ui;
}

void Identification::on_loginBtn_clicked()
{
    verificationController verifierCtl;
    if(verifierCtl.verifierLogin(ui->username->text(), ui->passwd->text())) {
        QMessageBox msg1(QMessageBox::Information,windowTitle(),"login succeed!", QMessageBox::Ok,this);
        if(msg1.exec() == QMessageBox::Ok) {
            accept();
        }
    } else {
        ui->username->clear();
        ui->passwd->clear();
        QMessageBox msg2(QMessageBox::Information,windowTitle(),"login failed",QMessageBox::Ok,this);
        msg2.exec();
    }

}


void Identification::on_annulerBtn_clicked()
{
    close();
}

void Identification::on_passwd_textEdited(const QString &arg1)
{
    if(arg1.length() < 6) {
        this->ui->label_4->setText("La longueur est supérieure à 6!");
    }
}

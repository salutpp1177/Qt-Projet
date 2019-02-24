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

void Identification::on_pushButton_clicked()
{
    if(this->ui->lineEdit->text() == "user" && this->ui->lineEdit_2->text() == "pwd") {
        QMessageBox msg1(QMessageBox::Information,windowTitle(),"login succeed!", QMessageBox::Ok,this);
        if(msg1.exec() == QMessageBox::Ok) {
            this->w.show();
        }
    } else {
        QMessageBox msg2(QMessageBox::Information,windowTitle(),"login failed",QMessageBox::Ok,this);
        msg2.exec();
    }

}


void Identification::on_pushButton_2_clicked()
{
    close();
}

void Identification::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1.length() < 4) {
        this->ui->label_4->setText("La longueur est supérieure à 4!");
    } else {
        this->ui->label_4->setText("Veuillez saisir votre mot de passe!");
    }
}


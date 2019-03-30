#include "identification.h"
#include "ui_identification.h"

Identification::Identification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Identification)
{
    ui->setupUi(this);

    //Question 2
    ui->username->setText("val");
    ui->passwd->setEchoMode(QLineEdit::Password);
}

Identification::~Identification()
{
    delete ui;
}

/**
 * @brief action after clicking the button Login
 * @details verify login infomation
 */
void Identification::on_loginBtn_clicked()
{
    if(res_Ctrl.verifierLogin(ui->username->text(), ui->passwd->text()).getLogin().isEmpty()) {
         ui->username->clear();
         ui->passwd->clear();
         QMessageBox msg2(QMessageBox::Information,windowTitle(),"login failed",QMessageBox::Ok,this);
         msg2.exec();
    } else {
         QMessageBox msg1(QMessageBox::Information,windowTitle(),"login succeed!", QMessageBox::Ok,this);
         if(msg1.exec() == QMessageBox::Ok) {
            accept();
         }
    }
}

/**
 * @brief action after clicking the button Anunler
 * @details quit this system
 */
void Identification::on_annulerBtn_clicked()
{
    close();
}

/**
 * @brief notify the password form
 */
void Identification::on_passwd_textEdited(const QString &arg1)
{
    if(arg1.length() < 6) {
        this->ui->label_4->setText("La longueur est supérieure à 4!");
    }
}

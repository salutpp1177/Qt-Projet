#include "formapropos.h"
#include "ui_formapropos.h"

FormAPropos::FormAPropos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAPropos)
{
    ui->setupUi(this);

}

FormAPropos::~FormAPropos()
{
    delete ui;
}

void FormAPropos::on_pushButton_clicked()
{
    close();
}

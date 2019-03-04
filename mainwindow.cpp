#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Vous avez connecté!");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}



void MainWindow::on_actionPatient_triggered()
{
    DialogAjouterPatient dap;
    if(dap.exec() == QDialog::Accepted) {
        model->select();
        ui->statusBar->showMessage("Vous avez ajouté un patient.");
    }
}



//void MainWindow::on_actionPersonnel_de_soins_triggered()
//{
//    this->das.show();
//}

//void MainWindow::on_actionA_propos_triggered()
//{
//    this->fap.show();
//}

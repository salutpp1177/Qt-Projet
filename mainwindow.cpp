#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->menuBar->addAction("Quitter");
    this->ui->menuBar->addMenu("Ajouter");
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
    this->dap.show();
}



void MainWindow::on_actionPersonnel_de_soins_triggered()
{
    this->das.show();
}

void MainWindow::on_actionA_propos_triggered()
{
    this->fap.show();
}

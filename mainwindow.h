#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialogajouterpatient.h>
#include <dialogajoutersoigneur.h>
#include <formapropos.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuitter_triggered();

    void on_actionPatient_triggered();

    void on_actionPersonnel_de_soins_triggered();

    void on_actionA_propos_triggered();

private:
    Ui::MainWindow *ui;
    DialogAjouterPatient dap;
    DialogAjouterSoigneur das;
    FormAPropos fap;
};

#endif // MAINWINDOW_H

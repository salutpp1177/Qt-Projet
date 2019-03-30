#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogajouterpatient.h"
#include "dialogajoutersoigneur.h"
#include "dialogmodifierressource.h"
#include "formapropos.h"
#include <QStringList>
#include <QStandardItemModel>
#include <QList>
#include "controller/ressourcecontroller.h"
#include "controller/consultcontroller.h"
#include "dialogmodifypatient.h"
#include <vector>
#include <QPushButton>
#include <QMessageBox>
#include<QFileDialog>
#include "dialogpsychologue.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init_treeView();
    void show_liste_ressource();
    void update_liste_ressource();
    void init_patient_list(vector<Patient> &vec_pat);

private slots:
    void on_actionQuitter_triggered();

    void on_actionPersonnel_de_soins_triggered();

    void on_actionPatient_triggered();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

    void on_rechercher_clicked();

    bool on_lineEdit_id_editingFinished();

    bool on_lineEdit_nom_editingFinished();

    bool on_lineEdit_prenom_editingFinished();

    void on_pushButton_plan_clicked();

    void on_pushButton_2_clicked();

    void on_actionPsychologue_triggered();


    void on_actionModifier_Patient_triggered();

private:
    Ui::MainWindow *ui;
    DialogAjouterSoigneur add_res;
    DialogAjouterPatient add_pat;
    DialogPsychologue add_psy;
    DialogModifierRessource mdf_res;
    DialogModifyPatient mdf_pat;
    QStandardItemModel *model;
    ressourceController res_Ctrl;
    consultController cst_Ctrl;
    QStandardItemModel *model_plan;
};

#endif // MAINWINDOW_H

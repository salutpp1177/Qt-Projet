#ifndef DIALOGAJOUTERSOIGNEUR_H
#define DIALOGAJOUTERSOIGNEUR_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QStringList>
#include <QStandardItemModel>
#include <QList>
#include <controller/ressourcecontroller.h>

namespace Ui {
class DialogAjouterSoigneur;
}

class DialogAjouterSoigneur : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterSoigneur(QWidget *parent = nullptr);
    ~DialogAjouterSoigneur();

//    void addRessource();

private slots:
    void on_Ajouter_accepted();

    bool on_lineEdit_nom_editingFinished();

    bool on_lineEdit_prenom_editingFinished();

    bool on_lineEdit_login_editingFinished();

    bool on_lineEdit_mdp_editingFinished();


private:
    Ui::DialogAjouterSoigneur *ui;
    ressourceController res_ctrl;

};

#endif // DIALOGAJOUTERSOIGNEUR_H

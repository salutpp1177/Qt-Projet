#ifndef DIALOGAJOUTERPATIENT_H
#define DIALOGAJOUTERPATIENT_H

#include <QDialog>
#include <controller/consultcontroller.h>
#include <QSqlQueryModel>
#include <vector>
#include "controller/ressourcecontroller.h"
#include <QStandardItemModel>


namespace Ui {
class DialogAjouterPatient;
}

class DialogAjouterPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterPatient(QWidget *parent = nullptr);
    ~DialogAjouterPatient();
    void init_ressource_list();
    void update_ressource_list();
    void init_ressource_reserved_list();
    void update_ressource_reserved_list();
    QString getCommAndDri();
    Patient* getPat() {return this->pat;}


private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    bool on_nomEdit_editingFinished();

    bool on_prenomEdit_editingFinished();

    bool on_spinBox_editingFinished();

    bool on_dureeEdit_editingFinished();

    bool on_cpEdit_editingFinished();

    bool on_villeEdit_editingFinished();

    bool on_adresseEdit_textChanged();

//    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_buttonBox_accepted();

    bool all_editors_full();

    void on_buttonBox_rejected();

private:
    Ui::DialogAjouterPatient *ui;
    ressourceController res_Ctrl;
    consultController cst_Ctrl;
    QStandardItemModel *model;
    QStandardItemModel *model_res;
    Patient *pat;
    QString comm_and_dri;
};

#endif // DIALOGAJOUTERPATIENT_H

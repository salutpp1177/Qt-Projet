#ifndef DIALOGMODIFYPATIENT_H
#define DIALOGMODIFYPATIENT_H

#include <QDialog>
#include "controller/consultcontroller.h"
#include "controller/ressourcecontroller.h"
#include <QSqlQueryModel>
#include <vector>
#include <QStandardItemModel>
#include <QMessageBox>

namespace Ui {
class DialogModifyPatient;
}

class DialogModifyPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifyPatient(QWidget *parent = nullptr);
    ~DialogModifyPatient();
    Patient* getPatient();
    void init_ressource_list();
    void update_ressource_list();
    void init_ressource_reserved_list();
    void update_ressource_reserved_list();
    QString getCommAndDri();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

    bool on_nomEdit_editingFinished();

    bool on_prenomEdit_editingFinished();

    bool on_spinBox_editingFinished();

    bool on_dureeEdit_editingFinished();

    bool on_cpEdit_editingFinished();

    bool on_villeEdit_editingFinished();

    bool on_adresseEdit_textChanged();

    void on_pushButton_del_clicked();

    void on_buttonBox_accepted();

    bool all_editors_full();

    void on_buttonBox_rejected();

private:
    ressourceController res_Ctrl;
    consultController cst_Ctrl;
    QStandardItemModel *model;
    QStandardItemModel *model_res;
    Ui::DialogModifyPatient *ui;
    Patient *pat;
    QString comm_and_dri;

};

#endif // DIALOGMODIFYPATIENT_H

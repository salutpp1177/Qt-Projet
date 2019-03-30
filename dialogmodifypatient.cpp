#include "dialogmodifypatient.h"
#include "ui_dialogmodifypatient.h"

DialogModifyPatient::DialogModifyPatient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifyPatient)
{
    ui->setupUi(this);
    ui->dateEdit->setDateRange(QDate::currentDate(),QDate::currentDate().addDays(90));
    ui->dureeEdit->setValidator(new QIntValidator);
    ui->cpEdit->setValidator(new QIntValidator);
    ui->telEdit->setValidator(new QIntValidator);
    ui->spinBox->setValue(1);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
    model = new QStandardItemModel(this);
    model_res = new QStandardItemModel(this);
    pat = new Patient();
    init_ressource_list();
}

DialogModifyPatient::~DialogModifyPatient()
{
    delete ui;
}

Patient* DialogModifyPatient::getPatient()
{
    return this->pat;
}



/**
 * @brief Initialize the list of ressource for preparation
 */
void DialogModifyPatient::init_ressource_list()
{
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal, "IdRessource");
    model->setHeaderData(1,Qt::Horizontal, "Nom");
    model->setHeaderData(2,Qt::Horizontal, "Prénom");
    model->setHeaderData(3,Qt::Horizontal, "Type Parmi");
    vector<Ressource> vec_res = res_Ctrl.showAllRessource();
    std::vector<Ressource>::iterator it;
    vector<TypeParmi> vec_type = res_Ctrl.selectAllType();
    for(it=vec_res.begin(); it!=vec_res.end(); ++it) {
        QList<QStandardItem*> list;
        list.append(new QStandardItem(QString::number(it->getIdRessource())));
        list.append(new QStandardItem(it->getNom()));
        list.append(new QStandardItem(it->getPrenom()));
        unsigned long id_t = it->getType();
        list.append(new QStandardItem(vec_type.at(id_t-1).getTypeName()));
        model->appendRow(list);
    }
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(model);

}

/**
 * @brief Update the list of ressource
 */
void DialogModifyPatient::update_ressource_list()
{
    model->clear();
    init_ressource_list();
}

/**
 * @brief Initialize the list of ressource reserved for preparation
 */
void DialogModifyPatient::init_ressource_reserved_list()
{
    std::vector<int>::iterator it;
    for(it=pat->getIDResource().begin(); it!=pat->getIDResource().end(); ++it) {
        model_res->appendRow(new QStandardItem(QString::number(*it)));
    }
    ui->listView->setModel(model_res);
}

/**
 * @brief Update the list of ressource for preparation
 */
void DialogModifyPatient::update_ressource_reserved_list()
{
    model_res->clear();
    init_ressource_reserved_list();
}

/**
 * @brief action after double-click of IdRessource in tableView
 */
void DialogModifyPatient::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(index.column() != 0) {
        //Qmessage
        QMessageBox msgBox;
        msgBox.setText("Veillez appuyer sur son Id_Ressource! ");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    } else {
        int id_res = index.data(0).toInt();
//        qDebug() <<id_res;
        QMessageBox msgBox;
        msgBox.setText("Vouz voulez ajouter la ressource?");
        msgBox.setStandardButtons(QMessageBox::Cancel|QMessageBox::Ok);
        if(msgBox.exec() == QMessageBox::Ok) {
            pat->addIDResource(id_res);
            update_ressource_reserved_list();
        }
    }
}

/**
 * @brief jury whether nom editer is filled
 */
bool DialogModifyPatient::on_nomEdit_editingFinished()
{
    bool finish = true;
    if(ui->nomEdit->text().isEmpty()){
        ui->nomEdit->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->nomEdit->setStyleSheet("background-color: white;");
        pat->setNom(ui->nomEdit->text());
    }
    return finish;
}


/**
 * @brief jury whether prenom editer is filled
 */
bool DialogModifyPatient::on_prenomEdit_editingFinished()
{
    bool finish = true;
    if(ui->prenomEdit->text().isEmpty()){
        ui->prenomEdit->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->prenomEdit->setStyleSheet("background-color: white;");
        pat->setPrenom(ui->prenomEdit->text());
    }
    return finish;
}

/**
 * @brief jury whether spinBox is filled
 */
bool DialogModifyPatient::on_spinBox_editingFinished()
{
    bool finish = true;
    if(ui->spinBox->value() == 0 || ui->spinBox->value()>5) {
        QMessageBox msgBox;
        msgBox.setText("La priorité : de 5 à 1 avec 5 comme plus prioritaire!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
        finish = false;
    } else {
        pat->setPriorite(ui->spinBox->value());
    }
    return finish;
}

/**
 * @brief jury whether duration editer is filled
 */
bool DialogModifyPatient::on_dureeEdit_editingFinished()
{
    bool finish = true;
    if(ui->dureeEdit->text().isEmpty()){
        ui->dureeEdit->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        //Q.8
        if(ui->dureeEdit->text().toInt() < 10) {
            QMessageBox msgBox;
            msgBox.setText("Au moin 10 mins!");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();
        }
        ui->dureeEdit->setStyleSheet("background-color: white;");
        pat->setDuree(ui->dureeEdit->text().toInt());
    }
    return finish;
}

/**
 * @brief jury whether cp editer is filled
 */
bool DialogModifyPatient::on_cpEdit_editingFinished()
{
    bool finish = true;
    if(ui->cpEdit->text().isEmpty()){
        ui->cpEdit->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->cpEdit->setStyleSheet("background-color: white;");
        pat->setCodePostale(ui->cpEdit->text().toInt());
    }
    return finish;
}

/**
 * @brief jury whether city editer is filled
 */
bool DialogModifyPatient::on_villeEdit_editingFinished()
{
    bool finish = true;
    if(ui->villeEdit->text().isEmpty()){
        ui->villeEdit->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->villeEdit->setStyleSheet("background-color: white;");
        pat->setVille(ui->villeEdit->text());
    }
    return finish;

}

/**
 * @brief jury whether address editer is filled
 */
bool DialogModifyPatient::on_adresseEdit_textChanged()
{
    bool finish = true;
    if(ui->adresseEdit->toPlainText().isEmpty()){
        ui->adresseEdit->setStyleSheet("background-color: red;");
        finish = false;
    } else {
        ui->adresseEdit->setStyleSheet("background-color: white;");
    }
    return finish;
}

///**
// * @brief action after clicking button ajouter
// * @details reserver new ressource
// */
//void DialogAjouterPatient::on_pushButton_add_clicked()
//{
//    //add ???
//    int row = model_res->rowCount();
//    model_res->insertRows(row,1);
//    QModelIndex index = model_res->index(row,0);
//    ui->listView->setCurrentIndex(index);
//    ui->listView->edit(index);
//    std::vector<int>::iterator it;
//    for(it=pat->getIDResource().begin(); it!=pat->getIDResource().end(); ++it) {
//        qDebug() << *it << ",";
//    }
//    qDebug() << "add:" << index.data().toInt();
//    pat->addIDResource(index.data(0).toInt());
//}


//void DialogAjouterPatient::on_pushButton_ins_clicked()
//{
//    //insert
//    int row = ui->listView->currentIndex().row();
//    model_res->insertRows(row,1);
//    QModelIndex index = model_res->index(row,0);
//    ui->listView->setCurrentIndex(index);
//    ui->listView->edit(index);
//    pat->addIDResource(index.data(0).toInt());

//}


/**
 * @brief action after clicking button supprimer
 * @details cancal a ressource reservered
 */
void DialogModifyPatient::on_pushButton_del_clicked()
{
    //delete
    model_res->removeRows(ui->listView->currentIndex().row(),1);
    qDebug() << "row del:"<<ui->listView->currentIndex().row();
    int row = ui->listView->currentIndex().row();
    pat->getIDResource().erase(pat->getIDResource().begin()+row-1);
}

/**
 * @brief check the necessary editors are all finished
 * @return true represents all done
 */
bool DialogModifyPatient::all_editors_full()
{
    bool nom = on_nomEdit_editingFinished();
    bool prenom = on_prenomEdit_editingFinished();
    bool cp = on_cpEdit_editingFinished();
    bool ville = on_villeEdit_editingFinished();
    bool pro = on_spinBox_editingFinished();
    bool duree = on_dureeEdit_editingFinished();
    if(nom && prenom  && cp && ville && pro && duree) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief action after clicking button OK
 * @details add a new patient with consult
 */
void DialogModifyPatient::on_buttonBox_accepted()
{
    if(all_editors_full()) {
        // Q.4
        if(!ui->telEdit->text().isEmpty()) {
            pat->setTelephone(ui->telEdit->text().toInt());
        }
        if((!ui->driveEdit->toPlainText().isEmpty())&&(!ui->commEdit->toPlainText().isEmpty())) {
            comm_and_dri = ui->commEdit->toPlainText() + ", drive:" + ui->driveEdit->toPlainText();
            pat->setComments(comm_and_dri);
        } else if ((ui->driveEdit->toPlainText().isEmpty())&&(!ui->commEdit->toPlainText().isEmpty())) {
            pat->setComments(ui->commEdit->toPlainText());
        } else if ((!ui->driveEdit->toPlainText().isEmpty())&&(ui->commEdit->toPlainText().isEmpty())) {
            comm_and_dri =  "No commentaire, drive:" + ui->driveEdit->toPlainText();
            pat->setComments(comm_and_dri);
        }
        if(!ui->commEdit->toPlainText().isEmpty()) {
            pat->setComments(ui->commEdit->toPlainText());
        }

        pat->setDate(ui->dateEdit->date());
        pat->setAdress(ui->adresseEdit->toPlainText());
        int id = cst_Ctrl.getMaxIdPatient()+1;
        pat->setIdPatient(id);
        cst_Ctrl.addPatient(*pat,id);
        qDebug() << "add patient to db";
        std::vector<int>::iterator it;
        for(it=pat->getIDResource().begin(); it!=pat->getIDResource().end(); ++it) {
            cst_Ctrl.addConsult(id,*it);
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Veuillez remplir la zone de saisie avec *!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }

}

/**
 * @brief action after clicking button cancel
 * @details quit this page
 */
void DialogModifyPatient::on_buttonBox_rejected()
{
    this->close();
}

//get comm and drive
QString DialogModifyPatient::getCommAndDri()
{
    this->comm_and_dri;
}




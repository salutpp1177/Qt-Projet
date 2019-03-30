#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Vous avez connecté!");
    model = new QStandardItemModel(this);
    show_liste_ressource();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

/**
 * @brief initialize the first level of treeview
 * @details show the type label in every first level
 */
void MainWindow::init_treeView()
{
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Nom")<<QStringLiteral("Prenom")<<QStringLiteral("Id_Ressource"));
    model->appendRow(new QStandardItem(QStringLiteral("1_Médecin_A")));
    model->appendRow(new QStandardItem(QStringLiteral("2_Médecin_B")));
    model->appendRow(new QStandardItem(QStringLiteral("3_Radiologue")));
    model->appendRow(new QStandardItem(QStringLiteral("4_Infirmière")));
    model->appendRow(new QStandardItem(QStringLiteral("5_Kinésithérapeute")));
    model->appendRow(new QStandardItem(QStringLiteral("6_Psychologue")));
    model->appendRow(new QStandardItem(QStringLiteral("7_informaticien")));
}

/**
 * @brief show the list of ressource in window finally
 */
void MainWindow::show_liste_ressource()
{
    init_treeView();
    vector<Ressource> vec_res = res_Ctrl.showAllRessource();
    std::vector<Ressource>::iterator it;
    for(it=vec_res.begin(); it!=vec_res.end(); ++it) {
        QList<QStandardItem*> liste;
        liste.append(new QStandardItem(it->getNom()));
        liste.append(new QStandardItem(it->getPrenom()));
        liste.append(new QStandardItem(QString::number(it->getIdRessource())));
        switch (it->getType()) {
        case 1 :
        {
            model->item(0)->appendRow(liste);
            break;
        }
        case 2 :
        {
            model->item(1)->appendRow(liste);
            break;
        }
        case 3 :
        {
            model->item(2)->appendRow(liste);
            break;
        }
        case 4 :
        {
            model->item(3)->appendRow(liste);
            break;
        }
        case 5 :
        {
            model->item(4)->appendRow(liste);
            break;
        }
        case 6 :
        {
            model->item(5)->appendRow(liste);
            break;
        }
        case 7 :
        {
            model->item(6)->appendRow(liste);
            break;
        }
        }
    }
    ui->treeView->setModel(model);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

/**
 * @brief update the list of ressource
 */
void MainWindow::update_liste_ressource()
{
    model->clear();
    show_liste_ressource();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

/**
 * @brief action to open new dialog
 */
void MainWindow::on_actionPersonnel_de_soins_triggered()
{
    add_res.show();
    //Q.7
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage("En train d'ajouter un patient!");
    if(add_res.exec() == QDialog::Accepted) {
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage("Vous avez réussi à ajouter une ressource!");
        update_liste_ressource();
    }

}

/**
 * @brief action to open new dialog
 */
void MainWindow::on_actionPatient_triggered()
{
    add_pat.show();
    if(add_pat.exec() == QDialog::Accepted) {
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage("Vous avez réussi à ajouter un patient!");

    }
}

/**
 * @brief action to doucle-click the treeView
 */
void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    int type = index.parent().row()+1;
    if(index.column() != 2) {
        //Qmessage
        QMessageBox msgBox;
        msgBox.setText("Veillez appuyer sur son Id_Ressource! ");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    } else {
        int id_res = index.data(0).toInt();
        qDebug() <<id_res;
        Ressource res = res_Ctrl.selectRessourceById(id_res);
        QMessageBox msgBox;
        msgBox.setText("Vouz voulez supprimer la ressource?");
        msgBox.setInformativeText(res_Ctrl.selectTypeParmiById(type).getTypeName()+": "+ res.getNom()+"  "+res.getPrenom());
        msgBox.setStandardButtons(QMessageBox::Help|QMessageBox::Cancel|QMessageBox::Ok);
        msgBox.setButtonText(QMessageBox::Help, QString("Modifier..."));
        if(msgBox.exec() == QMessageBox::Ok) {
            if(type==7) {
                res_Ctrl.deleteCompteByIdRessource(id_res);
            }
            res_Ctrl.deleteRessourceById(id_res);
            update_liste_ressource();
            ui->statusBar->clearMessage();
            ui->statusBar->showMessage("Vous avez réussi à modifier une ressource!");

        } else if (msgBox.exec() == QMessageBox::Help){
            mdf_res.show();
            mdf_res.setId_Res(id_res);
            if(mdf_res.exec() == QDialog::Accepted) {
                update_liste_ressource();
                ui->statusBar->clearMessage();
                ui->statusBar->showMessage("Vous avez réussi à modifier une ressource!");
            }
        }
    }

}


/**
 * @brief action
 */
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index  > 0) {
        update_liste_ressource();
    }
}

/**
 * @brief action to click the button rechercher
 * @details select the patient according to the input information
 */
void MainWindow::on_rechercher_clicked()
{
    vector<Patient> vec_pat;
    QDate d(2000,1,1);
    QDate begin = ui->dateEdit_du->date();
    QDate end = ui->dateEdit_au->date();

    //check date form if begin-date is after ending-date
    if(begin.daysTo(end) < 0) {
        QMessageBox msg1;
        msg1.setText("Veillez vérifier la date! ");
        msg1.setStandardButtons(QMessageBox::Ok);
        msg1.exec();

    }

    if(on_lineEdit_id_editingFinished()) {

        //select patient by id
        int id_pat = ui->lineEdit_id->text().toInt();
        vec_pat.push_back(cst_Ctrl.selectPatientById(id_pat));
        init_patient_list(vec_pat);

    } else {

        if ((!on_lineEdit_nom_editingFinished())&&(!on_lineEdit_prenom_editingFinished())) {
            //select patient just by date
            if(d.daysTo(end) == 0) {
                QDate today = QDate::currentDate();
                vec_pat = cst_Ctrl.selectPatientByDate(today.toString(Qt::ISODate),today.addMonths(1).toString(Qt::ISODate));
            } else {
                vec_pat = cst_Ctrl.selectPatientByDate(begin.toString(Qt::ISODate), end.toString(Qt::ISODate));
            }
        } else if (on_lineEdit_nom_editingFinished()&&(!on_lineEdit_prenom_editingFinished())) {
            //select patient by nom
            if(d.daysTo(end) == 0) {
                //select patient just by nom
                vec_pat = cst_Ctrl.selectPatientByName(ui->lineEdit_nom->text(), nullptr);
            } else {
                //select patient by nom and date
                vec_pat = cst_Ctrl.selectPatientByNameAndDate(begin.toString(Qt::ISODate), end.toString(Qt::ISODate), ui->lineEdit_nom->text(), 0);
            }

        } else if (on_lineEdit_prenom_editingFinished()&&(!on_lineEdit_nom_editingFinished())) {
            //select patient by prenom
            if(d.daysTo(end) == 0) {
                //select patient just by prenom
                vec_pat = cst_Ctrl.selectPatientByName(nullptr, ui->lineEdit_prenom->text());
            } else {
                //select patient by prenom and date
                vec_pat = cst_Ctrl.selectPatientByNameAndDate(begin.toString(Qt::ISODate), end.toString(Qt::ISODate), ui->lineEdit_prenom->text(), 1);
            }

        } else {
            //select patient just by nom and prenom
                vec_pat = cst_Ctrl.selectPatientByName(ui->lineEdit_nom->text(), ui->lineEdit_prenom->text());
        }

    }


    init_patient_list(vec_pat);

}


/**
 * @brief jury whether password editer is filled
 */
bool MainWindow::on_lineEdit_id_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_id->text().isEmpty()){
        finish = false;
    } else {
        ui->lineEdit_id->setStyleSheet("background-color: yellow;");
    }
    return finish;
}

/**
 * @brief
 */
void MainWindow::init_patient_list(vector<Patient> &vec_pat)
{
    QStandardItemModel *model_pat;
    if(!vec_pat.empty()) {
        model_pat = new QStandardItemModel(this);
        model_pat->setColumnCount(11);
        model_pat->setHeaderData(0,Qt::Horizontal, "Id");
        model_pat->setHeaderData(1,Qt::Horizontal, "Nom");
        model_pat->setHeaderData(2,Qt::Horizontal, "Prenom");
        model_pat->setHeaderData(3,Qt::Horizontal, "Adresse");
        model_pat->setHeaderData(4,Qt::Horizontal, "Ville");
        model_pat->setHeaderData(5,Qt::Horizontal, "CP");
        model_pat->setHeaderData(6,Qt::Horizontal, "Commentaire");
        model_pat->setHeaderData(7,Qt::Horizontal, "Tel");
        model_pat->setHeaderData(8,Qt::Horizontal, "DateConsultation");
        model_pat->setHeaderData(9,Qt::Horizontal, "Duree(mins)");
        model_pat->setHeaderData(10,Qt::Horizontal, "Priorité");
        std::vector<Patient>::iterator it;
        for (it=vec_pat.begin(); it!=vec_pat.end(); ++it) {
            QList<QStandardItem*> list;
            list.append(new QStandardItem(QString::number(it->getIdPatient())));
            list.append(new QStandardItem(it->getNom()));
            list.append(new QStandardItem(it->getPrenom()));
            list.append(new QStandardItem(it->getAdress()));
            list.append(new QStandardItem(it->getVille()));
            list.append(new QStandardItem(QString::number(it->getCodePostale())));
            list.append(new QStandardItem(it->getComments()));
            list.append(new QStandardItem(QString::number(it->getTelephone())));
            list.append(new QStandardItem(it->getDate().toString()));
            list.append(new QStandardItem(QString::number(it->getDuree())));
            list.append(new QStandardItem(QString::number(it->getPriorite())));
            model_pat->appendRow(list);
        }
        ui->tableView->setModel(model_pat);

    }
}

/**
 * @brief jury whether nom editer is filled
 */
bool MainWindow::on_lineEdit_nom_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_nom->text().isEmpty()){
        finish = false;
    } else {
        ui->lineEdit_nom->setStyleSheet("background-color: yellow;");
    }
    return finish;
}

/**
 * @brief jury whether prenom editer is filled
 */
bool MainWindow::on_lineEdit_prenom_editingFinished()
{
    bool finish = true;
    if(ui->lineEdit_prenom->text().isEmpty()){
        finish = false;
    } else {
        ui->lineEdit_prenom->setStyleSheet("background-color: yellow;");
    }
    return finish;
}

/**
 * @brief jury whether password editer is filled
 */
void MainWindow::on_pushButton_plan_clicked()
{
    model_plan = new QStandardItemModel(this);
    vector<Patient> vec_pat = cst_Ctrl.selectPatientByDate(ui->dateEdit->date().toString(Qt::ISODate),ui->dateEdit->date().toString(Qt::ISODate));
    list<pair<Consult, int>> sort = cst_Ctrl.sortConsult(vec_pat);
    model_plan = new QStandardItemModel(this);
    model_plan->setColumnCount(5);
    model_plan->setHeaderData(0,Qt::Horizontal, "Heure");
    model_plan->setHeaderData(1,Qt::Horizontal, "IdConsult");
    model_plan->setHeaderData(2,Qt::Horizontal, "Nom");
    model_plan->setHeaderData(3,Qt::Horizontal, "Prenom");
    model_plan->setHeaderData(4,Qt::Horizontal, "IdRessource");
    std::list<pair<Consult, int>>::iterator it;
    for (it=sort.begin(); it!=sort.end(); ++it) {
        QList<QStandardItem*> list;
        int hh = (it->second)/60;
        int mm = it->second-hh*60;
        QString str(QString::number(hh)+"H"+QString::number(mm));
        list.append(new QStandardItem(str));
        int id_cst = cst_Ctrl.selectConsultById(it->first.getPatient(), it->first.getRessource());
        list.append(new QStandardItem(QString::number(id_cst)));
        Patient p = cst_Ctrl.selectPatientById(it->first.getPatient());
        list.append(new QStandardItem(p.getNom()));
        list.append(new QStandardItem(p.getPrenom()));
        list.append(new QStandardItem(QString::number(it->first.getRessource())));
    }
    ui->tableView_plan->setModel(model_plan);
}

/**
 * @brief exporter file of sorting
 */
void MainWindow::on_pushButton_2_clicked()
{
    QString textData;
    int rows = model_plan->rowCount();
    int columns = model_plan->columnCount();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            textData += model->data(model->index(i,j)).toString();
            textData += "       " ;
        }
        textData += "\n";
    }

    QFile txtFile("/Users/jiangyaqi/Desktop/planification.txt");
    if(txtFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {

        QTextStream out(&txtFile);
        out << textData;
        txtFile.close();
    }

}

/*
 * Question 3
*/
void MainWindow::on_actionPsychologue_triggered()
{
    add_psy.show();
    if(add_psy.exec() == QDialog::Accepted) {
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage("Vous avez réussi à ajouter un patient!");
        update_liste_ressource();

    }
}


void MainWindow::on_actionModifier_Patient_triggered()
{
    mdf_pat.show();
    if(mdf_pat.exec() == QDialog::Accepted) {
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage("Vous avez réussi à ajouter un patient!");
    }
}

#ifndef DIALOGAJOUTERPATIENT_H
#define DIALOGAJOUTERPATIENT_H

#include <QDialog>

namespace Ui {
class DialogAjouterPatient;
}

class DialogAjouterPatient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterPatient(QWidget *parent = nullptr);
    ~DialogAjouterPatient();

private:
    Ui::DialogAjouterPatient *ui;
};

#endif // DIALOGAJOUTERPATIENT_H

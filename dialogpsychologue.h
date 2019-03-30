#ifndef DIALOGPSYCHOLOGUE_H
#define DIALOGPSYCHOLOGUE_H

#include <QDialog>
#include "controller/ressourcecontroller.h"

namespace Ui {
class DialogPsychologue;
}

class DialogPsychologue : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPsychologue(QWidget *parent = nullptr);
    ~DialogPsychologue();

private slots:
    void on_buttonBox_accepted();

    bool on_lineEdit_editingFinished();

    bool on_lineEdit_2_editingFinished();

private:
    Ui::DialogPsychologue *ui;
    ressourceController res_Ctrl;

};

#endif // DIALOGPSYCHOLOGUE_H

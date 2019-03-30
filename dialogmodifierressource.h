#ifndef DIALOGMODIFIERRESSOURCE_H
#define DIALOGMODIFIERRESSOURCE_H

#include <QDialog>
#include <controller/ressourcecontroller.h>

namespace Ui {
class DialogModifierRessource;
}

class DialogModifierRessource : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifierRessource(QWidget *parent = nullptr);
    ~DialogModifierRessource();
    void setId_Res(int id);
    int getId_Res();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogModifierRessource *ui;
    int id_res;
};

#endif // DIALOGMODIFIERRESSOURCE_H

#ifndef DIALOGAJOUTERSOIGNEUR_H
#define DIALOGAJOUTERSOIGNEUR_H

#include <QDialog>

namespace Ui {
class DialogAjouterSoigneur;
}

class DialogAjouterSoigneur : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterSoigneur(QWidget *parent = nullptr);
    ~DialogAjouterSoigneur();

private:
    Ui::DialogAjouterSoigneur *ui;
};

#endif // DIALOGAJOUTERSOIGNEUR_H

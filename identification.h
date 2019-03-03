#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QDialog>
#include <QString>
#include <mainwindow.h>
#include <qmessagebox.h>
#include <controller/verificationcontroller.h>

namespace Ui {
class Identification;
}

class Identification : public QDialog
{
    Q_OBJECT

public:
    explicit Identification(QWidget *parent = nullptr);
    ~Identification();

private slots:
    void on_loginBtn_clicked();

    void on_annulerBtn_clicked();

    void on_passwd_textEdited(const QString &arg1);

private:
    Ui::Identification *ui;
    MainWindow w;
};

#endif // IDENTIFICATION_H

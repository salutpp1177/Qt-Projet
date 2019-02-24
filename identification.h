#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QDialog>
#include <mainwindow.h>
#include <qmessagebox.h>

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Identification *ui;
    MainWindow w;
};

#endif // IDENTIFICATION_H

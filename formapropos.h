#ifndef FORMAPROPOS_H
#define FORMAPROPOS_H

#include <QWidget>

namespace Ui {
class FormAPropos;
}

class FormAPropos : public QWidget
{
    Q_OBJECT

public:
    explicit FormAPropos(QWidget *parent = nullptr);
    ~FormAPropos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormAPropos *ui;
};

#endif // FORMAPROPOS_H

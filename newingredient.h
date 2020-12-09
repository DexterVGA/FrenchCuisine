#ifndef NEWINGREDIENT_H
#define NEWINGREDIENT_H

#include <QWidget>
#include <QMainWindow>
#include <QAbstractButton>
#include <QMessageBox>

namespace Ui {
class NewIngredient;
}

class NewIngredient : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewIngredient(QWidget *parent = nullptr);
    ~NewIngredient();

private:
    Ui::NewIngredient *ui;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

signals:
    void sendData(QString str);

};

#endif // NEWINGREDIENT_H

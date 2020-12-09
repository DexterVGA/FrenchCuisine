#ifndef NEWRECIPE_H
#define NEWRECIPE_H

#include <QWidget>
#include <QMainWindow>
#include <QAbstractButton>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class NewRecipe;
}

class NewRecipe : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewRecipe(QWidget *parent = nullptr);
    ~NewRecipe();

private:
    Ui::NewRecipe *ui;
    int flag = 0;
    void buttonCheck();
    QString buttonsNotFill = "";
    QString filename = "";

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void loadButton_click();

signals:
    void sendData(QString str);
};

#endif // NEWRECIPE_H

#ifndef EDITRECIPE_H
#define EDITRECIPE_H

#include <QWidget>
#include <QMainWindow>
#include <QAbstractButton>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class editRecipe;
}

class editRecipe : public QMainWindow
{
    Q_OBJECT

public:
    explicit editRecipe(QWidget *parent = nullptr);
    ~editRecipe();

public slots:
    void recieveData(QString);

private:
    Ui::editRecipe *ui;
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

#endif // EDITRECIPE_H

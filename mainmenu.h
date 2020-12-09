#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QFileDialog>
#include <newingredient.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private:
    Ui::MainMenu *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
    QString name;
    NewIngredient *newIng;

private slots:
    void addIngredient();
    void dataReceprion(QString);
    void dataSort();

};
#endif // MAINMENU_H

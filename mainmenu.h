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
#include <newrecipe.h>

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
    NewRecipe *newRecipe;
    void addPictures();

private slots:
    void addIngredient();
    void addNewRecipe();
    void dataReception(QString);
    void newRecipeReception(QString);
    void dataSort();

};
#endif // MAINMENU_H

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QFileDialog>
#include <QTableView>
#include <newingredient.h>
#include <newrecipe.h>
#include <helper.h>
#include <editrecipe.h>

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
    QTableView *resultView;
    QSqlDatabase db;
    QString name;
    NewIngredient *newIng;
    NewRecipe *newRecipe;
    Helper *help;
    editRecipe *editForm;
    int rowNum = 0;
    int randomDish = 0;
    int rowNumDiff = 0;
    void addPictures();

private slots:
    void addIngredient();
    void addNewRecipe();
    void dataReception(QString);
    void newRecipeReception(QString);
    void editReception(QString);
    void dataSort();
    void handleOnTableClicked(const QModelIndex &);
    void showDailyDish();
    void editRecipe_slot();

signals:
    void sendData(QString str);

};
#endif // MAINMENU_H

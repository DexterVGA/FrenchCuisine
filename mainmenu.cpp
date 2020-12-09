#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    newIng = new NewIngredient(this);
    newIng->hide();

    connect(ui->addIngrButton, SIGNAL(clicked()), this, SLOT(addIngredient()));
    connect(ui->setFilter_button, SIGNAL(clicked()), this, SLOT(dataSort()));

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/vadimgrebensikov/3 course/1 semester/Visual/CourseWork/Reсipes.db3");
    if(db.open()) {
        model = new QSqlTableModel(parent, db);
        model->setTable("french_cuisine");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->setColumnHidden(6, true);
        ui->tableView->setColumnWidth(1, 125);
        ui->tableView->setColumnWidth(2, 125);
        ui->tableView->setColumnWidth(3, 75);
        ui->tableView->setColumnWidth(4, 135);
        ui->tableView->setColumnWidth(5, 135);
        ui->tableView->show();

        /*for(int i = 0; i < model->rowCount(); i++) {
            QString query = ":/pictures/" + QString::number(i + 1) + ".jpg";
            model->setData(model->index(i, 6), query);
        }
        model->submitAll();*/
    } else {
        QMessageBox::warning(this, "Error", db.lastError().text());
    }

    //ui->label->setText(model->index(2,1).data().toString());
    //ui->label->setPixmap(QPixmap(":/pictures/1.jpg"));
    //ui->label->setText(QString::number(model->rowCount()));

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::addIngredient()
{
    newIng->show();
}

void MainMenu::dataReceprion(QString str)
{
    ui->comboBox_3->addItem(str);
}

void MainMenu::dataSort()
{
    QString strCat = "'%" + ui->comboBox->currentText() + "%'";
    QString strDiff = "'%" + ui->comboBox_2->currentText() + "%'";
    QString strIng = "'%" + ui->comboBox_3->currentText().toLower() + "%'";

    if(ui->comboBox->currentText() == "Любая категория") {
        strCat = "'%%'";
    }
    if(ui->comboBox_2->currentText() == "Любая сложность") {
        strDiff = "'%%'";
    }
    if(ui->comboBox_3->currentText().toLower() == "любые ингредиенты") {
        strIng = "'%%'";
    }

    model->setFilter("Категория LIKE " + strCat + " AND Сложность LIKE " + strDiff + " AND Ингредиенты LIKE " + strIng);
    model->setSort(0, Qt::AscendingOrder);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnWidth(1, 125);
    ui->tableView->setColumnWidth(2, 125);
    ui->tableView->setColumnWidth(3, 75);
    ui->tableView->setColumnWidth(4, 135);
    ui->tableView->setColumnWidth(5, 135);
    ui->tableView->show();
}

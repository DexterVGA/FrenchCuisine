#include "newrecipe.h"
#include "ui_newrecipe.h"

NewRecipe::NewRecipe(QWidget *parent) : QMainWindow(parent), ui(new Ui::NewRecipe)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/icon.png"));
    connect(this, SIGNAL(sendData(QString)), parent, SLOT(newRecipeReception(QString)));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadButton_click()));
}

NewRecipe::~NewRecipe()
{
    delete ui;
}

void NewRecipe::loadButton_click()
{
    filename = QFileDialog::getOpenFileName(0, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    QPixmap pix(filename);
    int w = ui->label_8->width();
    int h = ui->label_8->height();
    ui->label_8->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void NewRecipe::buttonCheck()
{
    if(ui->lineEdit->text().isEmpty()) {
        flag = 1;
        buttonsNotFill += "Название блюда\n";
    }
    if(ui->lineEdit_2->text().isEmpty()) {
        flag = 1;
        buttonsNotFill += "Категория\n";
    }
    if(ui->lineEdit_3->text().isEmpty()) {
        flag = 1;
        buttonsNotFill += "Сложность\n";
    }
    if(ui->lineEdit_4->text().isEmpty()) {
        flag = 1;
        buttonsNotFill += "Ингредиенты\n";
    }
    if(ui->lineEdit_5->text().isEmpty()) {
        flag = 1;
        buttonsNotFill += "Время приготовления\n";
    }
    if(filename.isEmpty()) {
        flag = 1;
        buttonsNotFill += "Изображение\n";
    }
}

void NewRecipe::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text() == "OK") {
        buttonCheck();
        if(flag) {
            QMessageBox::warning(this, "Внимание", "Следующие поля должны дыть заполнены:\n" + buttonsNotFill);
            flag = 0;
            buttonsNotFill = "";
        } else {
            QString str = ui->lineEdit->text() + "\n";
            str += ui->lineEdit_2->text() + "\n";
            str += ui->lineEdit_3->text() + "\n";
            str += ui->lineEdit_4->text() + "\n";
            str += ui->lineEdit_5->text() + "\n";
            str += filename + "\n";
            emit sendData(str);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            filename = "";
            buttonsNotFill = "";
            this->hide();
        }
    } else if(button->text() == "Cancel") {
        this->hide();
    }
}

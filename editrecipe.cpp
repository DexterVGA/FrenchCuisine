#include "editrecipe.h"
#include "ui_editrecipe.h"

editRecipe::editRecipe(QWidget *parent) : QMainWindow(parent), ui(new Ui::editRecipe)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/icon.png"));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadButton_click()));
    connect(this, SIGNAL(sendData(QString)), parent, SLOT(editReception(QString)));
}

editRecipe::~editRecipe()
{
    delete ui;
}

void editRecipe::buttonCheck()
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
    if(ui->textEdit->toPlainText().isEmpty()) {
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

void editRecipe::on_buttonBox_clicked(QAbstractButton *button)
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
            str += ui->textEdit->toPlainText() + "\n";
            str += ui->lineEdit_5->text() + "\n";
            str += filename + "\n";
            emit sendData(str);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->textEdit->clear();
            ui->lineEdit_5->clear();
            filename = "";
            buttonsNotFill = "";
            this->hide();
        }
    } else if(button->text() == "Cancel") {
        this->hide();
    }
}

void editRecipe::loadButton_click()
{
    filename = QFileDialog::getOpenFileName(0, "Выберите изображение", QDir::currentPath(), "*.png *.jpg *.gif *.jpeg");
    QPixmap pix(filename);
    int w = ui->label_8->width();
    int h = ui->label_8->height();
    ui->label_8->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void editRecipe::recieveData(QString str)
{
    QStringList lst = str.split("\n");
    ui->lineEdit->setText(lst.at(0));
    ui->lineEdit_2->setText(lst.at(1));
    ui->lineEdit_3->setText(lst.at(2));
    ui->textEdit->setText(lst.at(3));
    ui->lineEdit_5->setText(lst.at(4));
    filename = lst.at(5);
    QPixmap pix(filename);
    int w = ui->label_8->width();
    int h = ui->label_8->height();
    ui->label_8->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

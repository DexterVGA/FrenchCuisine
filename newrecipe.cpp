#include "newrecipe.h"
#include "ui_newrecipe.h"

NewRecipe::NewRecipe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewRecipe)
{
    ui->setupUi(this);
}

NewRecipe::~NewRecipe()
{
    delete ui;
}

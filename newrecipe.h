#ifndef NEWRECIPE_H
#define NEWRECIPE_H

#include <QWidget>

namespace Ui {
class NewRecipe;
}

class NewRecipe : public QWidget
{
    Q_OBJECT

public:
    explicit NewRecipe(QWidget *parent = nullptr);
    ~NewRecipe();

private:
    Ui::NewRecipe *ui;
};

#endif // NEWRECIPE_H

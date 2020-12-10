#include "helper.h"
#include "ui_helper.h"

Helper::Helper(QWidget *parent) : QWidget(parent), ui(new Ui::Helper)
{
    ui->setupUi(this);
    connect(ui->nextButton, SIGNAL(clicked()), ui->textBrowser, SLOT(forward()));
    connect(ui->prevButton, SIGNAL(clicked()), ui->textBrowser, SLOT(backward()));
    connect(ui->homeButton, SIGNAL(clicked()), ui->textBrowser, SLOT(home()));
    connect(ui->textBrowser, SIGNAL(forwardAvailable(bool)), ui->nextButton, SLOT(setEnabled(bool)));
    connect(ui->textBrowser, SIGNAL(backwardAvailable(bool)), ui->prevButton, SLOT(setEnabled(bool)));
    ui->textBrowser->setSource(QUrl::fromLocalFile(":/browser/helper/index.html"));
}

Helper::~Helper()
{
    delete ui;
}

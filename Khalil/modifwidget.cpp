#include "modifwidget.h"
#include "ui_modifwidget.h"

ModifWidget::ModifWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifWidget)
{
    ui->setupUi(this);
}

ModifWidget::~ModifWidget()
{
    delete ui;
}

#include "addwidget.h"
#include "ui_addwidget.h"

AddWidget::AddWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWidget)
{
    ui->setupUi(this);
}

AddWidget::~AddWidget()
{
    delete ui;
}

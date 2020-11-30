#include "widmod2.h"
#include "ui_widmod2.h"

WidMod2::WidMod2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WidMod2)
{
    ui->setupUi(this);
}

WidMod2::~WidMod2()
{
    delete ui;
}

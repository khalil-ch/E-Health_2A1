#include "addw.h"
#include "ui_addw.h"

AddW::AddW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddW)
{
    ui->setupUi(this);
}

AddW::~AddW()
{
    delete ui;
}

#include "aboutwid.h"
#include "ui_aboutwid.h"
#include <QPixmap>

Aboutwid::Aboutwid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aboutwid)
{
    ui->setupUi(this);
    QPixmap pixmapTarget = QPixmap("C:/Users/khali/Desktop/integration finaleee!!!/E-Health_2A1/Integration_Ehealth/Logo/INFOSHIELD+++.png");
    //pixmapTarget = pixmapTarget.scaled(size-5, size-5, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->logoabout->setPixmap(pixmapTarget);
}

Aboutwid::~Aboutwid()
{
    delete ui;
}

void Aboutwid::on_Close_clicked()
{
    this->close();
}

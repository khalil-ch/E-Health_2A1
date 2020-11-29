#include "modifwidget.h"
#include "ui_modifwidget.h"
#include "mainwindow.h"
#include "QString"

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

void ModifWidget::on_pushButton_clicked()
{
    QString nom=ui->lineEdit->text();
    QString prenom=ui->lineEdit_2->text();
    Chefservice c(774,nom,prenom);
    c.modifierChefSv(nom,prenom);
    close();
}

void ModifWidget::on_pushButton_2_clicked()
{
    close();
}

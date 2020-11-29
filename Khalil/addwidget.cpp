#include "addwidget.h"
#include "ui_addwidget.h"
#include "chefservice.h"
#include <QMessageBox>
#include "mainwindow.h"

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


void AddWidget::on_Enregistrer_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
    QString nom=ui->lineEdit_Nom->text();
    QString prenom=ui->lineEdit_Prenom->text();
    Chefservice c(id,nom,prenom);
    bool test=c.ajouterChefSv();
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("chefservice ajoute"),QObject::tr("connection successful\n""click cancel"),QMessageBox::Cancel);
    }
    else
    {
    QMessageBox::information(nullptr,QObject::tr("database error"),QObject::tr("connection unsuccessful\n""click cancel"),QMessageBox::Cancel);
    }
}

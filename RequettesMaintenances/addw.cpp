#include "addw.h"
#include "ui_addw.h"
#include <QString>
#include "requette.h"
#include <QMessageBox>
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
// spec=ui->ModSpecEq->itemText(ui->ModSpecEq->currentIndex());
void AddW::on_ConfirmerAddRq_clicked()
{
    QString ref=ui->AddRqRef->text();
    QString ideq=ui->AddRqIdEq->text();
    QString etat="Non Resolu";//ui->CheckboxRq->accessibleName();
    if(ui->CheckboxRq->checkState())
        etat="Resolu";
    else
        etat="Non Resolu";
    QString service=ui->AddRqServ->itemText(ui->AddRqServ->currentIndex());
    QString typem=ui->AddRqTypeRq->itemText(ui->AddRqTypeRq->currentIndex());
    QDate dateajout=ui->DateAjoutEdit->date();
    //QString ref,QString ideq,QString service,QString typem,QString etat
    Requette req(ref,ideq,service,typem,etat,dateajout);
    bool test=req.AjouterReq();
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("req ajoute"),QObject::tr("connection successful\n""click cancel"),QMessageBox::Cancel);
    }
    else
    {
    QMessageBox::information(nullptr,QObject::tr("database error"),QObject::tr("connection unsuccessful\n""click cancel"),QMessageBox::Cancel);
    }
}

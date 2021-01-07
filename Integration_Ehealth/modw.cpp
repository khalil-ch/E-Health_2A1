#include "modw.h"
#include "ui_modw.h"
#include "requette.h"
#include <QMessageBox>
ModW::ModW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModW)
{
    ui->setupUi(this);
}

ModW::~ModW()
{
    delete ui;
}

void ModW::on_ConfirmModif_clicked()
{
    QString Eqid=ui->ModRqIdEq->text();
    QString typem=ui->ModRqType->itemText(ui->ModRqType->currentIndex());
    QString et="Non Resolu";
    if(ui->ModRqEtat->checkState())
        et="Resolu";
    else
        et="Non Resolu";
    QString serv=ui->ModRqServ->itemText(ui->ModRqServ->currentIndex());
    Requette req;
    req.SetInfotmp(GetReftmp());
    bool test=req.ModifierReq(Eqid,typem,et,serv);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectuee\n"
                                             "click cancel to exite"),QMessageBox::Cancel);
        close();
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                QObject::tr("modification non effectuee\n"
                            "click cancel to exit"),QMessageBox::Cancel);
    }
}

void ModW::on_CancelModif_clicked()
{
    this->close();
}

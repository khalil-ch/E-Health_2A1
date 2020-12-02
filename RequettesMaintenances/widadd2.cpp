#include "widadd2.h"
#include "ui_widadd2.h"
#include <QMessageBox>
#include "equipemaintenance.h"
WidAdd2::WidAdd2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WidAdd2)
{
    ui->setupUi(this);
}

WidAdd2::~WidAdd2()
{
    delete ui;
}
/*    QString IdEquipe,infotmp;
    QString ChefEquipe;
    QString Specialitee;
    QString NbReq;*/
void WidAdd2::on_AddEqConfirm_clicked()
{
    QString ideq=ui->AddIdEq->text();
    QString chefeq=ui->AddChefeq->text();
    QString spec=ui->AddSpecEq->currentText();//ui->CheckboxRq->accessibleName();
    QString nbrq=ui->AddNbRq->text();
    //QString ref,QString ideq,QString service,QString typem,QString etat
    EquipeMaintenance equipe(ideq,chefeq,spec,nbrq);
    bool test=equipe.AjouterEq();
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("Equipe ajoute"),QObject::tr("connection successful\n""click cancel"),QMessageBox::Cancel);
    }
    else
    {
    QMessageBox::information(nullptr,QObject::tr("database error"),QObject::tr("connection unsuccessful\n""click cancel"),QMessageBox::Cancel);
    }
}

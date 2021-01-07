#include "widmod2.h"
#include "ui_widmod2.h"
#include "equipemaintenance.h"
#include <QMessageBox>

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

void WidMod2::on_ConfirmerModEq_clicked()
{
    QString Eqid=ui->ModEqId->text();
    QString nomchef=ui->ModChefEq->text();
    QString spec=ui->ModSpecEq->itemText(ui->ModSpecEq->currentIndex());
    QString nbrq=ui->ModEqNbRq->text();
    EquipeMaintenance eq;
    eq.SetInfotmp2(getIDeqtmp());
    bool test=eq.ModifierEq(nomchef,spec,nbrq);

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

void WidMod2::on_AnnulerModEq_clicked()
{
    this->close();
}

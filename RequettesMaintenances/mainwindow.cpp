#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widadd2.h"
#include"widmod2.h"
#include "addw.h"
#include "modw.h"
#include "requette.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(requettetmp.AfficherReq());
    ui->tableView_2->setModel(equipetmp.AfficherEq());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AjouterReq_clicked()
{
    AddW widgetajout;
    widgetajout.setModal(true);
    widgetajout.exec();
    ui->tableView->setModel(requettetmp.AfficherReq());
}

void MainWindow::on_ActualiserReq_clicked()
{
    ui->tableView->setModel(requettetmp.AfficherReq());
}

void MainWindow::on_DeleteReq_clicked()
{
    QString ref=ui->lineEdit->text();
    bool test=requettetmp.SupprimerReq(ref);
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("suppression effectuee\n"
                                             "click cancel to exite"),QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                QObject::tr("suppression non effectuee\n"
                            "click cancel to exit"),QMessageBox::Cancel);
    }
    ui->tableView->setModel(requettetmp.AfficherReq());
}

void MainWindow::on_ModifReq_clicked()
{
    ModW WidgetMod;
    WidgetMod.SetReftmp(ui->lineEdit->text());
    WidgetMod.setModal(true);
    WidgetMod.exec();
}
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString info= QVariant(index.data()).toString();
    ui->lineEdit->clear();
    ui->lineEdit->insert(info);

}

void MainWindow::on_RechercheReq_clicked()
{
    requettetmp.SetInfotmp(ui->lineEdit->text());
    ui->tableView->setModel(requettetmp.RechercheReqbyRef());
}

void MainWindow::on_FiltrerReqSv_currentIndexChanged(const QString &arg1)
{
    //filtre
    requettetmp.SetInfotmp(ui->FiltrerReqSv->currentText());
    ui->tableView->setModel(requettetmp.RechercheReqbyService());
}
/*    AddW widgetajout;
    widgetajout.setModal(true);
    widgetajout.exec();
    ui->tableView->setModel(requettetmp.AfficherReq());*/
void MainWindow::on_AjouterEq_clicked()//ajouter equipe
{
    WidAdd2 widgetequipeadd;
    widgetequipeadd.setModal(true);
    widgetequipeadd.exec();
    ui->tableView_2->setModel(equipetmp.AfficherEq());
}

void MainWindow::on_ActualiserEq_clicked()
{
    ui->tableView_2->setModel(equipetmp.AfficherEq());
}

void MainWindow::on_RechercheEq_clicked()
{
    equipetmp.SetInfotmp2(ui->lineEdit_2->text());
    ui->tableView_2->setModel(equipetmp.RechercheEqbyId());
}

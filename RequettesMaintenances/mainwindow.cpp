#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widadd2.h"
#include"widmod2.h"
#include "addw.h"
#include "modw.h"
#include "requette.h"
#include <QMessageBox>
#include "statchart.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statRq->hide();
    ui->tableView->setModel(requettetmp.AfficherReq());
    ui->tableView_2->setModel(equipetmp.AfficherEq());

    animation = new QPropertyAnimation(ui->groupBox_2, "geometry");
    animation2 = new QPropertyAnimation(ui->groupBox, "geometry");
    animation->setDuration(1000);
    animation2->setDuration(2500);
    animation->setStartValue(ui->groupBox_2->geometry());
    animation2->setStartValue(ui->groupBox_2->geometry());
    animation->setEndValue(QRect(100,450,551,90));
    animation2->setEndValue(QRect(10,10,751,391));

    animation->start();
    animation2->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AjouterReq_clicked()//Ajouter Requettes
{
    AddW widgetajout;
    widgetajout.setWindowTitle("Ajouter Requette");
    widgetajout.setModal(true);
    widgetajout.exec();
    ui->tableView->setModel(requettetmp.AfficherReq());
}

void MainWindow::on_ActualiserReq_clicked()//Actualiser Requettes
{
    ui->tableView->setModel(requettetmp.AfficherReq());
}

void MainWindow::on_DeleteReq_clicked()//Supprimer Requette
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

void MainWindow::on_ModifReq_clicked()//Modifier Requette
{
    ModW WidgetMod;
    WidgetMod.setWindowTitle("Modifier Requette");
    WidgetMod.SetReftmp(ui->lineEdit->text());
    WidgetMod.setModal(true);
    WidgetMod.exec();
}
/*---------table view-----------*/
void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)//Afficher
{
    //int col=ui->tableView->model()->columnCount(index);
    int row=ui->tableView->model()->rowCount(index);
    ui->lineEdit->clear();
    QString infoint=QString::number(row);
    QModelIndex idx;
    QString info = QVariant(index.data()).toString();
    ui->lineEdit->insert(info);
}
/*-----------------------------*/
void MainWindow::on_RechercheReq_clicked()
{

    requettetmp.SetInfotmp(ui->lineEdit->text());
    ui->tableView->setModel(requettetmp.RechercheReqbyRef());
}

void MainWindow::on_FiltrerReqSv_currentIndexChanged(const QString &arg1)//filtrer requette
{
    //filtre
    requettetmp.SetInfotmp(ui->FiltrerReqSv->currentText());
    ui->tableView->setModel(requettetmp.RechercheReqbyService());
}
void MainWindow::on_AjouterEq_clicked()//ajouter equipe
{
    WidAdd2 widgetequipeadd;
    widgetequipeadd.setModal(true);
    widgetequipeadd.setWindowTitle("Ajouter Equipe");
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

void MainWindow::on_statRq_clicked()
{
    QString info = ui->tableView->model()->data(ui->tableView->model()->index(1,2)).toString();
    QStringList Employees;
    for (int i = 0; i < 3; ++i) {
        info = ui->tableView->model()->data(ui->tableView->model()->index(0,3)).toString();
        Employees<<info;
    }
    StatChart stat;
    stat.setWindowTitle("Requettes par equipe");
    stat.exec();

}

void MainWindow::on_ModifEq_clicked()
{
    WidMod2 widmodeq;
    widmodeq.setIDeqtmp(ui->lineEdit_2->text());
    widmodeq.setWindowTitle("Modifier Equipe");
    widmodeq.exec();
}

void MainWindow::on_DelEq_clicked()
{
    equipetmp.SupprimerEq(ui->lineEdit_2->text());
}

void MainWindow::on_statEq_clicked()
{
    QString info = ui->tableView->model()->data(ui->tableView->model()->index(1,2)).toString();
    QStringList Employees;
    for (int i = 0; i < ui->tableView_2->model()->rowCount(); ++i) {
        info = ui->tableView_2->model()->data(ui->tableView->model()->index(i,1)).toString();
        Employees<<info;
    }
    QStringList values;
    for (int i = 0; i < ui->tableView_2->model()->rowCount(); ++i) {
        info = ui->tableView_2->model()->data(ui->tableView->model()->index(i,3)).toString();
        values<<info;
    }
    //values<<"35"<<"45"<<"58";
    StatChart stat;
    stat.setModal(true);
    stat.setWindowTitle("Statistiques");
    stat.afficherStats(&Employees,&values);
    stat.exec();
}

void MainWindow::on_TrierEq_currentIndexChanged(const QString &arg1)
{
    if(ui->TrierEq->currentText()=="Nom")
        ui->tableView_2->setModel(equipetmp.TrierNom());
    else if(ui->TrierEq->currentText()=="Requettes")
        ui->tableView_2->setModel(equipetmp.TrierRequettes());
    else
        return;
}

void MainWindow::on_TrierReq_currentIndexChanged(const QString &arg1)
{
    if(ui->TrierReq->currentText()=="Reference")
        ui->tableView->setModel(requettetmp.TrierParREF());
    else if(ui->TrierReq->currentText()=="Date")
        ui->tableView->setModel(requettetmp.TrierParDATE());
    else
        return;
}

void MainWindow::on_ExtraiareReq_clicked()
{
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter printer(QPrinter::PrinterResolution);
        QString imgsource="C:/Users/khali/Desktop/Project-E-Health/RequettesMaintenances/UtopiaSft.png";
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        QString *html = new QString();
        QStringList info;
        int i=0;
        for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {

            for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
                info<<ui->tableView->model()->data(ui->tableView->model()->index(row,col)).toString();//(row,col)
                *html=*html+info.at(i)+"\t";
                i++;
            }*html+="<br> ";
        }
        *html+="<img src=+"+imgsource+" >";
        i=0;
        /*----*/
        QTextDocument doc;
        doc.setHtml(*html);
        doc.setPageSize(printer.pageRect().size());//hide num de poge
        doc.print(&printer);
}

void MainWindow::on_TabReqAndEquipes_currentChanged(int index)
{
    if (index==1)
        ui->groupBox_2->hide();
    else
        ui->groupBox_2->show();
}

void MainWindow::on_FiltrerEq_currentIndexChanged(const QString &arg1)
{
    equipetmp.SetInfotmp2(ui->FiltrerEq->currentText());
    ui->tableView_2->setModel(equipetmp.RechercheEqbySpec());
}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int row=ui->tableView_2->model()->rowCount(index);
    ui->lineEdit_2->clear();
    QString infoint=QString::number(row);
    QString info = QVariant(index.data()).toString();
    ui->lineEdit_2->insert(info);
}

void MainWindow::on_ExtraireEq_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    QString imgsource="C:/Users/khali/Desktop/Project-E-Health/RequettesMaintenances/UtopiaSft.png";
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    QString *html = new QString();
    QStringList info;
    int i=0;
    for (int row = 0; row < ui->tableView_2->model()->rowCount(); ++row) {

        for (int col = 0; col < ui->tableView_2->model()->columnCount(); ++col) {
            info<<ui->tableView_2->model()->data(ui->tableView_2->model()->index(row,col)).toString();//(row,col)
            *html=*html+info.at(i)+"\t";
            i++;
        }*html+="<br> ";
    }
    *html+="<img src=+"+imgsource+" >";
    i=0;
    /*----*/
    QTextDocument doc;
    doc.setHtml(*html);
    doc.setPageSize(printer.pageRect().size());//hide num de poge
    doc.print(&printer);
}

void MainWindow::on_FiltrerReqEtat_currentIndexChanged(const QString &arg1)
{
    requettetmp.SetInfotmp(ui->FiltrerReqEtat->currentText());
    if((ui->FiltrerReqEtat->currentText()=="Resolu")||(ui->FiltrerReqEtat->currentText()=="Non Resolu"))
        ui->tableView->setModel(requettetmp.RechercheReqbyEtat());
    else
        return;
}

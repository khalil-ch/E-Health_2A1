#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modifwidget.h"
#include "addwidget.h"
#include "chefservice.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(chefservicetmp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//supression
{
int id = ui->lineEdit->text().toInt();
bool test=chefservicetmp.supprimerChefSv(id);
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
    ui->tableView->setModel(chefservicetmp.afficher());
}

void MainWindow::on_pushButton_3_clicked()//recherche
{
    QString id = ui->lineEdit->text();
    ui->tableView->setModel(chefservicetmp.rechercheChefSv(id));
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
QString ress=QVariant(index.data()).toString();
ui->lineEdit->clear();
ui->lineEdit->insert(ress);

}

void MainWindow::on_pushButton_4_clicked()//bouton ajouter appel widget ajouter
{
    AddWidget addw;
    addw.setModal(true);
    addw.exec();
    ui->tableView->setModel(chefservicetmp.afficher());
}

void MainWindow::on_pushButton_2_clicked()//bouton modifier appel widget modifier
{
    ModifWidget modw;
    modw.setIDtmp(ui->lineEdit->text());
    modw.setModal(true);
    modw.exec();
    ui->tableView->setModel(chefservicetmp.afficher());
}

void MainWindow::on_pushButton_4_released()
{
    ui->tableView->setModel(chefservicetmp.afficher());
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->tableView->setModel(chefservicetmp.afficher());
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    Chefservice chef;
    ui->lineEdit->setText(ui->comboBox_2->itemText(ui->comboBox_2->currentIndex()));
    ui->tableView->setModel(chefservicetmp.searchChefSvAvanceeSV(ui->lineEdit->text()));
}

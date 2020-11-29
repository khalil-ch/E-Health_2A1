#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medicament.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(temp.afficher());
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    QString NOM=ui->nomLineEdit->text();
    QString TYPE=ui->typeDeMDicamentComboBox->currentText();
    int QUANTITE=ui->quantitLineEdit->text().toInt();
    QString FOURNISSEUR=ui->fournisseurLineEdit->text();
    QDate DATE_EXP=ui->dateDExpirationDateEdit->date();
    QString REFERENCE=ui->referenceLineEdit->text();
    Medicament medicament(NOM,TYPE,QUANTITE,FOURNISSEUR,DATE_EXP,REFERENCE);

    bool test=medicament.ajouter();
    if(test)
    { ui->tableView->setModel(temp.afficher());

    }
    else {
        QMessageBox::warning(this,"Erreur lors de l ajout du medicament","Veuillez remplir tous les champs à nouveau");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if (ui->pushButton_5->isChecked())
    {
        ui->pushButton_5->setDisabled(true);
        ui->pushButton_5->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("Medicament");
        tableModel->select();
        ui->tableView->setModel(tableModel);
    }
    else
    {
        ui->pushButton_5->setText("Modifier");
        ui->tableView->setModel(temp.afficher());

    }

}

void MainWindow::on_pushButton_4_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();

    QString NOM =select->selectedRows(0).value(0).data().toString();

    if(temp.supprimer(NOM))
    {
        ui->tableView->setModel(temp.afficher());
        ui->statusbar->showMessage("Medicament supprimé");
    }

}


void MainWindow::on_pushButton_7_clicked()
{
    QSqlQueryModel * test = new QSqlQueryModel();
    if (ui->pushButton_7->isChecked()){
        ui->pushButton_7->setText("En cours");
        if(ui->radioButton_2->isChecked()){
            QString REFERENCE = ui->lineEdit->text();
            test=temp.chercher_med(REFERENCE,1);
        }
        else if(ui->radioButton_3->isChecked())
        {
            QString NOM = ui->lineEdit->text();
            test=temp.chercher_med(NOM,2);
        }
        else if(ui->radioButton->isChecked())
        {
            QString FOURNISSEUR = ui->lineEdit->text();
            test=temp.chercher_med(FOURNISSEUR,3);
        }
        if(test!=nullptr)
        {
            QMessageBox::information(nullptr, QObject::tr("chercher un medicament"),
                                     QObject::tr("medicament trouvé.\n"
                                                 "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tableView->setModel(test);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("chercher un medicament"),
                                  QObject::tr("Erreur , medicament n'existe pas !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(test);
        }}
        else
        {
            ui->pushButton_7->setText("Recherche");
            ui->tableView->setModel(temp.afficher());

        }
    }

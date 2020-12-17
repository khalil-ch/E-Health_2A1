#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medicament.h"
#include"fournisseur.h"
#include "stats.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(temp.afficher());
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setModel(tempo.afficher());
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

















void MainWindow::on_resetmed_clicked()
{
    ui->nomLineEdit->setText("");
    ui->quantitLineEdit->setText("");
    ui->fournisseurLineEdit->setText("");
    ui->referenceLineEdit->setText("");
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

void MainWindow::on_pushButton_6_clicked()
{
    stats *a= new stats() ;
    a->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    if (ui->pushButton_5->isChecked())
    {
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

void MainWindow::on_pushButton_8_clicked()
{
    ui->nomline->setText("");
    ui->matriculeline->setText("");
    ui->adresseline->setText("");
}

void MainWindow::on_pushButton_9_clicked()
{
    QString NOM=ui->nomline->text();
    QString MATRICULE=ui->matriculeline->text();
    QString ADRESSE=ui->adresseline->text();
    fournisseur fournisseur(NOM,MATRICULE,ADRESSE);

    bool test1=fournisseur.ajouter();
    if(test1)
    { ui->tableView_2->setModel(tempo.afficher());

    }
    else {
        QMessageBox::warning(this,"Erreur lors de l ajout du fournisseur","Veuillez remplir tous les champs à nouveau");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    if(ui->radionom->isChecked())
       {
            if(ui->comboBox->currentText()=="Ordre croissant")
                 ui->tableView_2->setModel(tempo.trier_four("NOM",1));
            else
                 ui->tableView_2->setModel(tempo.trier_four("NOM",2));
       }
       else if(ui->radiomat->isChecked())
    {
         if(ui->comboBox->currentText()=="Ordre croissant")
              ui->tableView_2->setModel(tempo.trier_four("MATRICULE",1));
         else
              ui->tableView_2->setModel(tempo.trier_four("MATRICULE",2));
    }
       else if(ui->radioad->isChecked())
    {
         if(ui->comboBox->currentText()=="Ordre croissant")
              ui->tableView_2->setModel(tempo.trier_four("ADRESSE",1));
         else
              ui->tableView_2->setModel(tempo.trier_four("ADRESSE",2));
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_2->model()->rowCount();
    const int columnCount = ui->tableView_2->model()->columnCount();

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg("Title")
          <<  "</head>\n"
           <<"<body bgcolor=#ffffff link=#5000A0>\n"

           //     "<align='right'> " << datefich << "</align>"
           <<"<center> <H1>Liste des fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";


    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_2->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_2->isColumnHidden(column)) {
                QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
            "</body>\n"
            "</html>\n";



        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setPaperSize(QPrinter::A4);
        printer->setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer->pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(printer);

        QPrinter *p=new QPrinter();
        QPrintDialog dialog(p,this);
        if(dialog.exec()== QDialog::Rejected)
        {
            return;
        }
}

void MainWindow::on_pushButton_12_clicked()
{
    if (ui->pushButton_12->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("FOURNISSEUR");
        tableModel->select();
        ui->tableView_2->setModel(tableModel);
    }
    else
    {
        ui->pushButton_12->setText("Modifier");
        ui->tableView_2->setModel(tempo.afficher());

    }
}

void MainWindow::on_pushButton_13_clicked()
{
    QItemSelectionModel *select = ui->tableView_2->selectionModel();

    QString MATRICULE =select->selectedRows(1).value(0).data().toString();

    if(tempo.supprimer(MATRICULE))
    {
        ui->tableView_2->setModel(tempo.afficher());
        ui->statusbar->showMessage("Fournisseur supprimé");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    temp.exporter(ui->tableView);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}

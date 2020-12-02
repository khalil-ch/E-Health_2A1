#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "chambre.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include<QTextStream>
#include <QtWidgets>
#include <QItemSelectionModel>
#include <QModelIndexList>
#include <QStringList>
#include <QPropertyAnimation>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableView_Patient->setModel(tmpPatient.afficher());
    ui->tableView_chambre->setModel(tmpChambre.afficher());
   //this->setStyleSheet("background-color: rgb(0, 0, 100);");
    ui->lineEdit_CIN->setMaxLength(8);
    ui->lineEdit_cinp->setMaxLength(8);
    ui->lineEdit_cin_supp->setMaxLength(8);
    ui->lineEdit_recherchecin->setMaxLength(8);
    ui-> dateEdit->setMinimumDate(QDate::currentDate());
    ui->dateEdit17->setMinimumDate(QDate::currentDate());
    int const n=0;
        QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("C:/Users/hp/Desktop/qt/Piano-melancholy-music-short.mp3"));
        player->setVolume(n);
        player->play();
        ui->spinBox->setRange(0,100);
        ui->spinBox->setValue(n);
        ui->horizontalSlider->setRange(0,100);
        ui->horizontalSlider->setValue(n);
        QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->spinBox,SLOT(setValue(int)));
        QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));
        QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),player,SLOT(setVolume(int)));
        QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),player,SLOT(setVolume(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString cin = ui->lineEdit_CIN->text();
    QString id= ui->lineEdit->text();
    int age= ui-> lineEdit_age->text().toInt();
    int duree= ui-> lineEdit_duree->text().toInt();
    QDate Date_entrer= ui-> dateEdit->date();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    patient p(cin,id,age,duree,Date_entrer,nom,prenom);
      if ((age!=0)&&(cin.length()!=0) &&(duree!=0)&&(nom.length()!=0)&&
              (prenom.length()!=0)&&(id.length()!=0)
            &&(nom>='a'&&nom<='z' ) &&(prenom>='a'&&nom<='z' ))
      {
          bool test=p.ajouter();

if(test)
   { ui->tableView_Patient->setModel(tmpPatient.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajouter Patient"),
                QObject::tr("Patient ajuter.\n""Click Cancel to exit."), QMessageBox::Cancel);

    }
      }
else

{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter Patient"),
                QObject::tr("Ajout echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}



foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }

}
void MainWindow::on_pushButton_15_clicked()
{
    QString cin = ui -> lineEdit_cin_supp->text() ;

    bool test=tmpPatient.supprimer(cin);

    if(test)
       { ui->tableView_Patient->setModel(tmpPatient.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer Patient"),
                    QObject::tr("Patient supprimer.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }

    else

    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer Patient"),
                    QObject::tr("suppression echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

    }
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
        }
}

void MainWindow::on_pushButton_3_clicked()
{

    QString cin= ui->lineEdit_cinp->text();
    QString id= ui->lineEdit_2->text();
    int age= ui->lineEdit_agep->text().toInt();
    int duree= ui->lineEdit_dureep->text().toInt();
    QDate Date_entrer=ui->dateEdit17->date();
    QString nom=ui->lineEdit_nomp->text();
    QString prenom=ui->lineEdit_prenomp->text();

    if ((age!=0)&&(duree!=0)&&(nom.length()!=0)&&(prenom.length()!=0)&&
            (id.length()!=0)
           &&(nom>='a'&&nom<='z' ) &&(prenom>='a'&&nom<='z' )  )
    {

        bool test = tmpPatient.update(cin,id,age,duree,Date_entrer,nom,prenom);

        if(test)

        {
            ui->tableView_Patient->setModel(tmpPatient.afficher());

            QMessageBox::information(nullptr, QObject::tr("update "),
                        QObject::tr("Patient modifie\n"
        "Click Cancel to exit."), QMessageBox::Cancel);}
    }
        foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                widget->clear();
            }
}


void MainWindow::on_pushButton_9_clicked()
{
    int etage= ui-> lineEdit_etage->text().toInt();
    int numero_chambre= ui-> lineEdit_num->text().toInt();
    QString id= ui-> lineEdit_id->text();
    QString type=ui->comboBox->currentText();

    chambre ch(id ,etage,numero_chambre,type);
    if ((etage>=0)&&(numero_chambre>0)&&(id.length()!=0)&&(type.length()!=0))
    {

bool test=ch.ajouter();
if(test)
   { ui->tableView_chambre->setModel(tmpChambre.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajouter chambre"),
                QObject::tr("chambre ajouter.\n""Click Cancel to exit."), QMessageBox::Cancel);
}
}
else

{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter chambre"),
                QObject::tr("Ajout echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}
foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

void MainWindow::on_pushButton_16_clicked()
{
    QString id = ui -> lineEdit_csupp->text();
    bool test=tmpChambre.supprimer(id);

    if(test)
       { ui->tableView_chambre->setModel(tmpChambre.afficher());

        QMessageBox::information(nullptr, QObject::tr("supprimer Chambre"),
                    QObject::tr("Chambre supprimer.\n""Click Cancel to exit."), QMessageBox::Cancel);
    }

    else

    {
        QMessageBox::critical(nullptr, QObject::tr("supprimer Chambre"),
                    QObject::tr("suppression echoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

    }
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
            widget->clear();
        }
}




void MainWindow::on_pushButton_10_clicked()
{
    QString id= ui->lineEdit_2id->text();
    
    int numero_chambre= ui->lineEdit_2num->text().toInt();
    int etage=ui->dateEdit_4->text().toInt();
    QString type=ui->comboBox_2->currentText();
if((etage>=0)&&(numero_chambre>0)&&(type!=""))
{
        bool test = tmpChambre.update(id,etage,numero_chambre,type);

        if(test)

        {
            ui->tableView_chambre->setModel(tmpChambre.afficher());

            QMessageBox::information(nullptr, QObject::tr("update "),
                        QObject::tr("Chambre modifie\n"
        "Click Cancel to exit."), QMessageBox::Cancel);}
        foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                widget->clear();
            }
}

}


void MainWindow::on_pushButton_5_clicked()
{
    QString cin= ui->lineEdit_recherchecin->text();
    QString nom= ui->lineEdit_3->text();
    QString prenom= ui->lineEdit_4->text();

    QSqlQueryModel *test=tmpPatient.rechercher_patient(cin,nom,prenom);
if (test)
{
   ui->tableView_Patient->setModel(test);
}
foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }

}

void MainWindow::on_pushButton_12_clicked()
{
    QString id=ui->lineEdit_idrech->text();
    int numero_chambre=ui->lineEdit_numrech->text().toInt();
    int etage=ui->lineEdit_etagerech->text().toInt();

    QSqlQueryModel *rech=tmpChambre.rechercher_chambre(id,numero_chambre,etage);
if (rech)
{
   ui->tableView_chambre->setModel(rech);
}
foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }

}






void MainWindow::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked())
    {
        ui->tableView_Patient->setModel(tmpPatient.trier("age"));
    }

}




void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        ui->tableView_chambre->setModel(tmpChambre.trier("numero_chambre"));
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView_chambre->model()->rowCount();
        const int columnCount =ui->tableView_chambre->model()->columnCount();
        out << "<h2 align=left> E HEALTH APPLICATION  </h2>";
        out << "<h2 align=right> UTOPIA SOFTWARES </h2>";

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("chambre")
                <<  "</head>\n"
                "<body bgcolor=lightblue link=#5000A0>\n"

                    "<h1>Liste des chambre</h1>"



                    "<table border=1 cellspacing=0 cellpadding=2>\n";


        // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView_chambre->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_chambre->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tableView_chambre->isColumnHidden(column)) {
                               QString data = ui->tableView_chambre->model()->data(ui->tableView_chambre->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                       "</body>\n"
                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;

                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {
                       document->print(&printer);
                }
}


void MainWindow::on_pushButton_6_clicked()
{

    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tableView_Patient->model()->rowCount();
            const int columnCount =ui->tableView_Patient->model()->columnCount();
            out << "<h2 align=left> E HEALTH APPLICATION  </h2>";
            out << "<h2 align=right> UTOPIA SOFTWARES </h2>";

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("patient")
                    <<  "</head>\n"
                    "<body bgcolor=lightblue link=#5000A0>\n"

                        "<h1>Liste des patient</h1>"



                        "<table border=1 cellspacing=0 cellpadding=2>\n";


            // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_Patient->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_Patient->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_Patient->isColumnHidden(column)) {
                                   QString data = ui->tableView_Patient->model()->data(ui->tableView_Patient->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";

                       QTextDocument *document = new QTextDocument();
                       document->setHtml(strStream);

                       QPrinter printer;

                       QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                       if (dialog->exec() == QDialog::Accepted) {
                           document->print(&printer);
                    }
    }


void MainWindow::on_pushButton_18_clicked()
{

    tmpChambre.exporter(ui->tableView_chambre);

}

void MainWindow::on_pushButton_19_clicked()
{
     tmpPatient.exporter(ui->tableView_Patient);
}

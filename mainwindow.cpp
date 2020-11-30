#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "chambre.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_Patient->setModel(tmpPatient.afficher());
    ui->tableView_chambre->setModel(tmpChambre.afficher());
  //  this->setStyleSheet("background-color: rgb(0, 0, 100);");
    ui->lineEdit_CIN->setMaxLength(8);

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
      if ((age!=0)&&(cin>'0')&&(cin!=NULL)&&(duree!=0)&&(nom!="")&&(prenom!="")&&(id!=""))
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

    if ((age!=0)&&(duree!=0)&&(nom!="")&&(prenom!="") && (id!=""))
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
    if ((etage>=0)&&(numero_chambre>0)&&(id!="")&&(type!=""))
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
    QDate Date_entrer= ui->dateEdit_2->date();

    QSqlQueryModel *test=tmpPatient.rechercher_patient(cin,nom,Date_entrer);
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

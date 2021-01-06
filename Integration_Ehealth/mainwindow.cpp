#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "medicament.h"
#include"fournisseur.h"
#include "stats.h"
#include "patient.h"
#include "chambre.h"
#include "patient.cpp"
#include "chambre.cpp"
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
#include  <QSound>
#include<QString>
#include <QTranslator>
#include <QtWidgets>
#include "email.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
//khalil
#include <addw.h>
#include <modw.h>
#include <widadd2.h>
#include <widmod2.h>
#include <statchart.h>
#include <dsikstat.h>
//
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son=new QSound("C:/Users/AZYZ/Desktop/Azyzprojet/music.wav");
    int ret=A.connect_arduino();
    switch (ret)
    {
     case(0):qDebug()<<"arduino is available and connected to :"<<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
       break;
    case(-1):qDebug()<<"arduino is not available and connected to :"<<A.getarduino_port_name();
       break;
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    ui->stackedWidget->setCurrentIndex(1);
    ui->tablemed->setModel(temp.afficher());
    ui->tablemed->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablemed->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablefour->setModel(tempo.afficher());
    ui->tablefour->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tablefour->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_Patient->setModel(tmpPatient.afficher());
    ui->tableView_chambre->setModel(tmpChambre.afficher());
    //khalil
    ui->tableView_Rq->setModel(requettetmp.AfficherReq());
    ui->tableView_Eq->setModel(equipetmp.AfficherEq());
    //
    //AZIZ KAHLOUL
    ui->tabpersonnel->setModel(tmppersonnel.afficher());
     ui->tabservice->setModel(tmpservice.afficher());
    ui->cin_per->setValidator(new QIntValidator(0,9999,this));
     ui->cin_chef->setValidator(new QIntValidator(0,9999,this));
      ui->id_service->setValidator(new QIntValidator(0,9999,this));
      ui->id_service_sup->setValidator(new QIntValidator(0,9999,this));
     ui->type_service->setMaxLength(9);
     ui->nom_per->setMaxLength(9);
     ui->prenom_per->setMaxLength(9);
     ui->type_per->setMaxLength(9);

     //
       //this->setStyleSheet("background-color: rgb(0, 0, 100);");
        ui->lineEdit_CINpatient->setMaxLength(8);
        ui->lineEdit_cinp->setMaxLength(8);
        ui->lineEdit_cin_supp->setMaxLength(8);
        ui->lineEdit_recherchecin->setMaxLength(8);
        ui->lineEdit_nomp->setMaxLength(10);
        ui->lineEdit_prenomp->setMaxLength(10);
        ui->lineEdit_nompatient->setMaxLength(10);
        ui->lineEdit_prenompatient->setMaxLength(10);
        ui->lineEdit_idchambre->setMaxLength(4);
        ui->lineEdit_agep->setMaxLength(2);
        ui->lineEdit_numchambre->setMaxLength(2);
        ui->lineEdit_etage->setMaxLength(1);
        ui->lineEdit_2id->setMaxLength(4);
        ui->lineEdit_2num->setMaxLength(2);
        ui->dateEdit_Modifchambre->setMaxLength(1);
        ui->lineEdit_rechnomp->setMaxLength(10);
        ui->lineEdit_rechprenomp->setMaxLength(10);
        ui->lineEdit_idrech->setMaxLength(4);
        ui->lineEdit_numrech->setMaxLength(2);
        ui->lineEdit_etagerech->setMaxLength(1);
        ui->lineEdit_csupp->setMaxLength(4);
        ui->lineEdit_idajoutp->setMaxLength(4);
        ui->lineEdit_age->setMaxLength(2);
        ui->lineEdit_idpatient->setMaxLength(4);
        ui-> dateEditajoutp->setMinimumDate(QDate::currentDate());
        ui->dateEditModifP->setMinimumDate(QDate::currentDate());
        int const n=0;
               QMediaPlayer *player = new QMediaPlayer;
               player->setMedia(QUrl::fromLocalFile("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Piano-melancholy-music-short.mp3"));
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

               //arduino khalil

                   ret=A.connect_arduino();


                   switch (ret)
                   {
                   case 0:
                       qDebug() << "arduino is available and connected to:" << A.getarduino_port_name();
                       break;
                   case 1:
                       qDebug() << "arduino is available but not connected to:" << A.getarduino_port_name();
                       break;
                   case -1:
                       qDebug() << "arduino is not available";
                       break;
                   }

                   QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label_khalil()));

}
//arduinoaziz

void MainWindow::update_label_aziz()
{
    data=A.read_from_arduino();
    QString DataAsString = QString(data);
    qDebug()<< data;

     ui->label_2->setText("temp : "+data);

    if (data=="21"||data=="22"||data=="23"||data=="24"||data=="25"||data=="26"||data=="27"){
        if (messageboxactive==0){
            alert=1;
        }


    }
    if (alert==1){
         alert=0;
         messageboxactive=1;
        int reponse = QMessageBox::question(this, "led", "allumer led", QMessageBox::Yes |  QMessageBox::No);
                                   if (reponse == QMessageBox::Yes)
                                   {
                                     led=1;
                                   }
                                   if (reponse == QMessageBox::No)
                                   {
                                      led=0;
                                   }

    }
    if (led==1){
        A.write_to_arduino("1");
    }
    if (data=="20"||data=="19"||data=="18"||data=="17"||data=="16"||data=="15"||data=="14 "){
        A.write_to_arduino("0");
        led=0;
    }

}

//fin arduino

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_resetmed_clicked()
{
    ui->nommedLineEdit->setText("");
    ui->quantitLineEdit->setText("");
    ui->fournisseurLineEdit->setText("");
    ui->referencemedLineEdit->setText("");
}







void MainWindow::on_ajoutmed_clicked()
{
    QString NOM=ui->nommedLineEdit->text();
    QString TYPE=ui->typeDeMDicamentComboBox->currentText();
    int QUANTITE=ui->quantitLineEdit->text().toInt();
    QString FOURNISSEUR=ui->fournisseurLineEdit->text();
    QDate DATE_EXP=ui->dateDExpirationDateEdit->date();
    QString REFERENCE=ui->referencemedLineEdit->text();
    Medicament medicament(NOM,TYPE,QUANTITE,FOURNISSEUR,DATE_EXP,REFERENCE);

    bool test=medicament.ajouter();
    if(test)
    { ui->tablemed->setModel(temp.afficher());

    }
    else {
        QMessageBox::warning(this,"Erreur lors de l ajout du medicament","Veuillez remplir tous les champs à nouveau");
    }
}

void MainWindow::on_rechmed_clicked()
{
    QSqlQueryModel * test = new QSqlQueryModel();
    if (ui->rechmed->isChecked()){
        ui->rechmed->setText("En cours");
        if(ui->radiorefmed->isChecked()){
            QString REFERENCE = ui->linerech->text();
            test=temp.chercher_med(REFERENCE,1);
        }
        else if(ui->radionommed->isChecked())
        {
            QString NOM = ui->linerech->text();
            test=temp.chercher_med(NOM,2);
        }
        else if(ui->radiofourmed->isChecked())
        {
            QString FOURNISSEUR = ui->linerech->text();
            test=temp.chercher_med(FOURNISSEUR,3);
        }
        if(test!=nullptr)
        {
            QMessageBox::information(nullptr, QObject::tr("chercher un medicament"),
                                     QObject::tr("medicament trouvé.\n"
                                                 "Click Cancel to get informations."), QMessageBox::Cancel);
            ui->tablemed->setModel(test);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("chercher un medicament"),
                                  QObject::tr("Erreur , medicament n'existe pas !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tablemed->setModel(test);
        }}
        else
        {
            ui->rechmed->setText("Recherche");
            ui->tablemed->setModel(temp.afficher());

        }
}

void MainWindow::on_statsmed_clicked()
{
    stats *a= new stats() ;
    a->show();
}

void MainWindow::on_modifmed_clicked()
{
    if (ui->modifmed->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("Medicament");
        tableModel->select();
        ui->tablemed->setModel(tableModel);
    }
    else
    {
        ui->modifmed->setText("Modifier");
        ui->tablemed->setModel(temp.afficher());

    }

}

void MainWindow::on_suppmed_clicked()
{
    QItemSelectionModel *select = ui->tablemed->selectionModel();

    QString NOM =select->selectedRows(0).value(0).data().toString();

    if(temp.supprimer(NOM))
    {
        ui->tablemed->setModel(temp.afficher());
        ui->statusbar->showMessage("Medicament supprimé");
    }
}

void MainWindow::on_excelmed_clicked()
{
    temp.exporter(ui->tablemed);
    ui->statusbar->showMessage("EXPORT TABLE ",5000);
}

void MainWindow::on_trierfour_clicked()
{
    if(ui->radionom->isChecked())
       {
            if(ui->ordrefour->currentText()=="Ordre croissant")
                 ui->tablefour->setModel(tempo.trier_four("NOM",1));
            else
                 ui->tablefour->setModel(tempo.trier_four("NOM",2));
       }
       else if(ui->radiomat->isChecked())
    {
         if(ui->ordrefour->currentText()=="Ordre croissant")
              ui->tablefour->setModel(tempo.trier_four("MATRICULE",1));
         else
              ui->tablefour->setModel(tempo.trier_four("MATRICULE",2));
    }
       else if(ui->radioad->isChecked())
    {
         if(ui->ordrefour->currentText()=="Ordre croissant")
              ui->tablefour->setModel(tempo.trier_four("ADRESSE",1));
         else
              ui->tablefour->setModel(tempo.trier_four("ADRESSE",2));
    }
}

void MainWindow::on_resetfour_clicked()
{
    ui->nomline->setText("");
    ui->matriculeline->setText("");
    ui->adresseline->setText("");
}

void MainWindow::on_ajoutfour_clicked()
{
    QString NOM=ui->nomline->text();
    QString MATRICULE=ui->matriculeline->text();
    QString ADRESSE=ui->adresseline->text();
    fournisseur fournisseur(NOM,MATRICULE,ADRESSE);

    bool test1=fournisseur.ajouter();
    if(test1)
    { ui->tablefour->setModel(tempo.afficher());

    }
    else {
        QMessageBox::warning(this,"Erreur lors de l ajout du fournisseur","Veuillez remplir tous les champs à nouveau");
    }
}

void MainWindow::on_pdffour_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tablefour->model()->rowCount();
    const int columnCount = ui->tablefour->model()->columnCount();

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
        if (!ui->tablefour->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tablefour->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tablefour->isColumnHidden(column)) {
                QString data = ui->tablefour->model()->data(ui->tablefour->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_modiffour_clicked()
{
    if (ui->modiffour->isChecked())
    {
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("FOURNISSEUR");
        tableModel->select();
        ui->tablefour->setModel(tableModel);
    }
    else
    {
        ui->modiffour->setText("Modifier");
        ui->tablefour->setModel(tempo.afficher());

    }
}

void MainWindow::on_suppfour_clicked()
{
    QItemSelectionModel *select = ui->tablefour->selectionModel();

    QString MATRICULE =select->selectedRows(1).value(0).data().toString();

    if(tempo.supprimer(MATRICULE))
    {
        ui->tablefour->setModel(tempo.afficher());
        ui->statusbar->showMessage("Fournisseur supprimé");
    }
}

void MainWindow::on_Login_clicked()
{
    if(ui->loginLineEdit->text()=="firas")
            ui->stackedWidget->setCurrentIndex(0);
    if (ui->loginLineEdit->text()=="eya")
        ui->stackedWidget->setCurrentIndex(2);
    if (ui->loginLineEdit->text()=="khalil")
        ui->stackedWidget->setCurrentIndex(3);
    if (ui->loginLineEdit->text()=="aziz")
        ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButtonAjoutP_clicked()
{
QString cin = ui->lineEdit_CINpatient->text();
   QString id= ui->lineEdit_idajoutp->text();
   int age= ui-> lineEdit_age->text().toInt();
   int duree= ui-> lineEdit_duree->text().toInt();
   QDate Date_entrer= ui->dateEditajoutp->date();
   QString nom= ui->lineEdit_nompatient->text();
   QString prenom= ui->lineEdit_prenompatient->text();
   patient p(cin,id,age,duree,Date_entrer,nom,prenom);
     if ((age!=0)&&(cin.length()!=0) &&(duree!=0)&&(nom.length()!=0)&&
             (prenom.length()!=0)&&(id.length()!=0)
           &&(nom>='a'&&nom<='z' ) &&(prenom>='a'&&nom<='z' ))
     {
         bool test=p.ajouter();

if(test)
  { ui->tableView_Patient->setModel(tmpPatient.afficher());
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
               notifyIcon-> show ();
                notifyIcon-> showMessage ( " GESTION PATIENT " , " Patient ajouté " , QSystemTrayIcon :: Information, 15000 );
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

void MainWindow::on_pushButton_updatepatient_clicked()
{
    QString cin= ui->lineEdit_cinp->text();
       QString id= ui->lineEdit_idpatient->text();
       int age= ui->lineEdit_agep->text().toInt();
       int duree= ui->lineEdit_dureep->text().toInt();
       QDate Date_entrer=ui->dateEditModifP->date();
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
               QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                          notifyIcon-> show ();
                           notifyIcon-> showMessage ( " GESTION PATIENT " , " Patient Modifié " , QSystemTrayIcon :: Information, 15000 );

               QMessageBox::information(nullptr, QObject::tr("update "),
                           QObject::tr("Patient modifie\n"
           "Click Cancel to exit."), QMessageBox::Cancel);}
       }
           foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                   widget->clear();
               }
}


void MainWindow::on_pushButton_suppP_clicked()
{
    QString cin = ui -> lineEdit_cin_supp->text() ;

       bool test=tmpPatient.supprimer(cin);

       if(test)
          { ui->tableView_Patient->setModel(tmpPatient.afficher());
           QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                      notifyIcon-> show ();
                       notifyIcon-> showMessage ( " GESTION PATIENT " , " Patient Supprimé " , QSystemTrayIcon :: Information, 15000 );
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

void MainWindow::on_pushButton_ajoutchambre_clicked()
{
    int etage= ui-> lineEdit_etage->text().toInt();
        int numero_chambre= ui-> lineEdit_numchambre->text().toInt();
        QString id= ui-> lineEdit_idchambre->text();
        QString type=ui->comboBoxchambre->currentText();

        chambre ch(id ,etage,numero_chambre,type);
        if ((etage>=0)&&(numero_chambre>0)&&(id.length()!=0)&&(type.length()!=0))
        {

    bool test=ch.ajouter();
    if(test)
       { ui->tableView_chambre->setModel(tmpChambre.afficher());
        QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                   notifyIcon-> show ();
                    notifyIcon-> showMessage ( " GESTION CHAMBRE " , " chambre ajouté " , QSystemTrayIcon :: Information, 15000 );
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

void MainWindow::on_pushButton_upatechambre_clicked()
{
    QString id= ui->lineEdit_2id->text();

        int numero_chambre= ui->lineEdit_2num->text().toInt();
        int etage=ui->dateEdit_Modifchambre->text().toInt();
        QString type=ui->comboBox_modiftypchambre->currentText();
    if((etage>=0)&&(numero_chambre>0)&&(type!=""))
    {
            bool test = tmpChambre.update(id,etage,numero_chambre,type);

            if(test)

            {
                ui->tableView_chambre->setModel(tmpChambre.afficher());
                QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                           notifyIcon-> show ();
                            notifyIcon-> showMessage ( " GESTION CHAMBRE " , " chambre modifié " , QSystemTrayIcon :: Information, 15000 );
                QMessageBox::information(nullptr, QObject::tr("update "),
                            QObject::tr("Chambre modifie\n"
            "Click Cancel to exit."), QMessageBox::Cancel);}
            foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                    widget->clear();
                }
    }
}

void MainWindow::on_pushButton_suppchambre_clicked()
{
    QString id = ui -> lineEdit_csupp->text();
       bool test=tmpChambre.supprimer(id);

       if(test)
          { ui->tableView_chambre->setModel(tmpChambre.afficher());
           QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                      notifyIcon-> show ();
                       notifyIcon-> showMessage ( " GESTION CHAMBRE " , " Chambre Supprimé " , QSystemTrayIcon :: Information, 15000 );
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

void MainWindow::on_pushButton_rechpatient_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
       sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
       sound ->play();
       QString cin= ui->lineEdit_recherchecin->text();
       QString nom= ui->lineEdit_rechnomp->text();
       QString prenom= ui->lineEdit_rechprenomp->text();

       QSqlQueryModel *test=tmpPatient.rechercher_patient(cin,nom,prenom);
   if (test)
   {
      ui->tableView_Patient->setModel(test);
   }
   foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
           widget->clear();
       }
}


void MainWindow::on_pushButton_rechchambre_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
        sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
        sound ->play();
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

void MainWindow::on_checkBox_rechercheage_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
      sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
      sound ->play();
      if (ui->checkBox_rechercheage->isChecked())
      {
          ui->tableView_Patient->setModel(tmpPatient.trier("age"));
          QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                     notifyIcon-> show ();
                      notifyIcon-> showMessage ( " GESTION PATIENT " , " Patient Trié " , QSystemTrayIcon :: Information, 15000 );
      }
}

void MainWindow::on_checkBoxchambre_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
       sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
       sound ->play();
       if (ui->checkBoxchambre->isChecked())
       {
           ui->tableView_chambre->setModel(tmpChambre.trier("numero_chambre"));
           QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                      notifyIcon-> show ();
                       notifyIcon-> showMessage ( " GESTION CHAMBRE " , " Chambre Trié " , QSystemTrayIcon :: Information, 15000 );
       }
}

void MainWindow::on_pushButton_PDFchambre_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
        sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
        sound ->play();
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

void MainWindow::on_pushButton_pdff_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
       sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
       sound ->play();
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

void MainWindow::on_pushButton_Exelchambre_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
        sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
        sound ->play();

        tmpChambre.exporter(ui->tableView_chambre);
}

void MainWindow::on_pushButton_ExcelP_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
     sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
     sound ->play();
      tmpPatient.exporter(ui->tableView_Patient);
}

void MainWindow::on_pushButton_affichertoutP_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
        sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
        sound ->play();
        ui->tableView_Patient->setModel(tmpPatient.afficher());
}

void MainWindow::on_pushButton_afficherchambre_clicked()
{
    QMediaPlayer *sound =new QMediaPlayer();
       sound-> setMedia(QUrl("C:\\Users\\hp\\Desktop\\integration eya!\\E-Health_2A1\\Integration_Ehealth\\Mouse-Click-03-m-FesliyanStudios.com.mp3"));
       sound ->play();
       ui->tableView_chambre->setModel(tmpChambre.afficher());
}
void MainWindow::update_label()
{
   data=A.read_from_arduino();
   heartRateBPM+=data;
   qDebug()<<"data = "<< data;
ui->lineEdit_bpm->setText(heartRateBPM);
   }
//code khalil
//Ajoute une requette avec appel a un autre widget
void MainWindow::on_AjouterReq_clicked()
{
    AddW widgetajout;
    widgetajout.setWindowTitle("Ajouter Requette");
    widgetajout.setModal(true);
    widgetajout.exec();
    ui->tableView_Rq->setModel(requettetmp.AfficherReq());
}
//Actualise l affichage de requettes
void MainWindow::on_ActualiserReq_clicked()
{
    ui->tableView_Rq->setModel(requettetmp.AfficherReq());
}
//Supression de requettes
void MainWindow::on_DeleteReq_clicked()
{
    QString ref=ui->lineEdit_Rq->text();
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
    ui->tableView_Rq->setModel(requettetmp.AfficherReq());
}
//modification de requette
void MainWindow::on_ModifReq_clicked()
{
    ModW WidgetMod;
    WidgetMod.setWindowTitle("Modifier Requette");
    WidgetMod.SetReftmp(ui->lineEdit_Rq->text());
    WidgetMod.setModal(true);
    WidgetMod.exec();
}
// tableview
void MainWindow::on_tableView_Rq_doubleClicked(const QModelIndex &index)
{
    //int col=ui->tableView->model()->columnCount(index);
    int row=ui->tableView_Rq->model()->rowCount(index);
    ui->lineEdit_Rq->clear();
    QString infoint=QString::number(row);
    QModelIndex idx;
    QString info = QVariant(index.data()).toString();
    ui->lineEdit_Rq->insert(info);
}
/*------------Recherche de requette-----------------*/
void MainWindow::on_RechercheReq_clicked()
{

    requettetmp.SetInfotmp(ui->lineEdit_Rq->text());
    ui->tableView_Rq->setModel(requettetmp.RechercheReqbyRef());
}

void MainWindow::on_FiltrerReqSv_currentIndexChanged(const QString &arg1)
{
    //filtre
    requettetmp.SetInfotmp(ui->FiltrerReqSv->currentText());
    ui->tableView_Rq->setModel(requettetmp.RechercheReqbyService());
}

void MainWindow::on_TrierReq_currentIndexChanged(const QString &arg1)
{
    if(ui->TrierReq->currentText()=="Reference")
        ui->tableView_Rq->setModel(requettetmp.TrierParREF());
    else if(ui->TrierReq->currentText()=="Date")
        ui->tableView_Rq->setModel(requettetmp.TrierParDATE());
    else
        return;
}
//Extraction PDF
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
    for (int row = 0; row < ui->tableView_Rq->model()->rowCount(); ++row) {

        for (int col = 0; col < ui->tableView_Rq->model()->columnCount(); ++col) {
            info<<ui->tableView_Rq->model()->data(ui->tableView_Rq->model()->index(row,col)).toString();//(row,col)
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
//Partie Equipe de maintenance
//Ajout equipe
void MainWindow::on_AjouterEq_clicked()
{
    WidAdd2 widgetequipeadd;
    widgetequipeadd.setModal(true);
    widgetequipeadd.setWindowTitle("Ajouter Equipe");
    widgetequipeadd.exec();
    ui->tableView_Eq->setModel(equipetmp.AfficherEq());
}
//Actualise l affichage
void MainWindow::on_ActualiserEq_clicked()
{
    ui->tableView_Eq->setModel(equipetmp.AfficherEq());
}
//recherche simple equipe
void MainWindow::on_RechercheEq_clicked()
{
    equipetmp.SetInfotmp2(ui->lineEdit_Eq->text());
    ui->tableView_Eq->setModel(equipetmp.RechercheEqbyId());
}
//Midfier equipe
void MainWindow::on_ModifEq_clicked()
{
    WidMod2 widmodeq;
    widmodeq.setIDeqtmp(ui->lineEdit_Eq->text());
    widmodeq.setWindowTitle("Modifier Equipe");
    widmodeq.exec();
}
//Suppression Equipe
void MainWindow::on_DelEq_clicked()
{
    equipetmp.SupprimerEq(ui->lineEdit_Eq->text());
}
//tri equipe
void MainWindow::on_TrierEq_currentIndexChanged(const QString &arg1)
{
    if(ui->TrierEq->currentText()=="Nom")
        ui->tableView_Eq->setModel(equipetmp.TrierNom());
    else if(ui->TrierEq->currentText()=="Requettes")
        ui->tableView_Eq->setModel(equipetmp.TrierRequettes());
    else
        return;
}

void MainWindow::on_FiltrerEq_currentIndexChanged(const QString &arg1)
{
    equipetmp.SetInfotmp2(ui->FiltrerEq->currentText());
    ui->tableView_Eq->setModel(equipetmp.RechercheEqbySpec());
}

void MainWindow::on_tableView_Eq_doubleClicked(const QModelIndex &index)
{
    int row=ui->tableView_Eq->model()->rowCount(index);
    ui->lineEdit_Eq->clear();
    QString infoint=QString::number(row);
    QString info = QVariant(index.data()).toString();
    ui->lineEdit_Eq->insert(info);
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
    for (int row = 0; row < ui->tableView_Eq->model()->rowCount(); ++row) {

        for (int col = 0; col < ui->tableView_Eq->model()->columnCount(); ++col) {
            info<<ui->tableView_Eq->model()->data(ui->tableView_Eq->model()->index(row,col)).toString();//(row,col)
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

void MainWindow::on_statEq_clicked()
{
    QString info = ui->tableView_Eq->model()->data(ui->tableView_Eq->model()->index(1,2)).toString();
    QStringList Employees;
    for (int i = 0; i < ui->tableView_Eq->model()->rowCount(); ++i) {
        info = ui->tableView_Eq->model()->data(ui->tableView_Eq->model()->index(i,1)).toString();
        Employees<<info;
    }
    QStringList values;
    for (int i = 0; i < ui->tableView_Eq->model()->rowCount(); ++i) {
        info = ui->tableView_Eq->model()->data(ui->tableView_Eq->model()->index(i,3)).toString();
        values<<info;
    }
    ui->lineEdit_Eq->insert(info);

    //values<<"35"<<"45"<<"58";
    StatChart stat;
    stat.setModal(true);
    stat.setWindowTitle("Statistiques");
    stat.afficherStats(Employees,values);
    stat.exec();
}

void MainWindow::on_statRq_clicked()
{
    QString info = ui->tableView_Rq->model()->data(ui->tableView_Rq->model()->index(1,2)).toString();
    QStringList Services;
    Services<<"Urgence"<<"Pediatrie"<<"Secretariat"<<"Cardio"<<"Neurologie"<<"Psychiatrie";
    int freq[Services.length()];
    for (int i = 0; i < Services.length(); ++i) {
        freq[i]=0;
    }
    for (int i = 0; i < ui->tableView_Rq->model()->rowCount(); ++i) {
        info = ui->tableView_Rq->model()->data(ui->tableView_Rq->model()->index(i,4)).toString();
        for(int j=0;j<Services.length();j++)
        {
            if(info==Services.at(j))
                freq[j]+=1;
        }

    }
    ui->lineEdit_Eq->insert(info);

    //values<<"35"<<"45"<<"58";
    DsikStat diskstat;
    diskstat.setModal(true);
    diskstat.setWindowTitle("Statistiques");
    diskstat.afficherStatDisk(Services,freq);
    diskstat.exec();
}
//

void MainWindow::on_english_clicked()
{

     if (ui->english->isChecked())
    {
//C:\Users\khali\Desktop\integration finaleee!!!\E-Health_2A1\Integration_Ehealth
        translator->load("C:\\Users\\khali\\Desktop\\integration finaleee!!!\\E-Health_2A1\\Integration_Ehealth\\english.qm");

        qApp->installTranslator(translator);
        ui->retranslateUi(this);
        QSystemTrayIcon * notifyIcon = new QSystemTrayIcon;
                   notifyIcon-> show ();
                    notifyIcon-> showMessage ( " GESTION PATIENT ET CHAMBRE " , "langue modifié " , QSystemTrayIcon :: Information, 15000 );

    }
}
//AZIZ KAHLOUL
//
//
//
void MainWindow::on_ajouter_vehicule_clicked()
{
    int cin = ui->cin_per->text().toInt();
   QString type= ui->type_per->text();
     QString nom= ui->nom_per->text();
       QString prenom= ui->prenom_per->text();
  personnel p(cin,nom,prenom ,type);
  bool test=p.ajouter();
  if(test)
{ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->setIcon(QIcon("icone.png"));

             notifyIcon->showMessage("GESTION PERSONNEL ","Personnel Ajouté",QSystemTrayIcon::Information,15000);
QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("personnel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un personnel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_supprimer_vehicule_clicked()
{
    int cin = ui->cin_pers->text().toInt();
        bool test=tmppersonnel.supprimer(cin);
        if(test)
        {ui->tabpersonnel->setModel(tmppersonnel.afficher());//refresh
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                   notifyIcon->show();
                   notifyIcon->setIcon(QIcon("icone.png"));

                   notifyIcon->showMessage("GESTION PERSONNEL ","Personnel Supprimé",QSystemTrayIcon::Information,15000);

            QMessageBox::information(nullptr, QObject::tr("Supprimer un personnel"),
                        QObject::tr("personnel supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un personnel"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
             }





void MainWindow::on_ajouter_vehicule_2_clicked()
{
    int idservice = ui->id_service->text().toInt();
    int cinchef= ui->cin_chef->text().toInt();
     QString typeservice= ui->type_service->text();

  service s (idservice,cinchef ,typeservice);
  bool test=s.ajouter();
  if(test)
{ui->tabservice->setModel(tmpservice.afficher());//refresh

      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
             notifyIcon->show();
             notifyIcon->setIcon(QIcon("icone.png"));

             notifyIcon->showMessage("GESTION SERVICE ","Service Ajouté",QSystemTrayIcon::Information,15000);

QMessageBox::information(nullptr, QObject::tr("Ajouter un service"),
                  QObject::tr("service ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un service"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_panne_clicked()
{
    long idservice=ui->id_service_sup->text().toLong();
    bool test=tmpservice.supprimer(idservice);
    if(test)
    {ui->tabservice->setModel(tmpservice.afficher());//refresh

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
               notifyIcon->show();
               notifyIcon->setIcon(QIcon("icone.png"));

               notifyIcon->showMessage("GESTION SERVICE ","Service Supprimé",QSystemTrayIcon::Information,15000);
        QMessageBox::information(nullptr, QObject::tr("Supprimer un service"),
                    QObject::tr(" service supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un service"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


//modifierperso
void MainWindow::on_modifier_vehicule_clicked()
{


            if (ui->modifier_vehicule->isChecked())
            {

                ui->modifier_vehicule->setText("Modifiable");
                QSqlTableModel *tableModel= new QSqlTableModel();
                tableModel->setTable("PERSONNEL");
                tableModel->select();
                ui->tabpersonnel->setModel(tableModel);
            }
            else
            {
                ui->modifier_vehicule->setText("Modifier");
                ui->tabpersonnel->setModel(tmppersonnel.afficher());

                QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                       notifyIcon->show();
                       notifyIcon->setIcon(QIcon("icone.png"));

                       notifyIcon->showMessage("GESTION PERSONNEL ","Personnel Modifié",QSystemTrayIcon::Information,15000);
            }




}
//modifierservice
void MainWindow::on_modifier_service_clicked()
{
    if (ui->modifier_service->isChecked())
    {

        ui->modifier_service->setText("Modifiable");
        QSqlTableModel *tableModel= new QSqlTableModel();
        tableModel->setTable("SERVICE");
        tableModel->select();
        ui->tabservice->setModel(tableModel);

    }
    else
    {
        ui->modifier_service->setText("Modifier");
        ui->tabservice->setModel(tmpservice.afficher());

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
           notifyIcon->show();
           notifyIcon->setIcon(QIcon("icone.png"));

           notifyIcon->showMessage("GESTION SERVICE ","Service Modifié",QSystemTrayIcon::Information,15000);
    }

}
// rechercher

void MainWindow::on_rb_clicked()
{
    QString rech =ui->rechline->text();
        ui->tabpersonnel->setModel(tmppersonnel.rechercher(rech));
}

void MainWindow::on_tri_clicked()
{
    personnel *r = new personnel();
    ui->tabpersonnel->setModel(r->tri());
}
//service
void MainWindow::on_rb_2_clicked()
{
    QString rech =ui->rechline_2->text();
        ui->tabservice->setModel(tmpservice.rechercher(rech));
}

void MainWindow::on_tri_2_clicked()
{
    service *r = new service();
    ui->tabservice->setModel(r->tri());

}

void MainWindow::on_pdf_clicked()
{
            QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tabpersonnel->model()->rowCount();
                    const int columnCount =ui->tabpersonnel->model()->columnCount();

                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("PERSONNEL")
                            <<  "</head>\n"
                            "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                "<img src='C:/Users/AZYZ/Desktop/Azyzprojet/5739.PNG' width='100' height='100'>\n"
                                "<h1>Liste des personnels</h1>"



                                "<table border=1 cellspacing=0 cellpadding=2>\n";


                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tabpersonnel->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tabpersonnel->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tabpersonnel->isColumnHidden(column)) {
                                       QString data = ui->tabpersonnel->model()->data(ui->tabpersonnel->model()->index(row, column)).toString().simplified();
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


void MainWindow::on_play_clicked()
{
    son->play();

}

void MainWindow::on_mute_clicked()
{
    son->stop();

}


void MainWindow::on_mail_2_clicked()
{
    email e;
    e.exec();
}

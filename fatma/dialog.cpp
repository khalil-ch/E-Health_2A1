#include "dialog.h"
#include "ui_dialog.h"
#include <QStackedWidget>
#include <vehicule.h>
#include <equipement.h>
#include <QMessageBox>
#include <QDebug>
#include <QModelIndex>
#include <QSqlQuery>
#include <QPrinter>
#include <QPrintDialog>
#include <QLabel>
#include<QTextDocument>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include<smtp.h>
#include <QMediaPlayer>
#include<qpainter.h>
#include<qpdfwriter.h>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->AffichervehTab->setModel(tmpveh.Affichervehicule("nom"));
    ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("numdeserie"));
    ui->stackedWidget->setCurrentIndex(0);
    ui->categorie->addItem("A");
    ui->categorie->addItem("B");
    ui->categorie->addItem("C");
    ui->categorie_2->addItem("A");
    ui->categorie_2->addItem("B");
    ui->categorie_2->addItem("C");
    ui->desinfectation->addItem("protocole fait");
    ui->desinfectation->addItem("protocole non fait");
    ui->desinfectation_2->addItem("protocole fait");
    ui->desinfectation_2->addItem("protocle non fait");


    flip=0;
    QObject::connect(ui->AfficherTabeqp->horizontalHeader(), SIGNAL(sectionClicked(int)),this, SLOT(SortByHeader(int)));
    QObject::connect(ui->AffichervehTab->horizontalHeader(), SIGNAL(sectionClicked(int)),this, SLOT(SortByHeader2(int)));

}

Dialog::~Dialog()
{
    delete ui;
}
/*-----------------INDEXWORK---------------------*/
void Dialog::mail(QString email,QString sub,QString obj)
{
    qDebug() << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << QSslSocket::supportsSsl();
    qDebug() << QSslSocket::sslLibraryVersionString();

    Smtp* smtp = new Smtp("utopisoftwares.projet@gmail.com", "fatma1231@", "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail(email , sub,obj);
}

void Dialog::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information(nullptr,QObject::tr("utopiasoftwares mailing !"),QObject::tr("Un email a ete envoye !\n"));
    else
        QMessageBox::information(nullptr,QObject::tr("utopiasoftwares mailing !"),QObject::tr("couldn't send mail !\n"));
}

void Dialog::on_music_clicked()
{
      QMediaPlayer * music = new QMediaPlayer();
      connect(music, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
      music->setMedia(QUrl::fromLocalFile("/Users/LENOVO/Documents/ehealthproject/tranquility.mp3"));
      music->play();
      music->setVolume(50);
      music->play();

    ui->stackedWidget->setCurrentIndex(0);
}
//ajouter


void Dialog::on_music_2_clicked()
{
    QMediaPlayer * music = new QMediaPlayer();
    connect(music, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    music->setMedia(QUrl::fromLocalFile("/Users/LENOVO/Documents/ehealthproject/tranquility.mp3"));
    music->play();
    music->setVolume(50);
    music->play();

    ui->stackedWidget->setCurrentIndex(1);

}

void Dialog::on_equipementWin_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_equipementWin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}




void Dialog::on_Ajoutervehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void Dialog::on_Annulerveh_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_Addequipement_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void Dialog::on_Annulereqp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}




/*-----------------DATABASEWORK---------------------*/

void Dialog::on_Add_veh_clicked()
{
    vehicule v;
    if(ui->modeleveh->text().length()!=13)
    {
        QMessageBox msgBox;
        msgBox.setText("modele Invalide!");
        msgBox.exec();
    }
    else{
            v.setnom(ui->nom->text());
            v.setcategorie(ui->categorie->currentText());
            v.setmodele(ui->modeleveh->text());
            v.setdesinfectation(ui->desinfectation->currentText());
            v.setdescription(ui->DESC->text());
            if(v.Ajoutervehicule())
            {
                ui->AffichervehTab->setModel(tmpveh.Affichervehicule("nom"));
                QMessageBox msgBox;
                msgBox.setText("Ajout Avec Success!");
                msgBox.exec();
                ui->stackedWidget->setCurrentIndex(0);
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Echec! Champ(s) Manquant(s)!");
                msgBox.exec();
                ui->stackedWidget->setCurrentIndex(0);
            }
    }
}


void Dialog::on_Addeqp_clicked()
{
    equipement e;
    if(ui->numdeserie->text().length()!=10)
    {
        QMessageBox msgBox;
        msgBox.setText("numdeserie Invalide!");
        msgBox.exec();
    }
    else
    {
        e.setnumdeserie(ui->numdeserie->text());
        e.setnom(ui->nomeqp->text());
        e.setmodele(ui->MODELE->text());
        e.settype(ui->type->text());
        e.setcondition(ui->condition->text());
        e.setdescription(ui->descequipement->text());
        if(e.Ajouterequipement())
        {
            ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("numdeserie"));
            QMessageBox msgBox;
            msgBox.setText("Ajout Avec Success!");
            msgBox.exec();
            ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Echec! Champ(s) Manquant(s)!");
            msgBox.exec();
            ui->stackedWidget->setCurrentIndex(1);
        }

    }

}








void Dialog::on_vehSearch_clicked()
{

    QModelIndexList selection = ui->AffichervehTab->selectionModel()->selectedRows(0);

    if (!selection.empty()) {

        QModelIndex idIndex = selection.at(0);
        QString id = idIndex.data().toString();
        ui->nom_2->setText(id);
        ui->stackedWidget->setCurrentIndex(6);

    }
}


void Dialog::on_vehsearch_3_clicked()
{
        ui->AffichervehTab->setModel(tmpveh.Affichervehicule("NOM"));



}

void Dialog::on_Supprimervehicule_clicked()
{


    QModelIndexList selection = ui->AffichervehTab->selectionModel()->selectedRows(0);

    if (!selection.empty()) {

        QModelIndex idIndex = selection.at(0);
        QString id = idIndex.data().toString();
    if(tmpveh.Supprimervehicule(id))
           {
        ui->AffichervehTab->setModel(tmpveh.Affichervehicule("NOM"));
        QMessageBox msgBox;
        msgBox.setText("Suppression avec Success!");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Echec de Suppression! ");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(0);
        }
    }
}


void Dialog::on_Annulerveh_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_Add_veh_2_clicked()
{
    vehicule v;
            v.setnom(ui->vehSearch->text());
            v.setcategorie(ui->categorie_2->currentText());
            v.setmodele(ui->modeleveh_2->text());
            v.setdesinfectation(ui->desinfectation_2->currentText());
            v.setdescription(ui->DESC_2->text());
            if(v.modifiervehicule(ui->vehSearch->text()))
            {
                ui->AffichervehTab->setModel(tmpveh.Affichervehicule("NOM"));
                QMessageBox msgBox;
                msgBox.setText("Modification Avec Success!");
                msgBox.exec();
                ui->stackedWidget->setCurrentIndex(0);
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Echec! Champ(s) Manquant(s)!");
                msgBox.exec();
                ui->stackedWidget->setCurrentIndex(0);
            }
}








void Dialog::on_nomveh_textChanged(const QString &arg1)
{
    if (arg1=="")
        ui->AffichervehTab->setModel(tmpveh.Affichervehicule("NOM"));
   else
       this->ui->AffichervehTab->setModel(tmpveh.Searchvehicule(arg1));
}







/*--------------------------------------*/

void Dialog::on_Searcheqp_clicked()

{
    QModelIndexList selection = ui->AfficherTabeqp->selectionModel()->selectedRows(0);

    if (!selection.empty()) {

        QModelIndex idIndex = selection.at(0);
        QString id = idIndex.data().toString();
        ui->numdeserie_2->setText(id);
       ui->stackedWidget->setCurrentIndex(8);
    }
}

void Dialog::on_Searcheqp_3_clicked()
{
        ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NUMDESERIE"));
}

void Dialog::on_DELCAR_clicked()
{


    QModelIndexList selection = ui->AfficherTabeqp->selectionModel()->selectedRows(0);

    if (!selection.empty()) {

        QModelIndex idIndex = selection.at(0);
        QString mat = idIndex.data().toString();

    if(tmpeqp.Supprimerequipement(mat))
           {
        ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NUMDESERIE"));
        QMessageBox msgBox;
        msgBox.setText("Suppression avec Success!");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Echec de Suppression! ");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(1);
        }
    }
}





void Dialog::on_Annulereqp_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}




void Dialog::on_Addeqp_2_clicked()
{
    equipement e;


        e.setnumdeserie(ui->Searcheqpnum->text());
        e.setnom(ui->nomeqp_2->text());
        e.setmodele(ui->MODELE_2->text());
        e.settype(ui->type_2->text());
        e.setcondition(ui->condition_2->text());
        e.setdescription(ui->descequipement_2->text());



        if(e.modifierequipement(ui->Searcheqpnum->text()))
        {
            ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NUMDESERIE"));
            QMessageBox msgBox;
            msgBox.setText("Modification Avec Success!");
            msgBox.exec();
            ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("Echec! Champ(s) Manquant(s)!");
            msgBox.exec();
            ui->stackedWidget->setCurrentIndex(1);
        }

    }


 void Dialog::on_Searcheqpnum_textChanged(const QString &arg1)
{
    if (arg1=="")
        ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NUMDESERIE"));
   else
       this->ui->AfficherTabeqp->setModel(tmpeqp.Searchequipement(arg1));

}

 void Dialog::on_Mail_clicked()
 {

     mail("fatmalina1231@gmail.com","fatma1231","this is the bodi");
 }


void Dialog::SortByHeader(int logicalIndex)
{

    switch (logicalIndex) {
        case 0:
            if(flip==0)
            {
                flip++;
                ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NUMDESERIE ASC"));

            }
            else
            {
                flip--;
                ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NUMDESERIE DESC"));
            }

        break;
        case 1:
        if(flip==0)
        {
            flip++;
            ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NOM ASC"));
        }
        else
        {
            flip--;
            ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("NOM DESC"));
        }
        break;
        case 2:
        if(flip==0)
        {
            flip++;
           ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("TYPE ASC"));
        }
        else
        {
            flip--;
             ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("TYPE DESC"));
        }
        break;
        case 3:
        if(flip==0)
        {
            flip++;
            ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("CONDITION ASC"));
        }
        else
        {
            flip--;
            ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("CONDITION DESC"));
        }
            break;
        case 4:
        if(flip==0)
        {
            flip++;
          ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("MODELE ASC"));
        }
        else
        {
            flip--;
             ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("MODELE DESC"));
        }
            break;
        case 5:
        if(flip==0)
        {
            flip++;
            ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("DESCRIPTION ASC"));
        }
        else
        {
            flip--;
             ui->AfficherTabeqp->setModel(tmpeqp.Afficherequipement("DESCRIPTION DESC"));
        }
            break;

}


}


void Dialog::SortByHeader2(int logicalIndex)
{

    switch (logicalIndex) {
        case 0:
            if(flip==0)
            {
                flip++;
                ui->AffichervehTab->setModel(tmpveh.Affichervehicule("NOM ASC"));

            }
            else
            {
                flip--;
               ui->AffichervehTab->setModel(tmpveh.Affichervehicule("NOM DESC"));
            }

        break;
        case 1:
        if(flip==0)
        {
            flip++;
           ui->AffichervehTab->setModel(tmpveh.Affichervehicule("CATEGORIE ASC"));
        }
        else
        {
            flip--;
            ui->AffichervehTab->setModel(tmpveh.Affichervehicule("CATEGORIE DESC"));
        }
        break;
        case 2:
        if(flip==0)
        {
            flip++;
            ui->AffichervehTab->setModel(tmpveh.Affichervehicule("MODELE ASC"));
        }
        else
        {
            flip--;
           ui->AffichervehTab->setModel(tmpveh.Affichervehicule("MODELE DESC"));
        }
        break;

        case 3:
        if(flip==0)
        {
            flip++;
            ui->AffichervehTab->setModel(tmpveh.Affichervehicule("DESINFECTATION ASC"));
        }
        else
        {
            flip--;
            ui->AffichervehTab->setModel(tmpveh.Affichervehicule("DESINFECTATION DESC"));
        }
            break;

        case 4:
        if(flip==0)
        {
            flip++;
            ui->AffichervehTab->setModel(tmpveh.Affichervehicule("DESCRIPTION ASC"));
        }
        else
        {
            flip--;
            ui->AffichervehTab->setModel(tmpveh.Affichervehicule("DESCRIPTION DESC"));
        }
            break;


    }
    }





void Dialog::on_export_3_clicked()
{
    {
        {
            QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->AffichervehTab->model()->rowCount();
                const int columnCount =ui->AffichervehTab->model()->columnCount();
                out << "<h2 align=left> UTOPIA SOFTWARES  </h2>";
                out << "<h2 align=right> EHEALTH APPLICATION </h2>";

                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("EQUIPEMENT")
                        <<  "</head>\n"
                        "<body bgcolor=lightpink link=#5000A0>\n"

                            "<h1>Liste des vehicules</h1>"



                            "<table border=1 cellspacing=0 cellpadding=2>\n";


                // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->AfficherTabeqp->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->AfficherTabeqp->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->AfficherTabeqp->isColumnHidden(column)) {
                                       QString data = ui->AfficherTabeqp->model()->data(ui->AfficherTabeqp->model()->index(row, column)).toString().simplified();
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







}
}
void Dialog::on_export_4_clicked()
{
    {
        QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->AffichervehTab->model()->rowCount();
            const int columnCount =ui->AffichervehTab->model()->columnCount();
            out << "<h2 align=left> EHEALTH APPLICATION  </h2>";
            out << "<h2 align=right> UTOPIA SOFTWARES </h2>";

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("VEHICULE")
                    <<  "</head>\n"
                    "<body bgcolor=lightpink link=#5000A0>\n"

                        "<h1>Liste des vehicules</h1>"



                        "<table border=1 cellspacing=0 cellpadding=2>\n";


            // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->AffichervehTab->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->AffichervehTab->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->AffichervehTab->isColumnHidden(column)) {
                                   QString data = ui->AffichervehTab->model()->data(ui->AffichervehTab->model()->index(row, column)).toString().simplified();
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
}

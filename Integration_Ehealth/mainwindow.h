#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlTableModel>
#include "medicament.h"
#include "fournisseur.h"
#include "patient.h"
#include "chambre.h"
#include "soundsetting.h"
#include "arduino.h"
#include <QMainWindow>
#include <QStatusBar>
#include <QString>
#include <QTranslator>
#include "personnel.h"
#include "service.h"
#include "smtp.h"
//
#include "vehicule.h"
#include "equipement.h"
#include "requette.h"
#include"equipemaintenance.h"
#include <QUrl>
#include <QPdfWriter>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QPropertyAnimation>
#include <QFileDialog>
#include <QSound>
//
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
int led,alert,messageboxactive;
private slots:

void update_label();

    void on_resetmed_clicked();


    void on_ajoutmed_clicked();

    void on_rechmed_clicked();

    void on_statsmed_clicked();

    void on_modifmed_clicked();

    void on_suppmed_clicked();

    void on_excelmed_clicked();

    void on_trierfour_clicked();

    void on_resetfour_clicked();

    void on_ajoutfour_clicked();

    void on_pdffour_clicked();

    void on_modiffour_clicked();

    void on_suppfour_clicked();

    void on_Login_clicked();

    void on_pushButtonAjoutP_clicked();

    void on_pushButton_updatepatient_clicked();

    void on_pushButton_suppP_clicked();

    void on_pushButton_ajoutchambre_clicked();

    void on_pushButton_upatechambre_clicked();

    void on_pushButton_suppchambre_clicked();

    void on_pushButton_rechpatient_clicked();

    void on_pushButton_rechchambre_clicked();

    void on_checkBox_rechercheage_clicked();

    void on_checkBoxchambre_clicked();

    void on_pushButton_PDFchambre_clicked();

    void on_pushButton_pdff_clicked();

    void on_pushButton_Exelchambre_clicked();

    void on_pushButton_ExcelP_clicked();

    void on_pushButton_affichertoutP_clicked();

    void on_pushButton_afficherchambre_clicked();

    void on_AjouterReq_clicked();

    void on_ActualiserReq_clicked();

    void on_DeleteReq_clicked();

    void on_ModifReq_clicked();

    void on_tableView_Rq_doubleClicked(const QModelIndex &index);

    void on_RechercheReq_clicked();

    void on_FiltrerReqSv_currentIndexChanged(const QString &arg1);

    void on_TrierReq_currentIndexChanged(const QString &arg1);

    void on_ExtraiareReq_clicked();

    void on_AjouterEq_clicked();

    void on_ActualiserEq_clicked();

    void on_RechercheEq_clicked();

    void on_ModifEq_clicked();

    void on_DelEq_clicked();

    void on_TrierEq_currentIndexChanged(const QString &arg1);

    void on_FiltrerEq_currentIndexChanged(const QString &arg1);

    void on_tableView_Eq_doubleClicked(const QModelIndex &index);

    void on_ExtraireEq_clicked();

    void on_statEq_clicked();

    void on_statRq_clicked();

    void on_english_clicked();

    void on_ajouter_vehicule_clicked();

    void on_supprimer_vehicule_clicked();

    void on_modifier_vehicule_clicked();

    void on_ajouter_vehicule_2_clicked();

    void on_supprimer_panne_clicked();


    void on_modifier_service_clicked();

    void on_rb_clicked();

    void on_tri_clicked();

    void on_rb_2_clicked();

    void on_tri_2_clicked();

    void on_pdf_clicked();



    void on_play_clicked();

    void on_mute_clicked();

    void on_mail_2_clicked();
    //arduino
         void update_label_aziz();
         void update_label_khalil();
         //finarduino

         void on_AcceptArd_clicked();

         void on_RefuseArd_clicked();

         void on_resetlogin_clicked();

         void on_tradangaziz_clicked();

         void on_tradang2_clicked();

         void on_excelaziz_clicked();

         void on_Add_veh_clicked();

         void on_Add_veh_2_clicked();

         void on_vehsearch_3_clicked();

         void on_export_3_clicked();

         void on_vehSearch_clicked();

         void on_Supprimervehicule_clicked();

         void on_Addeqp_clicked();

         void on_Addeqp_2_clicked();

         void on_Searcheqp_3_clicked();


         void on_export_4_clicked();

         void on_DELCAR_clicked();

         void on_actionChange_Theme_triggered();

         void on_Next_clicked();

         void on_Previous_clicked();

         void on_actionSound_Settings_triggered();

         void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    Medicament temp;
    fournisseur tempo;
      patient tmpPatient;
      chambre tmpChambre;

     QString heartRateBPM="";
         QTranslator *translator=new QTranslator;
     //
     Requette requettetmp;
     EquipeMaintenance equipetmp;
     QPropertyAnimation* animation;
     QPropertyAnimation* animation2;
     int indexpage;
     bool AdminAccess;
     //
     vehicule tmpveh;
     equipement tmpeqp;
     int flip;
     //
     personnel tmppersonnel;
     service tmpservice;
     QSound *son;
     //arduino
       QByteArray data;
       QByteArray xdata;
      arduino A;
      QString uid;
      //arduino khalil
      /*
            arduino A;
            bool test=false;
            QString myid;*/

};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlTableModel>
#include "medicament.h"
#include "fournisseur.h"
#include "patient.h"
#include "chambre.h"
#include "arduino.h"
#include <QMainWindow>
#include <QStatusBar>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    Medicament temp;
    fournisseur tempo;
      patient tmpPatient;
      chambre tmpChambre;
      QByteArray data;
     QString heartRateBPM="";

      arduino A;
};
#endif // MAINWINDOW_H

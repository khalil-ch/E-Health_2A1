#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "patient.h"
#include "chambre.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>

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
    void on_pushButtonAjoutP_clicked();

    void on_pushButton_suppP_clicked();

    void on_pushButton_ajoutchambre_clicked();

    void on_pushButton_suppchambre_clicked();

    void on_pushButton_updatepatient_clicked();

    void on_pushButton_upatechambre_clicked();

    void on_pushButton_rechchambre_clicked();

    void on_pushButton_rechpatient_clicked();

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
    patient tmpPatient;
    chambre tmpChambre;
    QPropertyAnimation *contract_animation;
    QPropertyAnimation *expand_animation;
};
#endif // MAINWINDOW_H

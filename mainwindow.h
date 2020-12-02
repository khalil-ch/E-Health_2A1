#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "personnel.h"
#include "service.h"
#include "smtp.h"
#include <QString>
#include <QSqlTableModel>
#include <QSqlQueryModel>

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
    void on_ajouter_vehicule_clicked();

    void on_supprimer_vehicule_clicked();

    void on_modifier_vehicule_clicked();

   // void on_chercher_vehicule_clicked();

    //void on_trier1_vehicule_clicked();

    //void on_trier2_vehicule_clicked();

    void on_ajouter_vehicule_2_clicked();

    void on_supprimer_panne_clicked();

   // void on_modifier_panne_clicked();

   // void on_chercher_panne_clicked();

    //void on_trier_panne1_clicked();

    //void on_trier_panne2_clicked();
    //void sendMail();
    //void mailSent(QString);

   //void on_supprimer_vehicule_3_clicked();

    void on_modifier_service_clicked();

    void on_rb_clicked();

    void on_tri_clicked();

    void on_rb_2_clicked();

    void on_tri_2_clicked();

    void on_pdf_clicked();

    void on_mail_clicked();

private:
    Ui::MainWindow *ui;
    personnel tmppersonnel;
    service tmpservice;
};
#endif // MAINWINDOW_H

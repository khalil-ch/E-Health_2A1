#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <vehicule.h>
#include <equipement.h>
#include <QObject>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int flip;
private slots:

    void on_equipementWin_2_clicked();

    void on_equipementWin_clicked();

    void on_Ajoutervehicule_clicked();

    void on_Annulerveh_clicked();

    void on_Addequipement_clicked();

    void on_Annulereqp_clicked();

    void on_Add_veh_clicked();

    void on_Addeqp_clicked();

    void on_vehSearch_clicked();

    void on_vehsearch_3_clicked();
    void on_Add_veh_2_clicked();

    void on_Supprimervehicule_clicked();

    void on_Annulerveh_2_clicked();

    void on_nomveh_textChanged(const QString &arg1);

    void on_Searcheqp_clicked();

    void on_Searcheqp_3_clicked();

    void on_DELCAR_clicked();

    void on_Annulereqp_2_clicked();

    void on_Addeqp_2_clicked();

    void on_Searcheqpnum_textChanged(const QString &arg1);

    void SortByHeader(int);

    void SortByHeader2(int);
    void on_export_2_clicked();





    void on_export_3_clicked();

    void on_export_4_clicked();



    void on_Mail_clicked();
        void mail(QString,QString,QString);
        void mailSent(QString);


        void on_music_clicked();

        void on_music_2_clicked();

        void on_pdf_clicked();

private:
    Ui::Dialog *ui;
    vehicule tmpveh;
    equipement tmpeqp;

};

#endif // DIALOG_H

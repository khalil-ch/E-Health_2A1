#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "requette.h"
#include <QMainWindow>
#include"equipemaintenance.h"
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
    void on_AjouterReq_clicked();

    void on_ActualiserReq_clicked();

    void on_DeleteReq_clicked();

    void on_ModifReq_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_RechercheReq_clicked();

    void on_FiltrerReqSv_currentIndexChanged(const QString &arg1);

    void on_AjouterEq_clicked();

    void on_ActualiserEq_clicked();

    void on_RechercheEq_clicked();

    void on_statRq_clicked();

    void on_ModifEq_clicked();

    void on_DelEq_clicked();

    void on_statEq_clicked();

    void on_TrierEq_currentIndexChanged(const QString &arg1);

    void on_TrierReq_currentIndexChanged(const QString &arg1);

    void on_ExtraiareReq_clicked();

private:
    Ui::MainWindow *ui;
    Requette requettetmp;
    EquipeMaintenance equipetmp;
};
#endif // MAINWINDOW_H

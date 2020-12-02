#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "requette.h"
#include <QMainWindow>
#include"equipemaintenance.h"
#include <QUrl>
#include <QPdfWriter>
#ifndef QT_NO_PRINTER
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QPropertyAnimation>
#include <QFileDialog>
#endif
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

    void on_TabReqAndEquipes_currentChanged(int index);

    void on_FiltrerEq_currentIndexChanged(const QString &arg1);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_ExtraireEq_clicked();

    void on_FiltrerReqEtat_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Requette requettetmp;
    EquipeMaintenance equipetmp;
    QPropertyAnimation* animation;
    QPropertyAnimation* animation2;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "chefservice.h"

#include <QMainWindow>

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
    void on_pushButton_13_clicked();//enregistrer

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_4_released();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Chefservice chefservicetmp;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlTableModel>
#include "medicament.h"

#include <QMainWindow>
#include <QStatusBar>
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
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    Medicament temp;
};
#endif // MAINWINDOW_H

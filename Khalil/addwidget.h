#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QDialog>

namespace Ui {
class AddWidget;
}

class AddWidget : public QDialog
{
    Q_OBJECT

public:
    explicit AddWidget(QWidget *parent = nullptr);
    ~AddWidget();

private slots:
    void on_pushButton_13_clicked();

    void on_EnregistrerR_clicked();

    void on_Enregistrer_clicked();

private:
    Ui::AddWidget *ui;
};

#endif // ADDWIDGET_H

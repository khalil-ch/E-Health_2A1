#ifndef MODW_H
#define MODW_H
#include <QString>
#include <QDialog>

namespace Ui {
class ModW;
}

class ModW : public QDialog
{
    Q_OBJECT

public:
    explicit ModW(QWidget *parent = nullptr);
    void SetReftmp(QString ref){reftmp=ref;}
    QString GetReftmp(){return reftmp;}
    ~ModW();

private slots:
    void on_ConfirmModif_clicked();

    void on_CancelModif_clicked();

private:
    Ui::ModW *ui;
    QString reftmp;
};

#endif // MODW_H

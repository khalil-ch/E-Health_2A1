#ifndef WIDMOD2_H
#define WIDMOD2_H

#include <QDialog>

namespace Ui {
class WidMod2;
}

class WidMod2 : public QDialog
{
    Q_OBJECT

public:
    explicit WidMod2(QWidget *parent = nullptr);
    void setIDeqtmp(QString chaine){ideqtmp=chaine;}
    QString getIDeqtmp(){return ideqtmp;}
    ~WidMod2();

private slots:
    void on_ConfirmerModEq_clicked();

    void on_AnnulerModEq_clicked();

private:
    Ui::WidMod2 *ui;
    QString ideqtmp;
};

#endif // WIDMOD2_H

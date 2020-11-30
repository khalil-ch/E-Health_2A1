#ifndef MODIFWIDGET_H
#define MODIFWIDGET_H

#include <QDialog>
#include <QString>

namespace Ui {
class ModifWidget;
}

class ModifWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ModifWidget(QWidget *parent = nullptr);
        void setIDtmp(QString tmp){idtmp=tmp;}
        QString getIDtmp(){return idtmp;}
    ~ModifWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    QString idtmp;
    Ui::ModifWidget *ui;
};

#endif // MODIFWIDGET_H

#ifndef MODIFWIDGET_H
#define MODIFWIDGET_H

#include <QDialog>

namespace Ui {
class ModifWidget;
}

class ModifWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ModifWidget(QWidget *parent = nullptr);
    ~ModifWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ModifWidget *ui;
};

#endif // MODIFWIDGET_H

#ifndef WIDADD2_H
#define WIDADD2_H

#include <QDialog>

namespace Ui {
class WidAdd2;
}

class WidAdd2 : public QDialog
{
    Q_OBJECT

public:
    explicit WidAdd2(QWidget *parent = nullptr);
    ~WidAdd2();

private slots:
    void on_AddEqConfirm_clicked();

    void on_AddEqCancel_clicked();

private:
    Ui::WidAdd2 *ui;
};

#endif // WIDADD2_H

#ifndef ABOUTWID_H
#define ABOUTWID_H

#include <QDialog>

namespace Ui {
class Aboutwid;
}

class Aboutwid : public QDialog
{
    Q_OBJECT

public:
    explicit Aboutwid(QWidget *parent = nullptr);
    ~Aboutwid();

private slots:
    void on_Close_clicked();

private:
    Ui::Aboutwid *ui;
};

#endif // ABOUTWID_H

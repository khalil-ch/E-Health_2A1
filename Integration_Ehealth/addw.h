#ifndef ADDW_H
#define ADDW_H

#include <QDialog>

namespace Ui {
class AddW;
}

class AddW : public QDialog
{
    Q_OBJECT

public:
    explicit AddW(QWidget *parent = nullptr);
    ~AddW();

private:
    Ui::AddW *ui;
};

#endif // ADDW_H

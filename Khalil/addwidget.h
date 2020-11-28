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

private:
    Ui::AddWidget *ui;
};

#endif // ADDWIDGET_H

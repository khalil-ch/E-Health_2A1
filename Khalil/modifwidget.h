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

private:
    Ui::ModifWidget *ui;
};

#endif // MODIFWIDGET_H

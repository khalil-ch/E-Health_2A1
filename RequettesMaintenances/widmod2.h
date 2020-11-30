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
    ~WidMod2();

private:
    Ui::WidMod2 *ui;
};

#endif // WIDMOD2_H

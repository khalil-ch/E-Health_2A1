#ifndef STATCHART_H
#define STATCHART_H
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include <QDialog>
#include <QGridLayout>
// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class StatChart;
}

class StatChart : public QDialog
{
    Q_OBJECT

public:
    explicit StatChart(QWidget *parent = nullptr);
    void afficherStats(QStringList* list,QStringList* nbrq);
    ~StatChart();

private:
    Ui::StatChart *ui;
    QStringList* EquipId,nbrq;
    int i;
};

#endif // STATCHART_H

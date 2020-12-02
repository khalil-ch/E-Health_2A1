#include "statchart.h"
#include "ui_statchart.h"

// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE

StatChart::StatChart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatChart)
{
    ui->setupUi(this);
}

StatChart::~StatChart()
{
    delete ui;
}
void StatChart::afficherStats(QStringList* list,QStringList* nbrq)
{

    EquipId=list;
    QGridLayout* mainLayout = new QGridLayout;
    QVector <QBarSet*> set;
    for (int i = 0; i < EquipId->length(); ++i) {
     set.push_back( new QBarSet(EquipId->at(i)));
    }
    //conversion des requetes de qstring a int
    QString val;
    int bbb[EquipId->length()];
    for (int i = 0; i < EquipId->length(); ++i) {
        val=nbrq->at(i);
        bbb[i]=val.toInt();
    }
    //
    // Assign values for each bar
    int valeur=0;
    for (int i = 0; i < EquipId->length(); ++i) {
        valeur=bbb[i];
    *(set.at(i)) << valeur<<valeur;
    }

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();
    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    //houni n7ot for
    for (int i = 0;i < set.length(); i++) {
     series->append(set[i]);//append les individus a la serie
    }
    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Requettes par Annee");
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList total;
    total<<"2019"<<"2020";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(total);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);//legende
    chart->legend()->setAlignment(Qt::AlignBottom);//legend aligned

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0x4BE5D8));//0xE5E14B
    pal.setColor(QPalette::WindowText, QRgb(0x4BE5D8));

    // Apply palette changes to the application
    qApp->setPalette(pal);
    mainLayout->addWidget(chartView,0,0);
    setLayout(mainLayout);
}

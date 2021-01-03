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
void StatChart::afficherStats(QStringList list,QStringList nbrq)
{
    /*
    // Assign names to the set of bars used
    QBarSet *set0 = new QBarSet("Altuve");
    QBarSet *set1 = new QBarSet("Martinez");
    QBarSet *set2 = new QBarSet("Segura");
    QBarSet *set3 = new QBarSet("Simmons");
    QBarSet *set4 = new QBarSet("Trout");

    // Assign values for each bar
    *set0 << 283 << 341 << 313 << 338 << 346 << 335;
    *set1 << 250 << 315 << 282 << 307 << 303 << 330;
    *set2 << 294 << 246 << 257 << 319 << 300 << 325;
    *set3 << 248 << 244 << 265 << 281 << 278 << 313;
    *set4 << 323 << 287 << 299 << 315 << 306 << 313;

    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Batting Avg by Year");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();

    // 1. Bar chart
    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart
    // chart->setAxisY(axis, series);

    // Define where the legend is displayed
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xffffff));
    pal.setColor(QPalette::WindowText, QRgb(0x404044));

    // Apply palette changes to the application
    qApp->setPalette(pal);
    mainLayout->addWidget(chartView,0,0);
    setLayout(mainLayout);*/

    EquipId=list;
    QGridLayout* mainLayout = new QGridLayout;
    QVector <QBarSet*> set;
    for (int i = 0; i < EquipId.length(); ++i) {
     set.push_back( new QBarSet(EquipId.at(i)));
    }
    //conversion des requetes de qstring a int
    QString val;
    int ConverToInt[EquipId.length()];
    for (int i = 0; i < EquipId.length(); ++i) {
        val=nbrq.at(i);
        ConverToInt[i]=val.toInt();
    }
    //
    // Assign values for each bar
    int valeur=1;
    for (int i = 0; i < EquipId.length(); ++i) {
        valeur=ConverToInt[i];
    *(set.at(i)) <<ConverToInt[i];//<<valeur;
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
    total<<"Total";

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
    pal.setColor(QPalette::Window, QRgb(0x5C5C5C));//0xE5E14B
    pal.setColor(QPalette::WindowText, QRgb(0x4BE5D8));

    // Apply palette changes to the application
    qApp->setPalette(pal);
    mainLayout->addWidget(chartView,0,0);
    setLayout(mainLayout);
}

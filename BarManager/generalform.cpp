#include "generalform.h"
#include "ui_generalform.h"

GeneralForm::GeneralForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GeneralForm)
{
    ui->setupUi(this);

    connect(&_uiHall, SIGNAL(getArraySize ()), this, SLOT(sendArraySize ()));
    connect(&_uiHall, SIGNAL(getObjTable (unsigned int &)), this, SLOT(sendObjTable (unsigned int &)));
    connect(&_uiAddTable, SIGNAL(sendNewTable (std::vector<Table::Info>)), this, SLOT(getObjTable (std::vector<Table::Info>)));
    connect(&_uiAddTable, SIGNAL(getRangeSize ()), this, SLOT(sendRangeSize ()));
    connect(&_uiAddTable, SIGNAL(getItemInfoRange (unsigned int)), this, SLOT(sendItemInfoRange (unsigned int)));

    _uiRangeForm.loadMenu();
    updateCharts();
}

GeneralForm::~GeneralForm()
{
    _log.closeLogFile();
    delete ui;
}

void GeneralForm::getObjTable(std::vector<Table::Info> newTable)
{
    Table newTable2;
    newTable2.setVector(newTable);
    _tableArrea.push_back(newTable2);
    _uiAddTable.hide();
    updateCharts();
}

void GeneralForm::deleteTable(unsigned int index)
{//Закрываем стол
    _tableArrea.erase(_tableArrea.begin() + index);
}

void GeneralForm::showAllTable()
{//Выводит все столы
    for(unsigned int i = 0; i < _tableArrea.size(); i++)
    {
        ;
    }
}

unsigned int GeneralForm::sendArraySize()
{
    return _tableArrea.size();
}

std::vector<Table::Info> GeneralForm::sendObjTable(unsigned int &index)
{
    return _tableArrea[index].getObjInfo();
}

void GeneralForm::on_AddTablePushButton_clicked()
{
    _uiAddTable.loadMenuTable();
    _uiAddTable.show();
}

void GeneralForm::on_ShowAllTablesPushButton_clicked()
{
    _uiHall.update();
    _uiHall.show();
}

void GeneralForm::on_MenuPushButton_clicked()
{
    _uiRangeForm.update();
    _uiRangeForm.show();
}

unsigned int GeneralForm::sendRangeSize()
{
    return _uiRangeForm.getSize();
}

RangeForm::Info GeneralForm::sendItemInfoRange(unsigned int index)
{
    return _uiRangeForm.getMenuItem(index);
}

void GeneralForm::on_HelpPushButton_clicked()
{
    _uiHelper.show();
}

void GeneralForm::updateCharts()
{
    ui->ChartsHorizontalLayout->removeWidget(chartView);

    int maxseumm = 0;
    QtCharts::QBarSet *set;
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    std::vector<Table::Info> objTempInfo;

    for(unsigned int j = 0; j < _tableArrea.size(); j++)
    {
        int summFromTable = 0;
        set = new QtCharts::QBarSet(QString::number(j));
        objTempInfo = _tableArrea[j].getObjInfo();

        for(unsigned int l = 0; l < objTempInfo.size(); l++)
        {
            summFromTable += objTempInfo[l].price;
        }

        maxseumm = std::max(maxseumm, summFromTable);

        *set << summFromTable;
        series->append(set);
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("График цен открытых столов");
    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    QStringList categories;
    categories << "id стола";
    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setRange(0, maxseumm);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->ChartsHorizontalLayout->addWidget(chartView);
}

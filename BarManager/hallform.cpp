#include "hallform.h"
#include "ui_hallform.h"

HallForm::HallForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HallForm)
{
    ui->setupUi(this);
}

HallForm::~HallForm()
{
    _log.closeLogFile();
    delete ui;
}

void HallForm::updateTableInfo(std::vector<Info> objTable)
{
    ui->InfoAboutTabletableWidget->clear();

    QStringList headers = {"Название", "Цена"};

    ui->InfoAboutTabletableWidget->setRowCount(objTable.size());
    ui->InfoAboutTabletableWidget->setColumnCount(2);

    ui->InfoAboutTabletableWidget->setShowGrid(true);
    ui->InfoAboutTabletableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->InfoAboutTabletableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->InfoAboutTabletableWidget->setHorizontalHeaderLabels(headers);
    ui->InfoAboutTabletableWidget->horizontalHeader()->setStretchLastSection(true);

    _log.writeLog(std::to_string(objTable[0].price) + objTable[0].name);

    for(unsigned int i = 0; i < objTable.size(); i++)
    {
        ui->InfoAboutTabletableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(objTable[i].name)));
        ui->InfoAboutTabletableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(objTable[i].price)));
    }
}

void HallForm::update()
{
    ui->TableslistWidget->clear();

    unsigned int sizeArray = emit getArraySize();

    _log.writeLog(std::to_string(sizeArray));

    for(unsigned int i = 0; i < sizeArray; i++)
    {
        ui->TableslistWidget->addItem(QString::number(i));
    }
}

void HallForm::on_TableslistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    unsigned int index = item->text().toUInt();

    updateTableInfo(emit getObjTable(index));
}

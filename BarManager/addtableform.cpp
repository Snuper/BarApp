#include "addtableform.h"
#include "ui_addtableform.h"

AddTableForm::AddTableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTableForm)
{
    ui->setupUi(this);
}

AddTableForm::~AddTableForm()
{
    _log.closeLogFile();
    delete ui;
}

void AddTableForm::on_OkPushButton_clicked()
{
    emit sendNewTable(itemP);
    ui->AddedMenuTableWidget->clear();
    itemP.clear();
}

void AddTableForm::updateAddTableWidget(std::string name, int is)
{
    Table::Info temp;
    temp.name = name;
    temp.price = is;

    itemP.push_back(temp);

    ui->AddedMenuTableWidget->clear();

    QStringList headers = {"Название", "Цена"};

    ui->AddedMenuTableWidget->setRowCount(itemP.size());
    ui->AddedMenuTableWidget->setColumnCount(2);

    ui->AddedMenuTableWidget->setShowGrid(true);
    ui->AddedMenuTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->AddedMenuTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AddedMenuTableWidget->setHorizontalHeaderLabels(headers);
    ui->AddedMenuTableWidget->horizontalHeader()->setStretchLastSection(true);

    for(unsigned int i = 0; i < itemP.size(); i++)
    {
        ui->AddedMenuTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(itemP[i].name)));
        ui->AddedMenuTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(itemP[i].price)));
    }
}

void AddTableForm::loadMenuTable()
{
    unsigned int size = emit getRangeSize();

    _log.writeLog(std::to_string(size));

    ui->MenuTableWidget->clear();

    QStringList headers = {"Название", "Цена"};

    ui->MenuTableWidget->setRowCount(size);
    ui->MenuTableWidget->setColumnCount(2);

    ui->MenuTableWidget->setShowGrid(true);
    ui->MenuTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->MenuTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->MenuTableWidget->setHorizontalHeaderLabels(headers);
    ui->MenuTableWidget->horizontalHeader()->setStretchLastSection(true);

    for(unsigned int i = 0; i < size; i++)
    {
        Table::Info itemRange = emit getItemInfoRange(i);
        _log.writeLog(itemRange.name + std::to_string(itemRange.price));
        ui->MenuTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(itemRange.name)));
        ui->MenuTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(itemRange.price)));
    }
}

void AddTableForm::on_MenuTableWidget_cellDoubleClicked(int row, int column)
{
    std::string name = ui->MenuTableWidget->item(row, 0)->text().toStdString();
    int i = ui->MenuTableWidget->item(row, 1)->text().toInt();

    updateAddTableWidget(name, i);
}

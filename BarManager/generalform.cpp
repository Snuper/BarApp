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

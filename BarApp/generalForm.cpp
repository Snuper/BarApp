#include "generalForm.h"
#include "ui_general.h"

GeneralForm::GeneralForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::General)
{
    ui->setupUi(this);

    connect(&_uiHall, SIGNAL(getArraySize ()), this, SLOT(sendArraySize ()));
    connect(&_uiHall, SIGNAL(getObjTable (unsigned int &)), this, SLOT(sendObjTable (unsigned int &)));
}

GeneralForm::~GeneralForm()
{
    delete ui;
}

void GeneralForm::openTable()
{//Открываем стол
    Table newTable;
    _tableArrea.push_back(newTable);
}

void GeneralForm::deleteTable(unsigned int index)
{//Закрываем стол
    _tableArrea.erase(_tableArrea.begin() + index);
}


void GeneralForm::on_openTablePushButton_clicked()
{
    openTable();
}

void GeneralForm::showAllTable()
{//Выводит все столы
    for(unsigned int i = 0; i < _tableArrea.size(); i++)
    {
        ;
    }
}

void GeneralForm::on_showAllTablePushButton_clicked()
{//Открываем новую форму, для показа всех столов
    _uiHall.show();
}

unsigned int GeneralForm::sendArraySize()
{
    return _tableArrea.size();
}

std::vector<Table::Info>& GeneralForm::sendObjTable(unsigned int &index)
{
    return _tableArrea[index].getObjInfo();
}

#include "table.h"

Table::Table()
{

}

int Table::over()
{//Выставляет счет
    unsigned int proceeds = 0;

    for(unsigned int i = 0; i < _item.size(); i++)
    {
        proceeds += _item[i].price;
    }

    return proceeds;
}

void Table::addItem(Info ItemDB)
{
    _item.push_back(ItemDB);
}

std::vector<Table::Info>& Table::getObjInfo()
{//Возвращаем ссылку на структуру стола
    return _item;
}

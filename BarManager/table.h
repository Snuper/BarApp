#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <iostream>

class Table
{
public:
    Table();

    struct Info
    {//Структура хранения данных
        std::string name;
        unsigned int price;
    };

    int over();
    void addItem(Info);
    std::vector<Info>& getObjInfo();
    void setVector(std::vector<Info>);

private:
    std::vector<Info>_item;
};

#endif // TABLE_H

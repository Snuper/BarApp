#include "rangeform.h"
#include "ui_rangeform.h"

RangeForm::RangeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RangeForm)
{
    ui->setupUi(this);
}

RangeForm::~RangeForm()
{
    delete ui;
}

RangeForm::Info RangeForm::getMenuItem(unsigned int index)
{
    return _menuArray[index];
}

void RangeForm::update()
{
    ui->RangeTableWidget->clear();

    QStringList headers = {"Название", "Цена"};

    ui->RangeTableWidget->setRowCount(_menuArray.size());
    ui->RangeTableWidget->setColumnCount(2);

    ui->RangeTableWidget->setShowGrid(true);
    ui->RangeTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->RangeTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->RangeTableWidget->setHorizontalHeaderLabels(headers);
    ui->RangeTableWidget->horizontalHeader()->setStretchLastSection(true);

    for(unsigned int i = 0; i < _menuArray.size(); i++)
    {
        ui->RangeTableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(_menuArray[i].name)));
        ui->RangeTableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(_menuArray[i].price)));
    }
}

void RangeForm::on_AddPushButton_clicked()
{
    Info newItem;
    newItem.name = ui->NameLineEdit->text().toStdString();
    newItem.price = ui->PriceLineEdit->text().toInt();

    _menuArray.push_back(newItem);

    update();
    saveMenu();
}

unsigned int RangeForm::getSize()
{
    return _menuArray.size();
}

void RangeForm::loadMenu()
{//десирилизация
    std::ifstream in("Data");
    Info tempLoad;
    std::string temp;

    if(in.is_open())
    {
        getline(in, temp);
        saveSize = atoi(temp.c_str());

        for(int i = 1; i < saveSize * 2 + 1; i++)
        {//Считываем блоки
            if(i % 2 != 0)
            {
                getline(in, temp);
                tempLoad.name = temp;
            }
            else
            {
                getline(in, temp);
                tempLoad.price = atoi(temp.c_str());
                _menuArray.push_back(tempLoad);//добавляем в вектор заполненный объект
            }
        }
    }

    in.close();
}

void RangeForm::saveMenu()
{//серилизация
    std::ofstream out("Data"); //Открвыем бинарник

    int saveSize = _menuArray.size();//сохраняем размер вектора

    if(out.is_open())
    {
        out << std::to_string(saveSize) << std::endl;

        for(unsigned int i = 0; i < _menuArray.size(); i++) //Записываем блоки
        {//по одному друг за другом
            out << _menuArray[i].name << std::endl;
            out << std::to_string(_menuArray[i].price) << std::endl;
        }
    }

    out.close();
}

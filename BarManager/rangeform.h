#ifndef RANGEFORM_H
#define RANGEFORM_H

#include <QWidget>
#include <fstream>
#include <string>
#include <iostream>

namespace Ui {
class RangeForm;
}

class RangeForm : public QWidget
{
    Q_OBJECT

public:
    explicit RangeForm(QWidget *parent = nullptr);
    ~RangeForm();

    struct Info
    {//Структура хранения данных
        std::string name;
        unsigned int price;
    };

    unsigned int getSize();

    Info getMenuItem(unsigned int);
    void update();
    void saveMenu();
    void loadMenu();

private slots:
    void on_AddPushButton_clicked();

private:
    Ui::RangeForm *ui;
    int saveSize;
    std::vector<Info>_menuArray;
};

#endif // RANGEFORM_H

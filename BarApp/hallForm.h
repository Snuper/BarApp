#ifndef HALL_H
#define HALL_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class HallForm;
}

class HallForm : public QWidget
{
    Q_OBJECT

public:
    explicit HallForm(QWidget *parent = nullptr);
    ~HallForm();

    struct Info
    {//Структура хранения данных
        std::string name;
        unsigned int price;
    };

signals:
    unsigned int getArraySize();
    std::vector<HallForm::Info>& getObjTable(unsigned int &);

private slots:
    void on_TableslistWidget_itemDoubleClicked(QListWidgetItem*);

private:
    Ui::HallForm *ui;
};

#endif // HALL_H

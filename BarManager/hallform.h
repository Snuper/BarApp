#ifndef HALLFORM_H
#define HALLFORM_H

#include <QWidget>
#include <QListWidgetItem>
#include <logger.h>

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

    void update();

signals:
    unsigned int getArraySize();
    std::vector<HallForm::Info> getObjTable(unsigned int &);

private slots:
    void on_TableslistWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::HallForm *ui;

    Logger _log;

    void updateTableInfo(std::vector<Info>);
};

#endif // HALLFORM_H

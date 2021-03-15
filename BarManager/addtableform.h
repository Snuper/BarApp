#ifndef ADDTABLEFORM_H
#define ADDTABLEFORM_H

#include <QWidget>
#include <QTableWidgetItem>
#include "table.h"
#include "logger.h"

namespace Ui {
class AddTableForm;
}

class AddTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddTableForm(QWidget *parent = nullptr);
    ~AddTableForm();

    struct Info
    {//Структура хранения данных
        std::string name;
        unsigned int price;
    };

    void loadMenuTable();
    std::vector<Table::Info>itemP;


signals:
    unsigned int getRangeSize();
    Table::Info getItemInfoRange (unsigned int);
    void sendNewTable(std::vector<Table::Info>);

private slots:
    void on_OkPushButton_clicked();
    void on_MenuTableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::AddTableForm *ui;

    void updateAddTableWidget(std::string, int);
    Logger _log;
};

#endif // ADDTABLEFORM_H

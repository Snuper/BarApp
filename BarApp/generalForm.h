#ifndef GENERAL_H
#define GENERAL_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include "logger.h"
#include "table.h"
#include "addtableform.h"
#include "hallForm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class General; }
QT_END_NAMESPACE

class GeneralForm : public QMainWindow
{
    Q_OBJECT

public:
    GeneralForm(QWidget *parent = nullptr);
    ~GeneralForm();

private slots:
    unsigned int sendArraySize();
    std::vector<Table::Info>& sendObjTable(unsigned int &);

    void on_openTablePushButton_clicked();
    void on_showAllTablePushButton_clicked();

private:
    Logger _log; //Логгер

    //Функции для работы со столами
        std::vector<Table>_tableArrea;

        void openTable();
        void deleteTable(unsigned int);
        void showAllTable();
    //

    //Формы
        HallForm _uiHall;
        AddTableForm _uiAddTable;
    //

    Ui::General *ui;
};
#endif // GENERAL_H

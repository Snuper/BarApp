#ifndef GENERALFORM_H
#define GENERALFORM_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include "logger.h"
#include "table.h"
#include "addtableform.h"
#include "hallform.h"
#include "rangeform.h"
#include "helperform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GeneralForm; }
QT_END_NAMESPACE

class GeneralForm : public QMainWindow
{
    Q_OBJECT

public:
    GeneralForm(QWidget *parent = nullptr);
    ~GeneralForm();

private slots:
    unsigned int sendArraySize();
    std::vector<Table::Info> sendObjTable(unsigned int &);
    void getObjTable(std::vector<Table::Info>);

    void on_AddTablePushButton_clicked();
    void on_ShowAllTablesPushButton_clicked();

    void on_MenuPushButton_clicked();

    unsigned int sendRangeSize();
    RangeForm::Info sendItemInfoRange(unsigned int);

    void on_HelpPushButton_clicked();

private:
    Logger _log; //Логгер
    RangeForm _rangeMenu;

    //Функции для работы со столами
        std::vector<Table>_tableArrea;

        void openTable();
        void deleteTable(unsigned int);
        void showAllTable();
    //

    //Формы
        HallForm _uiHall;
        AddTableForm _uiAddTable;
        RangeForm _uiRangeForm;
        HelperForm _uiHelper;
    //

    Ui::GeneralForm *ui;
};
#endif // GENERALFORM_H

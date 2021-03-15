#include "hallForm.h"
#include "ui_hall.h"

HallForm::HallForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HallForm)
{
    ui->setupUi(this);

    unsigned int sizeArray = emit getArraySize();

    for(unsigned int i = 0; i < sizeArray; i++)
    {
        ui->TableslistWidget->addItem(QString::number(i));
    }
}

HallForm::~HallForm()
{
    delete ui;
}

void HallForm::on_TableslistWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ;
}

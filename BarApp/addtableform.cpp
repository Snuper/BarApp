#include "addtableform.h"
#include "ui_addtableform.h"

AddTableForm::AddTableForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddTableForm)
{
    ui->setupUi(this);
}

AddTableForm::~AddTableForm()
{
    delete ui;
}

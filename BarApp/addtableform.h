#ifndef ADDTABLEFORM_H
#define ADDTABLEFORM_H

#include <QWidget>

namespace Ui {
class AddTableForm;
}

class AddTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddTableForm(QWidget *parent = nullptr);
    ~AddTableForm();

private:
    Ui::AddTableForm *ui;
};

#endif // ADDTABLEFORM_H

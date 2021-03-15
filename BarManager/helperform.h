#ifndef HELPERFORM_H
#define HELPERFORM_H

#include <QWidget>
#include <QFile>
#include <QObject>

namespace Ui {
class HelperForm;
}

class HelperForm : public QWidget
{
    Q_OBJECT

public:
    explicit HelperForm(QWidget *parent = nullptr);
    ~HelperForm();

private slots:
    void onAnchorClicked(const QUrl &link);

private:
    Ui::HelperForm *ui;
};

#endif // HELPERFORM_H

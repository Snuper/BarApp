#include "generalform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GeneralForm w;
    w.show();
    return a.exec();
}

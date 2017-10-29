#include "gauss.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gauss w;
    w.show();

    return a.exec();
}

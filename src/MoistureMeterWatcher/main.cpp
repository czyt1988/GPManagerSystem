#include "MoistureMeterWatcher.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MoistureMeterWatcher w;
    w.show();
    return a.exec();
}

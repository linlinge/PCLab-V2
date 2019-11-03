#include "pcviewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PCViewer w;
    w.show();

    return a.exec();
}

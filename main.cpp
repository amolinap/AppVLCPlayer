#include "vlc/VLC_source/VLCVideoWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VLCVideoWidget w("");
    w.show();

    return a.exec();
}



#ifndef QTVLCAPP_H
#define QTVLCAPP_H

#include <QWidget>
#include <QByteArray>
#include <QDebug>
#include <QtSerialPort>

#define APP_NAME "SPARTAAM Vector NAV"
#define APP_COMPANYNAME "Secretaría de Marina"
#define APP_VERSION "v1.1"
#define APP_BUILT_ON "OCTOBER 2016"

namespace Ui {
class QtVLCApp;
}

class QtVLCApp : public QWidget
{
    Q_OBJECT

public:
    explicit QtVLCApp(QWidget *parent = 0);
    ~QtVLCApp();

public slots:
    void receiveYPR(double y, double p, double r);
    void connectSerial();
    void disconnectSerial();

private:
    Ui::QtVLCApp *ui;
    bool connectVN;
};

#endif // QTVECTORNAV_H

#include "QtVLCApp.h"
#include "ui_QtVLCApp.h"

QtVLCApp::QtVLCApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QtVLCApp),
    connectVN(false)
{
    ui->setupUi(this);

    ui->cbSerialPort->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cbSerialPort->addItem(info.portName());
    }

    connect(ui->btSerial, SIGNAL(clicked()), this, SLOT(connectSerial()));

    setWindowTitle(APP_NAME);
    ui->lbVersion->setText(APP_VERSION);
    ui->lbBuild->setText(APP_BUILT_ON);
}

QtVLCApp::~QtVLCApp()
{
    delete ui;
}

void QtVLCApp::receiveYPR(double y, double p, double r)
{
    QString str;

    ui->tbYaw->setText(str.sprintf("%1").arg(y, 3, 'f', 6, '0'));
    ui->tbPitch->setText(str.sprintf("%1").arg(p, 3, 'f', 6, '0'));
    ui->tbRoll->setText(str.sprintf("%1").arg(r, 3, 'f', 6, '0'));
}

void QtVLCApp::connectSerial()
{
    if(!connectVN)
    {
        //if(vn100->connectVN((char* const)ui->cbSerialPort->currentText().toUtf8().constData(), ui->cbBaudRate->currentText().toInt()))
        {
            ui->btSerial->setText("Disconnect");
            connectVN = true;
        }
    }
    else
    {
        //if(vn100->disconnectVN())
        {
            ui->btSerial->setText("Connect");
            connectVN = false;
        }
    }
}

void QtVLCApp::disconnectSerial()
{

}

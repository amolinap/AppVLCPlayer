/**
 * @file
 *   @brief Definition of class VLCVideoWidget
 *
 *   @author Alejandro Molina Pulido <am.alex09@gmail.com>
 *
 */

#include "VLCVideoWidget.h"
#include "ui_VLCVideoWidget.h"

#define qtu( i ) ((i).toUtf8().constData())

VLCVideoWidget::VLCVideoWidget(const QString path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VLCVideoWidget)
{
    ui->setupUi(this);

    pathVideo = path;

    vlcDisplay = new VLCDisplay(pathVideo, this);

    createControlsVLC();
}

void VLCVideoWidget::createControlsVLC()
{
    vlDisplay = new QVBoxLayout(this);
    vlDisplay->setContentsMargins(2,2,2,2);
    vlDisplay->addWidget(vlcDisplay);

    hlButtonOptions = new QHBoxLayout();
    btPlay = new QPushButton(QIcon(":/images/Play.png"), tr(""), this);
    btPlay->setToolTip(tr("Play"));
    connect(btPlay, SIGNAL(clicked()), this, SLOT(play()));

    btStop = new QPushButton(QIcon(":/images/Stop.png"), tr(""), this);
    btStop->setToolTip(tr("Stop"));
    connect(btStop, SIGNAL(clicked()), this, SLOT(stop()));

    btOpenRTSP = new QPushButton(QIcon(":/images/Server.png"), tr(""), this);
    btOpenRTSP->setToolTip(tr("Open Network"));
    connect(btOpenRTSP, SIGNAL(clicked()), this, SLOT(openRTSP()));

    btOpenFile = new QPushButton(QIcon(":/images/Open.png"), tr(""), this);
    btOpenFile->setToolTip(tr("Open File"));
    connect(btOpenFile, SIGNAL(clicked()), this, SLOT(openFile()));

    btRecord = new QPushButton(QIcon(":/images/Radio.png"), "", this);
    btRecord->setToolTip(tr("Emitir"));
    connect(btRecord, SIGNAL(clicked()), vlcDisplay, SLOT(startEmitVideo()));

    hlButtonOptions->setAlignment(Qt::AlignLeft);
    hlButtonOptions->addWidget(btPlay);
    hlButtonOptions->addWidget(btStop);
    hlButtonOptions->addWidget(btOpenRTSP);
    hlButtonOptions->addWidget(btOpenFile);
    hlButtonOptions->addWidget(btRecord);

    vlDisplay->addLayout(hlButtonOptions);

    QHBoxLayout *hlLabelMedia = new QHBoxLayout();
    lbTittle = new QLabel(this);
    lbTittle->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    lbTittle->setText("");
    hlLabelMedia->addWidget(lbTittle);
    vlDisplay->addLayout(hlLabelMedia);

    ui->groupBox->setLayout(vlDisplay);

    setWindowIcon(QIcon(":/images/spartaam.ico"));
    setWindowTitle(tr("ISR Video"));
}

void VLCVideoWidget::play()
{
    if(!lbTittle->text().isEmpty())
    {
        vlcDisplay->playVideo();
    }
}

void VLCVideoWidget::stop()
{
    vlcDisplay->stopVideo();
    vlcDisplay->stopEmitVideo();
}

VLCVideoWidget::~VLCVideoWidget()
{
    delete vlcDisplay;

    delete ui;
}

void VLCVideoWidget::openRTSP()
{
    bool ok;

    QStringList url = (QStringList() << tr("rtsp://192.168.1.90:554/axis-media/media.amp") << tr("http://192.168.1.90/mjpg/video.mjpg"));

    //QString text = QInputDialog::getText(this, tr("Ingrese la URL"), tr("URL RTSP Axis:"), QLineEdit::Normal, tr("rtsp://192.168.1.90:554/axis-media/media.amp"), &ok);
    QString text = QInputDialog::getItem(this, tr("Ingrese la URL"), tr("URL RTSP Axis:"), url, 0, true, &ok);

    if (ok && !text.isEmpty())
    {
        addURL(text, true);
    }
}

void VLCVideoWidget::openFile()
{
    QString fileName(QFileDialog::getOpenFileName(this, tr("Abrir"), pathVideo, tr("Archivo de video (*.avi | *.mp4 | *.mpg | *.mov)")));

    if (fileName.isEmpty())
        return;

    addURL(fileName, false);
}

void VLCVideoWidget::addURL(const QString url, bool isRTSP)
{
    vlcDisplay->addURL(url, isRTSP);
    lbTittle->setText(url);

    if(!isRTSP)
    {
        QDir dirInfo(url);
        lbTittle->setText("../"+dirInfo.dirName());
        lbTittle->setToolTip(url);
    }
}

void VLCVideoWidget::record()
{
    //vlcDisplay->recordVideo();
    vlcDisplay->startEmitVideo();
}

void VLCVideoWidget::changePATH(const QString &path)
{
    this->pathVideo = path;
    vlcDisplay->changePATH(path);
}

void VLCVideoWidget::setVideoURL(const QString &url)
{
    vlcDisplay->setVideoURL(url);
}

QString VLCVideoWidget::getVideoURL()
{
    return vlcDisplay->getVideoURL();
}

#include "VLCDisplay.h"
#include "ui_VLCDisplay.h"

#define qtu( i ) ((i).toUtf8().constData())

VLCDisplay::VLCDisplay(const QString path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VLCDisplay)
{
    ui->setupUi(this);

    isRecord = false;
    isPlay = false;
    isRTSP = false;
    url = "";
    pathVideo = "";
    videoURL = "rtp://IP_ADDRESS";
    startTime=-1;

    createInstanceVLC("");
    mediaPlayer = libvlc_media_player_new_from_media(media);
    libvlc_media_player_set_hwnd(mediaPlayer, (void*)ui->frame->winId());

    processRecord.setProcessChannelMode(QProcess::MergedChannels);
    closeEmit.setProcessChannelMode(QProcess::MergedChannels);
}

VLCDisplay::~VLCDisplay()
{
    delete ui;
}

void VLCDisplay::playVideo()
{
    if(libvlc_media_player_is_playing(mediaPlayer)==1)
    {
        libvlc_media_player_pause(mediaPlayer);
        isPlay = false;
    }
    else
    {
        libvlc_media_player_play(mediaPlayer);
        isPlay = true;
    }
}

void VLCDisplay::stopVideo()
{
    if(libvlc_media_player_is_playing(mediaPlayer)==1)
    {
        libvlc_media_player_stop(mediaPlayer);
        isPlay = false;
    }
}

void VLCDisplay::addURL(const QString url, bool isRTSP)
{
    stopVideo();

    if(instance)
    {
        libvlc_release(instance);
    }

    QString newUrl = url;

    newUrl.replace('/', "\\" );
    createInstanceVLC(qtu(newUrl));
    libvlc_media_player_set_media(mediaPlayer, media);

    this->url = newUrl;
    this->isRTSP = isRTSP;
}

void VLCDisplay::createInstanceVLC(const QString url)
{
    const char *optionDeVlc[] = {
        "--plugin-path","C:\\VideoLAN\\VLC"
    };

    instance = libvlc_new(sizeof(optionDeVlc) / sizeof(optionDeVlc[0]),optionDeVlc);
    media = libvlc_media_new_path(instance, qtu(url));
}

void VLCDisplay::changePATH(const QString &path)
{
    this->pathVideo = path;
}

quint64 VLCDisplay::getGroundTimeNow()
{
    QDateTime time = QDateTime::currentDateTime();
    time = time.toUTC();
    quint64 milliseconds = time.toTime_t() * static_cast<quint64>(1000);
    return static_cast<quint64>(milliseconds + time.time().msec());
}

void VLCDisplay::resizeEvent(QResizeEvent *size)
{
    //    vlcMacWidget->resize(size->size().width(), size->size().height());
}

void VLCDisplay::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
}

void VLCDisplay::startEmitVideo()
{
    QStringList arguments;
    //arguments<<"/C"<<"ipconfig";

    //arguments<<"/C"<<"C:\\VideoLAN\\VLC\\vlc.exe -I dummy -vvv C:\\SPARTAAM_Nocturna_1minuto.mp4 --sout=#transcode{vcodec=h264,vb=0,scale=0,acodec=mp4a,ab=128,channels=2,samplerate=4100}:udp{dst=201.168.1.115:12003} :no-sout-rtp-sap :no-sout-standard-sap :ttl=1 :sout-keep";
    arguments<<"/C"<<"C:\\VideoLAN\\VLC\\vlc.exe -I dummy -vvv "+url+" --sout=#transcode{vcodec=h264,vb=0,scale=0,acodec=mp4a,ab=128,channels=2,samplerate=2000}:rtp{mux=ts,dst=239.255.1.12} :no-sout-rtp-sap :no-sout-standard-sap :ttl=1 :sout-keep --loop";

    qDebug()<<arguments;

    processRecord.start("cmd.exe", arguments);
    int noProcess = processRecord.pid()->dwThreadId;
    processRecord.waitForFinished();
}

void VLCDisplay::stopEmitVideo()
{
    QStringList arguments;
    arguments<<"/C"<<"TASKKILL /IM vlc.exe /F";

    closeEmit.start("cmd.exe", arguments);
    closeEmit.waitForFinished();
    closeEmit.close();
}

void VLCDisplay::setVideoURL(const QString &url)
{
    videoURL = url;
}

QString VLCDisplay::getVideoURL()
{
    return videoURL;
}

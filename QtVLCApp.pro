#-------------------------------------------------
#
# Project created by QtCreator 2014-06-02T11:54:08
#
#-------------------------------------------------

QT       += core gui network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(vlc/VLC.pri)

TARGET = VideoPlayer
TEMPLATE = app
BASEDIR = $$PWD
TARGETDIR = $$OUT_PWD
BUILDDIR = $$TARGETDIR/build
OBJECTS_DIR = $$BUILDDIR/obj
MOC_DIR = $$BUILDDIR/moc
UI_DIR = $$BUILDDIR/generated

SOURCES += main.cpp

QMAKE_POST_LINK += echo "Copying files"
QTDIR = C:\\Qt\\Qt5.3.2\\5.3\\mingw482_32\\bin

CONFIG(debug, debug|release) {
    message("Debug...")

QMAKE_POST_LINK += && xcopy \"$$QTDIR\\..\\plugins\\platforms\" \"$$TARGETDIR\\debug\\platforms\\\" /S /E /Y

QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\icudt52.dll\" \"$$TARGETDIR\\debug\\icudt52.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\icuin52.dll\" \"$$TARGETDIR\\debug\\icuin52.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\icuuc52.dll\" \"$$TARGETDIR\\debug\\icuuc52.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\libgcc_s_dw2-1.dll\" \"$$TARGETDIR\\debug\\libgcc_s_dw2-1.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\libstdc++-6.dll\" \"$$TARGETDIR\debug\libstdc++-6.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\libwinpthread-1.dll\" \"$$TARGETDIR\\debug\\libwinpthread-1.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Cored.dll\" \"$$TARGETDIR\\debug\\Qt5Cored.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Guid.dll\" \"$$TARGETDIR\\debug\\Qt5Guid.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Networkd.dll\" \"$$TARGETDIR\\debug\\Qt5Networkd.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5OpenGLd.dll\" \"$$TARGETDIR\\debug\\Qt5OpenGLd.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5SerialPortd.dll\" \"$$TARGETDIR\\debug\\Qt5SerialPortd.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Widgetsd.dll\" \"$$TARGETDIR\\debug\\Qt5Widgetsd.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Sqld.dll\" \"$$TARGETDIR\\debug\\Qt5Sqld.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Svgd.dll\" \"$$TARGETDIR\\debug\\Qt5Svgd.dll\"

}

CONFIG(release, debug|release) {
    message("Release...")

QMAKE_POST_LINK += && xcopy \"$$QTDIR\\..\\plugins\\platforms\" \"$$TARGETDIR\\release\\platforms\\\" /S /E /Y

QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\icudt52.dll\" \"$$TARGETDIR\\release\\icudt52.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\icuin52.dll\" \"$$TARGETDIR\\release\\icuin52.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\icuuc52.dll\" \"$$TARGETDIR\\release\\icuuc52.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\libgcc_s_dw2-1.dll\" \"$$TARGETDIR\\release\\libgcc_s_dw2-1.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\libstdc++-6.dll\" \"$$TARGETDIR\release\libstdc++-6.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\libwinpthread-1.dll\" \"$$TARGETDIR\\release\\libwinpthread-1.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Core.dll\" \"$$TARGETDIR\\release\\Qt5Core.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Gui.dll\" \"$$TARGETDIR\\release\\Qt5Gui.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Network.dll\" \"$$TARGETDIR\\release\\Qt5Network.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5OpenGL.dll\" \"$$TARGETDIR\\release\\Qt5OpenGL.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5SerialPort.dll\" \"$$TARGETDIR\\release\\Qt5SerialPort.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Widgets.dll\" \"$$TARGETDIR\\release\\Qt5Widgets.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Sql.dll\" \"$$TARGETDIR\\release\\Qt5Sql.dll\"
QMAKE_POST_LINK += && copy /Y \"$$QTDIR\\Qt5Svg.dll\" \"$$TARGETDIR\\release\\Qt5Svg.dll\"

}

RESOURCES += \
    Resources.qrc

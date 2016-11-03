#VLC_SOURCE = vlc/VLC_source

INCLUDEPATH += vlc/VLC_source/vlc/

HEADERS += vlc/VLC_source/VLCVideoWidget.h \
    vlc/VLC_source/VLCDisplay.h


SOURCES += vlc/VLC_source/VLCVideoWidget.cpp \
    vlc/VLC_source/VLCDisplay.cpp


FORMS += vlc/VLC_source/VLCVideoWidget.ui \
    vlc/VLC_source/VLCDisplay.ui

#LIBS += -L"C:/Program Files/VideoLAN/VLC" \# if you are at windows os
LIBS += -L"C:/VideoLAN/VLC" \# if you are at windows os


LIBS += -lvlc

#INCLUDEPATH += /Applications/VLC.app/Contents/MacOS/include \

#LIBS += /Applications/VLC.app/Contents/MacOS/lib/libvlc.5.dylib \
#/Applications/VLC.app/Contents/MacOS/lib/libvlccore.dylib \


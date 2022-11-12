









QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fin.cpp \
    game.cpp \
    help.cpp \
    ia.cpp \
    ia2.cpp \
    main.cpp \
    mainwindow.cpp \
    proc.cpp

HEADERS += \
    fin.h \
    game.h \
    help.h \
    ia.h \
    ia2.h \
    mainwindow.h \
    proc.h

FORMS += \
    fin.ui \
    game.ui \
    help.ui \
    ia.ui \
    ia2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

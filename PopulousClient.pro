#-------------------------------------------------
#
# Project created by QtCreator 2014-09-22T02:31:29
#
#-------------------------------------------------

QT       += core gui network xml

android{
QT += androidextras
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PopulousClient
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    irctextformatter.cpp \
    notificationbar.cpp

HEADERS  += dialog.h \
    irctextformatter.h \
    notificationbar.h

FORMS    += dialog.ui

CONFIG += mobility
MOBILITY =

include(libcommuni/src/src.pri)

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS = \
        $$PWD/openssl/libcrypto.so \
        $$PWD/openssl/libssl.so
}

RESOURCES += \
    Resource.qrc

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/src/net/popre/popmmmobile/notification/NotificationBar.java \
    android/AndroidManifest.xml

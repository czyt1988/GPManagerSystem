#-------------------------------------------------
#
# Project created by QtCreator 2020-06-16T19:13:29
#
#-------------------------------------------------
message("")
message("--------------SA-System--------------------------")
message(Qt version: $$[QT_VERSION])
message(Qt is installed in $$[QT_INSTALL_PREFIX])

QT       += core gui
QT += xml
QT += opengl
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DESTDIR = $$PWD/../../bin
TARGET = SAManagerSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        MainWindow.h

FORMS += \
        MainWindow.ui

#3thparty
#{
#QWT
include($$PWD/../3rdParty/qwt/qwt_set.pri)
#}

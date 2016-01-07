#-------------------------------------------------
#
# Project created by QtCreator 2016-01-06T10:32:47
#
#-------------------------------------------------

DEPENDPATH += .
INCLUDEPATH += .
SQLITE_PATH=/usr/local
DEPENDPATH += $$SQLITE_PATH/include
INCLUDEPATH += $$SQLITE_PATH/include
LIBS += -L$$SQLITE_PATH/lib
LIBS += -lsqlite3



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qrcodedecoder-pc4
TEMPLATE = app


SOURCES += main.cpp\
    EditRecord.cpp \
    managementform.cpp \


HEADERS  += \
    EditRecord.h \
    managementform.h \

FORMS    += \
    management.ui \

RESOURCES += \
    background.qrc

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT += core
QT += sql
SOURCES += \
        csv.cpp \
        database.cpp \
        log.cpp \
        login.cpp \
        main.cpp

HEADERS += \
    csv.h \
    database.h \
    log.h \
    login.h


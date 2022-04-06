TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT += core
QT += sql
SOURCES += \
        csv.cpp \
        custom.cpp \
        database.cpp \
        login.cpp \
        main.cpp \
        savedmessages.cpp \
        user.cpp \
        userguide.cpp

HEADERS += \
    csv.h \
    custom.h \
    database.h \
    login.h \
    savedmessages.h \
    user.h \
    userguide.h


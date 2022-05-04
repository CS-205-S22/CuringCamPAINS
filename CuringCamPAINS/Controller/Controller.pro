TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

QT += widgets
QT += core
QT += sql
SOURCES += \
        contact.cpp \
        contactlist.cpp \
        csv.cpp \
        database.cpp \
        log.cpp \
        login.cpp \
        main.cpp \
        savedmessages.cpp \

HEADERS += \
    contact.h \
    contactlist.h \
    csv.h \
    database.h \
    log.h \
    login.h \
    savedmessages.h \



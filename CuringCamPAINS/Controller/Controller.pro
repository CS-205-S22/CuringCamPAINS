TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT += core
QT += sql
SOURCES += \
        contact.cpp \
        contactlist.cpp \
        csv.cpp \
        database.cpp \
        login.cpp \
        main.cpp

HEADERS += \
    contact.h \
    contactlist.h \
    csv.h \
    database.h \
    login.h


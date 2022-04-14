TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

QT += core
QT += sql

LIBS += -pthread

#include "contacttest.h"
#include "contactlisttest.h"
#include "csvtest.h"
#include "customtest.h"
#include "databasetest.h"
#include "logtest.h"
#include "logintest.h"


SOURCES += ../../gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../../gtest \
                ../../gtest/googletest \
                ../../gtest/googletest/include \
                ../../gtest/googletest/include/gtest

SOURCES += \
        contacttest.cpp \
        contactlisttest.cpp \
        csvtest.cpp \
        customtest.cpp \
        databasetest.cpp \
        logintest.cpp \
        logtest.cpp \
        savedmessagestest.cpp \
        main.cpp \
        ../Controller/contact.cpp \
        ../Controller/contactlist.cpp \
        ../Controller/csv.cpp \
        ../Controller/custom.cpp \
        ../Controller/database.cpp \
        ../Controller/login.cpp \
        ../Controller/log.cpp \
        ../Controller/savedmessages.cpp

HEADERS += \
        contactlisttest.h \
        contacttest.h \
        csvtest.h \
        customtest.h \
        databasetest.h \
        logintest.h \
        logtest.h \
        savedmessagestest.h \
        ../Controller/contact.h \
        ../Controller/contactlist.h \
        ../Controller/csv.h \
        ../Controller/custom.h \
        ../Controller/database.h \
        ../Controller/login.h \
        ../Controller/log.h \
        ../Controller/savedmessages.h




QT       += core gui

CONFIG += qt

QT += core
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#TARGET = curingCamPAINS
#TEMPLATE = app

SOURCES += \
    admingui.cpp \
    contactsgui.cpp \
    dashboardgui.cpp \
    dynamicbutton.cpp \
    loggui.cpp \
    logingui.cpp \
    main.cpp \
    ../Controller/contactlist.cpp \
    ../Controller/database.cpp \
    ../Controller/login.cpp \
    ../Controller/contact.cpp \
    ../Controller/savedmessages.cpp \
    ../Controller/log.cpp \
    ../Controller/csv.cpp \
    registrationgui.cpp \
    resourcesgui.cpp

HEADERS += \
    admingui.h \
    contactsgui.h \
    ../Controller/contactlist.h \
    ../Controller/database.h \
    ../Controller/contact.h \
    ../Controller/login.h \
    ../Controller/savedmessage.h \
    ..Controller/log.h \
    dashboardgui.h \
    dynamicbutton.h \
    loggui.h \
    logingui.h \
    registrationgui.h \
    ../Controller/csv.h \
    resourcesgui.h

FORMS += \
    admingui.ui \
    contactsgui.ui \
    dashboardgui.ui \
    loggui.ui \
    logingui.ui \
    registrationgui.ui \
    resourcesgui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

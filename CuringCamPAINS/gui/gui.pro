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
    contacts.cpp \
    logingui.cpp \
    main.cpp \
    dashboard.cpp \
    ../Controller/contactlist.cpp \
    ../Controller/database.cpp \
    ../Controller/login.cpp \
    ../Controller/contact.cpp \
    registrationgui.cpp

HEADERS += \
    contacts.h \
    dashboard.h \
    ../Controller/contactlist.h \
    ../Controller/database.h \
    ../Controller/contact.h \
    ../Controller/login.h \
    logingui.h \
    registrationgui.h

FORMS += \
    contacts.ui \
    dashboard.ui \
    logingui.ui \
    registrationgui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

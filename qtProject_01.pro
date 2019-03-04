#-------------------------------------------------
#
# Project created by QtCreator 2019-02-06T16:21:46
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtProject_01
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    identification.cpp \
    dialogajouterpatient.cpp \
    dialogajoutersoigneur.cpp \
    formapropos.cpp \
    controller/verificationcontroller.cpp \
    c_init_bd.cpp \
    model/patient.cpp \
    model/typeparmi.cpp \
    model/consult.cpp \
    model/compte.cpp \
    model/ressource.cpp \
    dao/patientdao.cpp

HEADERS += \
        mainwindow.h \
    identification.h \
    dialogajouterpatient.h \
    dialogajoutersoigneur.h \
    formapropos.h \
    controller/verificationcontroller.h \
    c_init_bd.h \
    model/patient.h \
    model/typeparmi.h \
    model/consult.h \
    model/compte.h \
    model/ressource.h \
    dao/patientdao.h

FORMS += \
        mainwindow.ui \
    identification.ui \
    dialogajouterpatient.ui \
    dialogajoutersoigneur.ui \
    formapropos.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressource.qrc \
    login.qrc \
    icon_menu.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2019-05-06T16:42:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2
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
        capagladiador.cpp \
        capatorres.cpp \
        dibujar.cpp \
        flecha.cpp \
        gladiador.cpp \
        juego.cpp \
        listaflechas.cpp \
        listagladiadores.cpp \
        listanodos.cpp \
        listatorres.cpp \
        main.cpp \
        inicio.cpp \
        nodomatriz.cpp \
        torre.cpp \
        workercaminar.cpp \
        workerdisparar.cpp

HEADERS += \
        capagladiador.h \
        capatorres.h \
        dibujar.h \
        flecha.h \
        gladiador.h \
        inicio.h \
        juego.h \
        listaflechas.h \
        listagladiadores.h \
        listanodos.h \
        listatorres.h \
        nodomatriz.h \
        torre.h \
        workercaminar.h \
        workerdisparar.h

FORMS += \
        inicio.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

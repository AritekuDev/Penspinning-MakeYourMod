#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T16:03:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PenspinningMakeYourMod
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#Programisto! Ten kod został udostępniony na platformie github: https://github.com/AritekuDev/PenspinningMakeYourMod
#Pod licencją MIT. Proszę, nie usuwaj z niego żadnych informacji o realnych autorach Aplikacji, tj Artur Koniec - Ariteku.pl
#Proszę cię też by program nie uległ zmianie w więcej niż 30%.
#Kosztował mnie on naprawdę wiele czasu i serca, więc uszanuj to, i zastosuj się proszę do powyższych sentencji.
#Pozdrawiam - Arteq - Ariteku.pl - Pełnoprawny autor Penspinning: Make your Mod
RC_FILE = psmya.rc

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        menowawindow.cpp \
    busterwindow.cpp

HEADERS += \
        mainwindow.h \
        menowawindow.h \
    busterwindow.h

FORMS += \
        mainwindow.ui \
        menowawindow.ui \
    busterwindow.ui

RESOURCES += \
    resources.qrc

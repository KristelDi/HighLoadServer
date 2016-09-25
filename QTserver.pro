QT += core network
QT -= gui

CONFIG += c++11

TARGET = QTserver
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    qsocketthread.cpp

HEADERS += \
    server.h \
    qsocketthread.h

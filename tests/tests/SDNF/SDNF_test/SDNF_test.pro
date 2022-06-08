QT += testlib
QT -= gui

QT += network

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_sdnf_test.cpp \
    ../../../ClientAndWindowsInOne/back_func.cpp \
    ../../../ClientAndWindowsInOne/client.cpp

HEADERS += \
    ../../../ClientAndWindowsInOne/back_func.h \
    ../../../ClientAndWindowsInOne/client.h

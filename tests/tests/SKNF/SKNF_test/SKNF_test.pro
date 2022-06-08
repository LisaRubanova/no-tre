QT += testlib network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_sknf_test.cpp \
    ../../../ClientAndWindowsInOne/back_func.cpp \
    ../../../ClientAndWindowsInOne/client.cpp

HEADERS += \
    ../../../ClientAndWindowsInOne/back_func.h \
    ../../../ClientAndWindowsInOne/client.h

QT += core
QT -= gui

CONFIG += c++11

TARGET = iot-embedded
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += pipeline \
               plugin/interfaces

SOURCES += main.cpp \
    pipeline/onetomanypipeline.cpp \
    plugin/dummyendpoint.cpp

HEADERS += \
    pipeline/datasink.h \
    pipeline/datasource.h \
    pipeline/onetomanypipeline.h \
    pipeline/pipeline.h \
    plugin/interfaces/endpoint.h \
    plugin/dummyendpoint.h \
    worker.h


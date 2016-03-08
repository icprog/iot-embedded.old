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
    plugin/test/testendpoint.cpp \
    plugin/test/testendpointfactory.cpp

HEADERS += \
    pipeline/datasink.h \
    pipeline/datasource.h \
    pipeline/onetomanypipeline.h \
    pipeline/pipeline.h \
    plugin/interfaces/node.h \
    plugin/interfaces/nodefactory.h \
    plugin/test/testendpoint.h \
    plugin/test/testendpointfactory.h \
    plugin/utils/concurrentqueue.h


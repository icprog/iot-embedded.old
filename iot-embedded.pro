QT += core
QT -= gui

CONFIG += c++11

TARGET = iot-embedded
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += pipeline \
               pipeline/utils \
               plugin/interfaces \
               plugin/interfaces/sensor

SOURCES += main.cpp \
    pipeline/onetomanypipeline.cpp \
    plugin/test/testendpoint.cpp \
    plugin/test/testendpointfactory.cpp \
    pipeline/utils/dataitem.cpp \
    plugin/sensor/sensorendpoint.cpp \
    plugin/sensor/sensorprocessor.cpp \
    plugin/sensor/system_telemetry/systemtelemetryprocessor.cpp \
    plugin/sensor/system_telemetry/systemtelemetrysensorfactory.cpp \
    plugin/sensor/system_telemetry/systemdataprovider.cpp \
    core/applicationcontextloader.cpp \
    core/nodecontainer.cpp \
    plugin/rest/RestEndpoint.cpp \
    plugin/rest/RestEndpointFactory.cpp

HEADERS += \
    pipeline/datasink.h \
    pipeline/datasource.h \
    pipeline/onetomanypipeline.h \
    pipeline/pipeline.h \
    plugin/interfaces/node.h \
    plugin/interfaces/nodefactory.h \
    plugin/test/testendpoint.h \
    plugin/test/testendpointfactory.h \
    pipeline/utils/concurrentqueue.h \
    pipeline/utils/dataitem.h \
    plugin/sensor/sensorendpoint.h \
    plugin/sensor/sensorprocessor.h \
    plugin/sensor/system_telemetry/systemtelemetryprocessor.h \
    plugin/sensor/system_telemetry/systemtelemetrysensorfactory.h \
    plugin/sensor/system_telemetry/systemdataprovider.h \
    core/applicationcontextloader.h \
    core/nodecontainer.h \
    plugin/rest/RestEndpoint.h \
    plugin/rest/RestEndpointFactory.h


QT += core
QT -= gui

CONFIG += c++11

TARGET = iot-embedded
CONFIG += console
QT += network
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
    core/applicationcontextloader.cpp \
    core/nodecontainer.cpp \
    plugin/rest/RestEndpoint.cpp \
    plugin/rest/RestEndpointFactory.cpp \
    plugin/sensor/SensorWorker.cpp \
    plugin/sensor/Sensor.cpp \
    plugin/sensor/system_telemetry/TelemetryDataProvider.cpp \
    plugin/sensor/system_telemetry/SystemTelemetryWorker.cpp \
    plugin/sensor/system_telemetry/SystemTelemetrySensorFactory.cpp

HEADERS += \
    plugin/interfaces/SensorNode.h \
    plugin/interfaces/SensorNodeFactory.h \
    plugin/interfaces/BrokerNode.h \
    plugin/interfaces/BrokerNodeFactory.h \
    plugin/interfaces/ConnectivityNode.h \
    plugin/interfaces/ConnectivityNodeFactory.h \
    plugin/interfaces/node.h \
    plugin/interfaces/nodefactory.h \
    plugin/test/testendpoint.h \
    plugin/test/testendpointfactory.h \
    pipeline/utils/concurrentqueue.h \
    pipeline/utils/dataitem.h \
    core/applicationcontextloader.h \
    core/nodecontainer.h \
    plugin/rest/RestEndpoint.h \
    plugin/rest/RestEndpointFactory.h \
    plugin/sensor/SensorWorker.h \
    plugin/sensor/Sensor.h \
    plugin/sensor/system_telemetry/SystemTelemetrySensorFactory.h \
    plugin/sensor/system_telemetry/SystemTelemetryWorker.h \
    plugin/sensor/system_telemetry/TelemetryDataProvider.h


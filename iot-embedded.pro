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
               plugin/interfaces/sensor \
               /usr/include/qt5/QStomp/

SOURCES += main.cpp \
    pipeline/utils/dataitem.cpp \
    plugin/rest/RestEndpoint.cpp \
    plugin/rest/RestEndpointFactory.cpp \
    plugin/sensor/SensorWorker.cpp \
    plugin/sensor/Sensor.cpp \
    plugin/sensor/system_telemetry/TelemetryDataProvider.cpp \
    plugin/sensor/system_telemetry/SystemTelemetryWorker.cpp \
    plugin/sensor/system_telemetry/SystemTelemetrySensorFactory.cpp \
    core/NodeContainer.cpp \
    core/ApplicationContextLoader.cpp \
    plugin/websocket/WebSocketEndpoint.cpp \
    plugin/iot-broker/IotBroker.cpp \
    plugin/iot-broker/IoTBrokerFactory.cpp \
    plugin/iot-broker/JsonMessageFormatter.cpp \
    plugin/iot-broker/StompMessageFormatter.cpp \
    #plugin/iot-broker/QStomp/qstomp.cpp

HEADERS += \
    plugin/interfaces/SensorNode.h \
    plugin/interfaces/SensorNodeFactory.h \
    plugin/interfaces/BrokerNode.h \
    plugin/interfaces/BrokerNodeFactory.h \
    plugin/interfaces/ConnectivityNode.h \
    plugin/interfaces/ConnectivityNodeFactory.h \
    pipeline/utils/dataitem.h \
    plugin/rest/RestEndpoint.h \
    plugin/rest/RestEndpointFactory.h \
    plugin/sensor/SensorWorker.h \
    plugin/sensor/Sensor.h \
    plugin/sensor/system_telemetry/SystemTelemetrySensorFactory.h \
    plugin/sensor/system_telemetry/SystemTelemetryWorker.h \
    plugin/sensor/system_telemetry/TelemetryDataProvider.h \
    core/NodeContainer.h \
    core/ApplicationContextLoader.h \
    plugin/websocket/WebSocketEndpoint.h \
    plugin/iot-broker/IotBroker.h \
    plugin/iot-broker/IoTBrokerFactory.h \
    plugin/iot-broker/MessageFormattingStrategy.h \
    plugin/iot-broker/JsonMessageFormatter.h \
    plugin/iot-broker/StompMessageFormatter.h \
    #plugin/iot-broker/QStomp/qstomp.h \
    #plugin/iot-broker/QStomp/qstomp_global.h \
    #plugin/iot-broker/QStomp/qstomp_p.h

QMAKE_CXXFLAGS_WARN_OFF += -Wunused-parameter

LIBS += -lqstomp

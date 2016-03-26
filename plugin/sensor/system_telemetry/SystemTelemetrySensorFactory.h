#ifndef SYSTEMTELEMETRYPROCESSORFACTORY_H
#define SYSTEMTELEMETRYPROCESSORFACTORY_H

#include <QObject>
#include <SensorNodeFactory.h>
#include <SensorNode.h>

#include "plugin/sensor/Sensor.h"
#include "plugin/sensor/SensorWorker.h"
#include "plugin/sensor/system_telemetry/SystemTelemetryWorker.h"

class SystemTelemetrySensorFactory : public QObject, public SensorNodeFactory
{
    Q_OBJECT
//    Q_PLUGIN_METADATA(IID "com.jmssolutions.iot.embedded.plugin.node.SystemTelemetrySensor")
    Q_INTERFACES(NodeFactory)

public:
    explicit SystemTelemetrySensorFactory(QObject *parent = 0);
    SensorNode *createNode(const QString &node_name) override final;
    QByteArray getNodeClassName() override final;

signals:

public slots:

private:
    const static QString TAG;
};

#endif // SYSTEMTELEMETRYPROCESSORFACTORY_H

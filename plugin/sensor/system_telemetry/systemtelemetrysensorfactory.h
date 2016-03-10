#ifndef SYSTEMTELEMETRYPROCESSORFACTORY_H
#define SYSTEMTELEMETRYPROCESSORFACTORY_H

#include <QObject>
#include "nodefactory.h"
#include "node.h"
#include "plugin/sensor/sensorendpoint.h"
#include "plugin/sensor/sensorprocessor.h"
#include "plugin/sensor/system_telemetry/systemtelemetryprocessor.h"

class SystemTelemetrySensorFactory : public QObject, public NodeFactory
{
    Q_OBJECT
//    Q_PLUGIN_METADATA(IID "com.jmssolutions.iot.embedded.plugin.node.SystemTelemetrySensor")
    Q_INTERFACES(NodeFactory)

public:
    explicit SystemTelemetrySensorFactory(QObject *parent = 0);
    Node *createNode() override final;

signals:

public slots:

private:
    const static QString TAG;
};

#endif // SYSTEMTELEMETRYPROCESSORFACTORY_H

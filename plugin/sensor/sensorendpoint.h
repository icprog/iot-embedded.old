#ifndef SENSORENDPOINT_H
#define SENSORENDPOINT_H
#include <QObject>

#include "node.h"


class SensorEndpoint : public Node
{
    Q_OBJECT
public:
    SensorEndpoint();
};

#endif // SENSORENDPOINT_H

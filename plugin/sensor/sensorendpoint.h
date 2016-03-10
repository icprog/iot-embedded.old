#ifndef SENSORENDPOINT_H
#define SENSORENDPOINT_H
#include <QObject>

#include "node.h"
#include "sensorprocessor.h"


class SensorEndpoint : public Node
{
    Q_OBJECT
public:
    explicit SensorEndpoint(QObject *parent = 0);

    void setProcessor(SensorProcessor *processor);

public slots:
    virtual void onDataReceived(ConcurrentQueue<DataItem>* queue);

private:
    SensorProcessor* processor_;
};

#endif // SENSORENDPOINT_H

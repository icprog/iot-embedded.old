#include "sensorendpoint.h"

SensorEndpoint::SensorEndpoint(QObject *parent) : Node(parent)
{

}

void SensorEndpoint::setProcessor(SensorProcessor *processor)
{
    processor_ = processor;
    processor_->setParent(this);
}

void SensorEndpoint::onDataReceived(ConcurrentQueue<DataItem> *queue)
{

}

#include "sensorendpoint.h"

SensorEndpoint::SensorEndpoint(QString &name, QObject *parent) : Node(name, parent),
                                                                    name_(name)
{
    this->settings_ = new QSettings(this);
}

QString SensorEndpoint::getName()
{
    return name_;
}

void SensorEndpoint::setProcessor(SensorProcessor *processor)
{
    processor_ = processor;
    processor_->setParent(this);
    processor_->setSettings(settings_);
}

void SensorEndpoint::onDataReceived(ConcurrentQueue<DataItem> *queue)
{

}

QSettings *SensorEndpoint::getSettings() const
{
    return settings_;
}

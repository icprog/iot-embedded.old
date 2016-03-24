#include "sensorendpoint.h"
#include <QDebug>
#include <QThread>

const QString SensorEndpoint::TAG = "SensorEndpoint";
SensorEndpoint::SensorEndpoint(const QString &name, QObject *parent) : Node(name, parent),
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
    connect(processor, &SensorProcessor::dataReady, this, &SensorEndpoint::onSensorDataAvaliable);
}

void SensorEndpoint::onDataReceived(DataItem data)
{

}

void SensorEndpoint::start()
{
    qDebug()<<TAG<<": start() from thread: "<<QThread::currentThreadId();
    processor_->start();
}

void SensorEndpoint::stop()
{
    qDebug()<<TAG<<": stop() from thread: "<<QThread::currentThreadId();
    processor_->stop();
    emit onStopped();
}

void SensorEndpoint::onSensorDataAvaliable(DataItem data)
{

}

QSettings *SensorEndpoint::getSettings() const
{
    return settings_;
}

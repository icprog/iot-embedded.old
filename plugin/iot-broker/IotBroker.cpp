#include "IotBroker.h"

const QString IoTBroker::TAG = "IoTBroker";

IoTBroker::IoTBroker(const QString& name, QObject *parent) : BrokerNode(name, parent),
                                                                 name_(name)
{

}

QString IoTBroker::getName()
{
    return name_;
}

void IoTBroker::start()
{

}

void IoTBroker::stop()
{

}

void IoTBroker::processData(DataItem data)
{

}

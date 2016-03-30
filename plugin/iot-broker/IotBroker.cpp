#include "IotBroker.h"

const QString IoTBroker::TAG = "IoTBroker";
const QString IoTBroker::IOT_BROKER_ID_MAPPING_KEY = "sensorId";

IoTBroker::IoTBroker(const QString& name, QObject *parent) : BrokerNode(name, parent),
                                                                 name_(name)
{
    settings_.beginGroup(name_);
    settings_.beginGroup(IOT_BROKER_ID_MAPPING_KEY);
    QStringList mappings = settings_.childKeys();
    foreach(const QString &key, mappings) {
        sensor_id_mapping_.insert(key, settings_.value(key).toInt());
    }
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

#include "IotBroker.h"
#include <QDebug>
#include <QThread>
#include <QJsonObject>
#include <QJsonDocument>

const QString IoTBroker::TAG = "IoTBroker";
const QString IoTBroker::IOT_BROKER_ID_MAPPING_KEY = "sensorId";

IoTBroker::IoTBroker(const QString& name, QObject *parent) : BrokerNode(name, parent),
                                                                 name_(name)
{
    settings_.beginGroup(name_);
    settings_.beginGroup(IOT_BROKER_ID_MAPPING_KEY);
    QStringList nodes = settings_.childGroups();
    foreach (const QString &node, nodes) {
        settings_.beginGroup(node);
        QStringList mappings = settings_.childKeys();
        foreach(const QString &key, mappings) {
            sensor_id_mapping_.insert(node+"/"+key, settings_.value(key).toInt());
        }
        settings_.endGroup();
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
    qDebug()<<TAG<<": processData() from thread: "<<QThread::currentThreadId();
    QJsonObject json;
    int sensor_id = sensor_id_mapping_[data.senderId()];
    json["id"] = sensor_id;
    json["time"] = data.payload()["time"].toLongLong();
    json["value"] = data.payload()["value"].toDouble();
    DataItem result;
    result.setSenderId(name_.toUtf8());
    result.setSendTime(QDateTime::currentDateTime());
    result.setPayloadType("iot/json");
    result.payload().insert("json", QJsonDocument(json).toJson());

    qDebug()<<result.payload()["json"];
    emit dataProcessed(result);
}

#include "IoTBrokerFactory.h"
#include <QThread>
#include <QDebug>
#include <plugin/iot-broker/IotBroker.h>

const QString IoTBrokerFactory::TAG = "IoTBrokerFactory";

IoTBrokerFactory::IoTBrokerFactory(QObject *parent) : QObject(parent)
{

}

BrokerNode *IoTBrokerFactory::createNode(const QString &node_name)
{
    qDebug()<< TAG << ": createNode() from thread: " << QThread::currentThreadId();
    QThread *thread = new QThread(this);
    thread->start();
    IoTBroker *bn = new IoTBroker(node_name);
    BrokerNode *node = bn;
    node->moveToThread(thread);
    qDebug()<<TAG<<": Node created and moved to dedicated thread." ;
    return node;
}

QByteArray IoTBrokerFactory::getNodeClassName()
{
    return "IoTBroker";
}

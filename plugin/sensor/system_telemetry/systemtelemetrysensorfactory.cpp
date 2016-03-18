#include "systemtelemetrysensorfactory.h"
#include <QDebug>
#include <QThread>
const QString SystemTelemetrySensorFactory::TAG = "SystemTelemetrySensorFactory";

SystemTelemetrySensorFactory::SystemTelemetrySensorFactory(QObject *parent) : QObject(parent)
{

}

Node *SystemTelemetrySensorFactory::createNode(const QString &node_name)
{
    qDebug()<< TAG << ": createNode() from thread: " << QThread::currentThreadId();
    QThread *node_thread = new QThread(this);
    node_thread->start();
    SensorEndpoint *se = new SensorEndpoint(node_name);
    se->setProcessor(new SystemTelemetryProcessor(se->getSettings(), se));
    Node *node = se;
    se->moveToThread(node_thread);
    qDebug()<<TAG<<": Node created and moved to dedicated thread." ;
    return node;
}

QByteArray SystemTelemetrySensorFactory::getNodeClassName()
{
    return TAG.toLocal8Bit();
}

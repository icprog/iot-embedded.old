#include "systemtelemetrysensorfactory.h"
#include <QDebug>
#include <QThread>
const QString SystemTelemetrySensorFactory::TAG = "SystemTelemetrySensorFactory";

SystemTelemetrySensorFactory::SystemTelemetrySensorFactory(QObject *parent) : QObject(parent)
{

}

Node *SystemTelemetrySensorFactory::createNode()
{
    qDebug()<< TAG << ": createNode() from thread: " << QThread::currentThreadId();
    QThread *node_thread = new QThread();
    node_thread->start();
    SensorEndpoint *se = new SensorEndpoint();
    se->setProcessor(new SystemTelemetryProcessor(se));
    Node *node = se;
    se->moveToThread(node_thread);
    qDebug()<<TAG<<": Node created and moved to dedicated thread." ;
    return node;
}

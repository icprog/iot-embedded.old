#include "RestEndpointFactory.h"
#include "RestEndpoint.h"
#include <QThread>
#include <QDebug>
const QString RestEndpointFactory::TAG = "RestEndpointFactory";

RestEndpointFactory::RestEndpointFactory(QObject *parent) : QObject(parent)
{

}

ConnectivityNode *RestEndpointFactory::createNode(const QString &node_name)
{
    qDebug()<< TAG << ": createNode() from thread: " << QThread::currentThreadId();
    QThread *thread = new QThread(this);
    thread->start();
    RestEndpoint *re = new RestEndpoint(node_name);
    ConnectivityNode *node = re;
    node->moveToThread(thread);
    qDebug()<<TAG<<": Node created and moved to dedicated thread." ;
    return node;
}

QByteArray RestEndpointFactory::getNodeClassName()
{
    return "RestEndpoint";
}

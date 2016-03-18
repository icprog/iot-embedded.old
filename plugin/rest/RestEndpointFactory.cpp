#include "RestEndpointFactory.h"
#include "RestEndpoint.h"
#include <QThread>
#include <QDebug>
const QString RestEndpointFactory::TAG = "RestEndpointFactory";

RestEndpointFactory::RestEndpointFactory(QObject *parent) : QObject(parent)
{

}

Node *RestEndpointFactory::createNode(QString &node_name)
{
    qDebug()<< TAG << ": createNode() from thread: " << QThread::currentThreadId();
    QThread *thread = new QThread(this);
    thread->start();
    RestEndpoint *re = new RestEndpoint(node_name);
    Node *node = re;
    node->moveToThread(thread);
    qDebug()<<TAG<<": Node created and moved to dedicated thread." ;
    return node;
}

QByteArray RestEndpointFactory::getNodeClassName()
{
    return TAG.toLocal8Bit();
}

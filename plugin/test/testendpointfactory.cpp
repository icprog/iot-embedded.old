#include "testendpointfactory.h"
#include "qdebug.h"
const QString TestEndpointFactory::TAG = "TestEndpointFactory";

TestEndpointFactory::TestEndpointFactory(QObject *parent) : QObject(parent)
{

}

Node *TestEndpointFactory::createNode()
{
    qDebug()<< TAG << ": createNode() from thread: " << QThread::currentThreadId();
    QThread *node_thread = new QThread();
    node_thread->start();
    Node *node = new TestEndpoint();
    node->moveToThread(node_thread);
    qDebug()<<TAG<<": Node created and moved to thread: " << node_thread->objectName() ;
    return node;
}

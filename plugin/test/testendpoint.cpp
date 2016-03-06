#include "testendpoint.h"
#include "qdebug.h"

const QString TestEndpoint::TAG = "TestEndpoint";

TestEndpoint::TestEndpoint(QObject *parent) : Node(parent)
{

}

void TestEndpoint::onDataReceived(QByteArray &data)
{
    qDebug()<<TAG << ": onDataReceived, thread: " << QThread::currentThreadId();
}

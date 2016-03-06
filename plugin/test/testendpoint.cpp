#include "testendpoint.h"
#include "qdebug.h"

const QString TestEndpoint::TAG = "TestEndpoint";

TestEndpoint::TestEndpoint(QObject *parent) : Node(parent)
{

}

void TestEndpoint::bang()
{
    qDebug()<<TAG<< ": BANG! from thread: "<<QThread::currentThreadId();
    QByteArray dupa(10, 'z');
    emit dataSent(&dupa);
}

void TestEndpoint::onDataReceived(QByteArray *data)
{
    qDebug()<<TAG << ": onDataReceived, thread: " << QThread::currentThreadId();
}

#include "testendpoint.h"
#include "qdebug.h"

const QString TestEndpoint::TAG = "TestEndpoint";

TestEndpoint::TestEndpoint(QObject *parent) : Node(parent)
{

}

void TestEndpoint::bang()
{
    qDebug()<<TAG<< ": BANG! from thread: "<<QThread::currentThreadId();

    test_queue_.enqueue(DataItem());
    emit dataSent(&test_queue_);
}

void TestEndpoint::onDataReceived(ConcurrentQueue<DataItem> *data)
{
    data->dequeue();
    qDebug()<<TAG << ": onDataReceived, thread: " << QThread::currentThreadId();
    bang();
}

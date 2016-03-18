#include "RestEndpoint.h"

RestEndpoint::RestEndpoint(const QString &name, QObject *parent) : Node(name, parent),
                                                             name_(name)
{

}

QString RestEndpoint::getName()
{
    return name_;
}

void RestEndpoint::onDataReceived(ConcurrentQueue<DataItem> *queue)
{

}

void RestEndpoint::start()
{

}

void RestEndpoint::stop()
{

}


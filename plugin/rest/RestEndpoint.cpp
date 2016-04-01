#include "RestEndpoint.h"

RestEndpoint::RestEndpoint(const QString &name, QObject *parent) : ConnectivityNode(name, parent),
                                                             name_(name)
{

}

QString RestEndpoint::getName()
{
    return name_;
}

void RestEndpoint::sendData(DataItem data)
{

}

void RestEndpoint::start()
{

}

void RestEndpoint::stop()
{

}


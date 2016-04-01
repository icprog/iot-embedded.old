#include "WebSocketEndpoint.h"

WebSocketEndpoint::WebSocketEndpoint(const QString &name, QObject *parent) : ConnectivityNode(name, parent),
                                                                             name_(name)
{

}

QString WebSocketEndpoint::getName()
{
    return name_;
}

void WebSocketEndpoint::start()
{

}

void WebSocketEndpoint::stop()
{

}

void WebSocketEndpoint::sendData(DataItem data)
{

}

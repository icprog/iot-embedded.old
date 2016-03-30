#ifndef WEBSOCKETENDPOINT_H
#define WEBSOCKETENDPOINT_H

#include <QObject>
#include <ConnectivityNode.h>

class WebSocketEndpoint : public ConnectivityNode
{
    Q_OBJECT
public:
    explicit WebSocketEndpoint(const QString& name, QObject *parent = 0);
    virtual ~WebSocketEndpoint() {}
    virtual QString getName() override final;


public slots:
    virtual void start();
    virtual void stop();
    virtual void sendData(DataItem data);

private:
   static const QString TAG;
   QString name_;

};

#endif // WEBSOCKETENDPOINT_H

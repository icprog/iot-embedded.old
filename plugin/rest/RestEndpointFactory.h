#ifndef RESTENDPOINTFACTORY_H
#define RESTENDPOINTFACTORY_H

#include <QObject>

#include <ConnectivityNodeFactory.h>

class RestEndpointFactory : public QObject, public ConnectivityNodeFactory
{
    Q_OBJECT
    Q_INTERFACES(ConnectivityNodeFactory)

public:   
    explicit RestEndpointFactory(QObject* parent = 0);

    ConnectivityNode *createNode(const QString &node_name) override final;

    QByteArray getNodeClassName() override final;

private:
    const static QString TAG;
};

#endif // RESTENDPOINTFACTORY_H

#ifndef RESTENDPOINTFACTORY_H
#define RESTENDPOINTFACTORY_H

#include <QObject>

#include "nodefactory.h"

class RestEndpointFactory : public QObject, public NodeFactory
{
    Q_OBJECT
    Q_INTERFACES(NodeFactory)

public:   
    explicit RestEndpointFactory(QObject* parent = 0);

    Node *createNode(const QString &node_name) override final;

    QByteArray getNodeClassName() override final;

private:
    const static QString TAG;
};

#endif // RESTENDPOINTFACTORY_H

#ifndef TESTENDPOINTFACTORY_H
#define TESTENDPOINTFACTORY_H

#include <QObject>
#include "nodefactory.h"
#include "node.h"
#include "testendpoint.h"
class TestEndpointFactory : public QObject, public NodeFactory
{
    Q_OBJECT
//    Q_PLUGIN_METADATA(IID "com.jmssolutions.iot.embedded.plugin.node.TestEndpoint")
    Q_INTERFACES(NodeFactory)

public:
    explicit TestEndpointFactory(QObject *parent = 0);

    Node *createNode(const QString &name) override final;

    QByteArray getNodeClassName() override final {return "TestEndpointFactory"; }


signals:

public slots:

private:
    const static QString TAG;
};

#endif // TESTENDPOINTFACTORY_H

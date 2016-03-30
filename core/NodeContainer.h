#ifndef NODECONTAINER_H
#define NODECONTAINER_H

#include <QObject>
#include <QMap>
#include <SensorNode.h>
#include <SensorNodeFactory.h>
#include <BrokerNode.h>
#include <BrokerNodeFactory.h>
#include <ConnectivityNode.h>
#include <ConnectivityNodeFactory.h>

#include "node.h"
#include "nodefactory.h"

class NodeContainer : public QObject
{
    Q_OBJECT
public:
    explicit NodeContainer(QObject *parent = 0);
    ~NodeContainer();

    SensorNode* getSensor(const QString &name);
    BrokerNode* getBroker(const QString &name);
    ConnectivityNode* getConnectivityNode(const QString &name);

    SensorNodeFactory* getSensorFactory(const QString &name);
    BrokerNodeFactory* getBrokerFactory(const QString &name);
    ConnectivityNodeFactory* getConnectivityFactory(const QString &name);




    bool loadNodeFactory(QString &file_name);
    bool loadNodeFactoryTestSet();

    void registerNode(SensorNode *node);
    void registerNode(BrokerNode *node);
    void registerNode(ConnectivityNode *node);

signals:

public slots:

private:
//    QMap<QString, Node*> nodes_;
//    QMap<QString, NodeFactory*> factories_;

    QMap<QString, SensorNode*> sensor_nodes_;
    QMap<QString, BrokerNode*> broker_nodes_;
    QMap<QString, ConnectivityNode*> connectivity_nodes_;

    QMap<QString, SensorNodeFactory*> sensor_node_factories_;
    QMap<QString, BrokerNodeFactory*> broker_node_factories_;
    QMap<QString, ConnectivityNodeFactory*> connectivity_node_factories_;

};

#endif // NODECONTAINER_H

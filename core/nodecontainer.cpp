#include "nodecontainer.h"

NodeContainer::NodeContainer(QObject *parent) : QObject(parent)
{

}

Node *NodeContainer::getNode(QString &name)
{
    if(nodes_.contains(name))
        return nodes_[name];
    else return nullptr;
}

NodeFactory *NodeContainer::getNodeFactory(QString &class_name)
{
    if(factories_.contains(class_name))
        return factories_[class_name];
    else return nullptr;
}

bool NodeContainer::loadNodeFactory(QString &file_name)
{
    // do PluginLoader stuff here
}


#include "plugin/sensor/system_telemetry/systemtelemetrysensorfactory.h"
bool NodeContainer::loadNodeFactoryTestSet()
{
    NodeFactory *sts_factory = new SystemTelemetrySensorFactory(this);
    factories_.insert(sts_factory->getNodeClassName(), sts_factory);
    /// debug function


}

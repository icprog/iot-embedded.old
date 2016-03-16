#include "nodecontainer.h"
#include <stdexcept>

NodeContainer::NodeContainer(QObject *parent) : QObject(parent)
{

}

Node *NodeContainer::getNode(QString &name)
{
    if(nodes_.contains(name))
        return nodes_[name];
    else throw new std::runtime_error("Cannot find node with given name");
}

NodeFactory *NodeContainer::getNodeFactory(QString &class_name)
{
    if(factories_.contains(class_name))
        return factories_[class_name];
    else throw new std::runtime_error("Node Factory of given name not registered.");
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

void NodeContainer::registerNode(Node *node)
{
    if(nodes_.contains(node->getName()))
        throw new std::runtime_error("Node of given name already exists.");
    else
        nodes_.insert(node->getName(), node);

}

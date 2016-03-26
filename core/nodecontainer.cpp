#include "nodecontainer.h"
#include <stdexcept>

NodeContainer::NodeContainer(QObject *parent) : QObject(parent)
{

}

Node *NodeContainer::getNode(const QString &name)
{
    if(nodes_.contains(name))
        return nodes_[name];
    else throw new std::runtime_error("Cannot find node with given name");
}

NodeFactory *NodeContainer::getNodeFactory(const QString &class_name)
{
    if(factories_.contains(class_name))
        return factories_[class_name];
    else throw new std::runtime_error("Node Factory of given name not registered.");
}

#include "plugin/sensor/system_telemetry/SystemTelemetrySensorFactory.h"
#include "plugin/rest/RestEndpointFactory.h"
bool NodeContainer::loadNodeFactory(QString &file_name)
{
    if(file_name.startsWith("test")) {
        QString name = file_name;
        name.remove("test_lib");
        name.remove(".so");
        NodeFactory* nf;
        if(name=="restendpoint") {
            nf = new RestEndpointFactory();
            factories_.insert(nf->getNodeClassName(), nf);
        }

        if(name=="systemtelemetrysensor") {
            nf = new SystemTelemetrySensorFactory();
            factories_.insert(nf->getNodeClassName(), nf);
        }
    }
    // do PluginLoader stuff here
}



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

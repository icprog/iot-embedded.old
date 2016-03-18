#ifndef NODEFACTORY_H
#define NODEFACTORY_H
#include "node.h"

/**
 * @brief The NodeFactory interface
 * @details This is interface exported to plugin.
 *          Creates instance of plugins.
 */
class NodeFactory
{
public:
    /**
     * @brief ~NodeFactory Virtual desctuctor
     */
    virtual ~NodeFactory() {}

    /**
     * @brief createNode Node instance method
     * @return instance of Node interface
     */
    virtual Node *createNode(const QString &node_name) = 0;

    virtual QByteArray getNodeClassName() = 0;

};

#include <QObject>
#define NodeFactory_iid "com.jmssolutions.iot.embedded.plugin.node.NodeFactory"
Q_DECLARE_INTERFACE(NodeFactory, NodeFactory_iid)

#endif // NODEFACTORY_H

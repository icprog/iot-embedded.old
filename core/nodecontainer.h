#ifndef NODECONTAINER_H
#define NODECONTAINER_H

#include <QObject>
#include <QMap>
#include "node.h"
#include "nodefactory.h"

class NodeContainer : public QObject
{
    Q_OBJECT
public:
    explicit NodeContainer(QObject *parent = 0);

    Node* getNode(QString &name);
    NodeFactory* getNodeFactory(QString &class_name);

    bool loadNodeFactory(QString &file_name);
    bool loadNodeFactoryTestSet();

signals:

public slots:

private:
    QMap<QString, Node*> nodes_;
    QMap<QString, NodeFactory*> factories_;
};

#endif // NODECONTAINER_H

#ifndef NODE_H
#define NODE_H
#include <QObject>
#include <QByteArray>
#include "utils/concurrentqueue.h"
#include "utils/dataitem.h"

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = 0) : QObject(parent) {}
    virtual ~Node() {}

public slots:
    virtual void onDataReceived(ConcurrentQueue<DataItem> *queue) = 0 ;

signals:
    void dataSent(ConcurrentQueue<DataItem> *queue);
};

#endif // NODE_H

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
    explicit Node(const QString& name, QObject *parent = 0) : QObject(parent) {}
    virtual ~Node() {}
    virtual QString getName() = 0;


public slots:
    virtual void onDataReceived(DataItem data) = 0 ;
    virtual void start() = 0;
    virtual void stop() = 0;

signals:
    void dataSent(DataItem data);
    void onStopped();
};

#endif // NODE_H

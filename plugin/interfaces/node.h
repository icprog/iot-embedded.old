#ifndef NODE_H
#define NODE_H
#include <QObject>
#include <QByteArray>

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = 0) : QObject(parent) {}
    virtual ~Node() {}

public slots:
    virtual void onDataReceived(QByteArray& data) = 0 ;

signals:
    void dataSent(QByteArray& data);
};

#endif // NODE_H

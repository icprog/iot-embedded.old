#ifndef TESTENDPOINT_H
#define TESTENDPOINT_H

#include <QObject>
#include <QThread>
#include "node.h"
class TestEndpoint : public Node
{
    Q_OBJECT
public:
    explicit TestEndpoint(QObject *parent = 0);

    void bang();

public slots:
    void onDataReceived(ConcurrentQueue<DataItem>* data) override;

private:
    static const QString TAG;

    ConcurrentQueue<DataItem> test_queue_;
};

#endif // TESTENDPOINT_H

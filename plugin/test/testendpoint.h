#ifndef TESTENDPOINT_H
#define TESTENDPOINT_H

#include <QObject>
#include <QThread>
#include "node.h"
class TestEndpoint : public Node
{
    Q_OBJECT
public:
    explicit TestEndpoint(QString &name, QObject *parent = 0);

    void bang();

    QString getName() override final;

public slots:
    void onDataReceived(ConcurrentQueue<DataItem>* data) override final;
    void start() override final {}
    void stop() override final {emit onStopped();}

private:
    static const QString TAG;

    ConcurrentQueue<DataItem> test_queue_;
};

#endif // TESTENDPOINT_H

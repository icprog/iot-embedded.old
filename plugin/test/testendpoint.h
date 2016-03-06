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

public slots:
    void onDataReceived(QByteArray& data) override;

private:
    static const QString TAG;
};

#endif // TESTENDPOINT_H

#ifndef IOTBROKER_H
#define IOTBROKER_H

#include <QObject>
#include <BrokerNode.h>

class IoTBroker : public BrokerNode
{
    Q_OBJECT
public:
    explicit IoTBroker(const QString& name, QObject *parent = 0);
    virtual ~IoTBroker() {}
    virtual QString getName() override final;


public slots:
    virtual void start() override;
    virtual void stop() override;
    virtual void processData(DataItem data) override;

private:
   static const QString TAG;
   QString name_;

};

#endif // IOTBROKER_H

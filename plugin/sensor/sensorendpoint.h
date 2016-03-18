#ifndef SENSORENDPOINT_H
#define SENSORENDPOINT_H
#include <QObject>

#include "node.h"
#include "sensorprocessor.h"


class SensorEndpoint : public Node
{
    Q_OBJECT
public:
    explicit SensorEndpoint(QString &name, QObject *parent = 0);
    QString getName() override final;
    QSettings *getSettings() const;

    void setProcessor(SensorProcessor *processor);

public slots:
    virtual void onDataReceived(ConcurrentQueue<DataItem>* queue) override;
    virtual void start() override;
    virtual void stop() override;

private:
    SensorProcessor* processor_;
    const static QString TAG;

protected:
    QString name_;
    QSettings *settings_;
};

#endif // SENSORENDPOINT_H

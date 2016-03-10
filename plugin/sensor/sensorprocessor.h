#ifndef SENSORPROCESSOR_H
#define SENSORPROCESSOR_H

#include <QObject>
#include <QTimer>
#include <QSettings>
#include "utils/concurrentqueue.h"
#include "utils/dataitem.h"

class SensorProcessor : public QObject
{
    Q_OBJECT
public:
    explicit SensorProcessor(QObject *parent = 0);

signals:
    void dataReady(ConcurrentQueue<DataItem>* queue);

public slots:
    virtual void onData(ConcurrentQueue<DataItem>* queue)=0;
protected:
    QTimer* timer_;
    QSettings* settings_;
};

#endif // SENSORPROCESSOR_H

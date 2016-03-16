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
    explicit SensorProcessor(QSettings *settings, QObject *parent = 0);

    void setSettings(QSettings *settings);

signals:
    void dataReady();

public slots:
    virtual void onData(ConcurrentQueue<DataItem>* queue)=0;
protected:
    QTimer* timer_;
    QSettings* settings_;

};

#endif // SENSORPROCESSOR_H

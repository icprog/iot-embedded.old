#ifndef SYSTEMTELEMETRYSENSOR_H
#define SYSTEMTELEMETRYSENSOR_H
#include "plugin/sensor/sensorprocessor.h"

class SystemTelemetryProcessor: public SensorProcessor
{
public:
    explicit SystemTelemetryProcessor(QObject *parent = 0);

public slots:
    void onData(ConcurrentQueue<DataItem> *queue);

private slots:
    void onTimerTimeout();

private:
    const static QString TAG;
};

#endif // SYSTEMTELEMETRYSENSOR_H

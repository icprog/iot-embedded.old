#ifndef SYSTEMTELEMETRYSENSOR_H
#define SYSTEMTELEMETRYSENSOR_H
#include "plugin/sensor/sensorprocessor.h"
#include <QFile>

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

    QFile* proc_loadavg_;
    QFile* proc_meminfo_;
    QFile* proc_stat_;
};

#endif // SYSTEMTELEMETRYSENSOR_H

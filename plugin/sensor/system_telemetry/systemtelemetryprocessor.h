#ifndef SYSTEMTELEMETRYSENSOR_H
#define SYSTEMTELEMETRYSENSOR_H
#include "plugin/sensor/sensorprocessor.h"
#include "systemdataprovider.h"
#include <QFile>

class SystemTelemetryProcessor: public SensorProcessor
{
public:
    explicit SystemTelemetryProcessor(QSettings * settings, QObject *parent = 0);

public slots:
    void onData(DataItem data);
    void start() override;
    void stop() override;

private slots:
    void onTimerTimeout();

private:
    const static QString TAG;

    QFile* proc_loadavg_;
    QFile* proc_meminfo_;
    QFile* proc_stat_;

    SystemDataProvider *data_provider_;

    double load_avg_;
    double mem_usage_;
    double cpu_usage_;

    int load_avg_sensor_id_;
    int cpu_usage_sensor_id_;
    int mem_usage_sensor_id_;
};

#endif // SYSTEMTELEMETRYSENSOR_H

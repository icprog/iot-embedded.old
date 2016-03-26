#include "SystemTelemetryWorker.h"
#include <QDebug>
#include <QThread>
#include "dataitem.h"

const QString SystemTelemetryWorker::TAG = "SystemTelemetryProcessor";

SystemTelemetryWorker::SystemTelemetryWorker(QSettings * settings, QObject* parent) : SensorWorker(settings, parent)
{
    qDebug()<<TAG<<": constructor() from thread: "<<QThread::currentThreadId();
    /* test code */
//    this->settings_->setValue("loadAvgPath", "/proc/loadavg");
//    this->settings_->setValue("meminfoPath", "/proc/meminfo");
//    this->settings_->setValue("statPath", "/proc/stat");
//    this->settings_->setValue("sampleInterval", 500);
    /*   */



    // File setup
    this->proc_loadavg_ = new QFile(this->settings_->value("loadAvgPath").toString(), this);
    this->proc_meminfo_ = new QFile(this->settings_->value("meminfoPath").toString(), this);
    this->proc_stat_ = new QFile(this->settings_->value("statPath").toString(), this);
    qDebug()<<TAG<<": constructor() - /proc files handler created.";

    this->load_avg_sensor_id_ = settings_->value("loadAvgSensorID").toInt();
    this->mem_usage_sensor_id_ = settings_->value("memInfoSensorID").toInt();
    this->cpu_usage_sensor_id_ = settings_->value("cpuUsageSensorID").toInt();
    // Data provider setup
    data_provider_ = new SystemDataProvider(this);
    if(proc_loadavg_->exists())
        data_provider_->setLoadavgFile(proc_loadavg_);
    if(proc_meminfo_->exists())
        data_provider_->setMeminfoFile(proc_meminfo_);
    if(proc_stat_->exists())
        data_provider_->setStatFile(proc_stat_);

    // Timer setup
    this->timer_ = new QTimer(this);
    timer_->setInterval(this->settings_->value("sampleInterval").toInt());
    connect(timer_, &QTimer::timeout, this, &SystemTelemetryWorker::onTimerTimeout);
//    timer_->start();
    qDebug()<<TAG<<": constructor() - created and started timer.";

}

void SystemTelemetryWorker::onData(DataItem data)
{
    qDebug()<<TAG<<": onData() from thread: "<<QThread::currentThreadId();
}

void SystemTelemetryWorker::start()
{
    connect(this, SIGNAL(signalStart()), this->timer_, SLOT(start()) );
    emit signalStart();
}

void SystemTelemetryWorker::stop()
{
    connect(this, &SensorWorker::signalStop, this->timer_, &QTimer::stop );
    emit signalStop();
}

void SystemTelemetryWorker::onTimerTimeout()
{
//    qDebug()<<TAG<<": onTimerTimeout() from thread: "<<QThread::currentThreadId();

    try{
        load_avg_ = data_provider_->getLoadAverage();
        cpu_usage_ = data_provider_->getProcessorUsage();
        mem_usage_ = data_provider_->getMemoryUsage();
    } catch (std::runtime_error e) {
        qDebug()<<TAG<<": onTimerTimeout() - exception caught: "<<e.what();
        return;
    }

    DataItem load_avg_item;
    load_avg_item.setPayloadType("sensor");
    load_avg_item.payload().insert("value", load_avg_);
    load_avg_item.payload().insert("time", QTime::currentTime());
    load_avg_item.payload().insert("id", load_avg_sensor_id_);
    emit dataReady(load_avg_item);

    DataItem cpu_usage_item;
    cpu_usage_item.setPayloadType("sensor");
    cpu_usage_item.payload().insert("value", cpu_usage_);
    cpu_usage_item.payload().insert("time", QTime::currentTime());
    cpu_usage_item.payload().insert("id", cpu_usage_sensor_id_);
    emit dataReady(load_avg_item);

    DataItem mem_usage_item;
    mem_usage_item.setPayloadType("sensor");
    mem_usage_item.payload().insert("value", mem_usage_);
    mem_usage_item.payload().insert("time", QTime::currentTime());
    mem_usage_item.payload().insert("id", mem_usage_sensor_id_);
    emit dataReady(mem_usage_item);
}

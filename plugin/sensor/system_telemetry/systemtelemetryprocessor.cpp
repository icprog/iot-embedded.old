#include "systemtelemetryprocessor.h"
#include "QThread"
#include "qdebug.h"

const QString SystemTelemetryProcessor::TAG = "SystemTelemetryProcessor";

SystemTelemetryProcessor::SystemTelemetryProcessor(QObject* parent) : SensorProcessor(parent)
{
    qDebug()<<TAG<<": constructor() from thread: "<<QThread::currentThreadId();
    /* test code */
    this->settings_->setValue("loadAvgPath", "/proc/loadavg");
    this->settings_->setValue("meminfoPath", "/proc/meminfo");
    this->settings_->setValue("statPath", "/proc/stat");
    this->settings_->setValue("sampleInterval", 500);
    /*   */



    // File setup
    this->proc_loadavg_ = new QFile(this->settings_->value("loadAvgPath").toString(), this);
    this->proc_meminfo_ = new QFile(this->settings_->value("meminfoPath").toString(), this);
    this->proc_stat_ = new QFile(this->settings_->value("statPath").toString(), this);
    qDebug()<<TAG<<": constructor() - /proc files handler created.";

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
    connect(timer_, &QTimer::timeout, this, &SystemTelemetryProcessor::onTimerTimeout);
    timer_->start();
    qDebug()<<TAG<<": constructor() - created and started timer.";

}

void SystemTelemetryProcessor::onData(ConcurrentQueue<DataItem> *queue)
{
    qDebug()<<TAG<<": onData() from thread: "<<QThread::currentThreadId();
}

void SystemTelemetryProcessor::onTimerTimeout()
{
    qDebug()<<TAG<<": onTimerTimeout() from thread: "<<QThread::currentThreadId();

    try{
        double load_avg = data_provider_->getLoadAverage();
        qDebug()<<TAG<<": onTimerTimeout() - proc/loadavg: "<<load_avg;
        double  cpu_usage = data_provider_->getProcessorUsage();
        qDebug()<<TAG<<": onTimerTimeout() - proc/stat: "<<cpu_usage;
        double  memory_usage = data_provider_->getMemoryUsage();
        qDebug()<<TAG<<": onTimerTimeout() - proc/meminfo: "<<memory_usage;
    } catch (std::runtime_error e) {
        qDebug()<<TAG<<": onTimerTimeout() - exception caught: "<<e.what();
    }

//    QByteArray arr =
}

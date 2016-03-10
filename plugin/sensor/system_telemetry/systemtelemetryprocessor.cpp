#include "systemtelemetryprocessor.h"
#include "QThread"
#include "qdebug.h"

const QString SystemTelemetryProcessor::TAG = "SystemTelemetryProcessor";

SystemTelemetryProcessor::SystemTelemetryProcessor(QObject* parent) : SensorProcessor(parent)
{
    /* test code */
    this->settings_->setValue("loadAvgPath", "/proc/loadavg");
    this->settings_->setValue("meminfoPath", "/proc/meminfo");
    this->settings_->setValue("statPath", "/proc/stat");
    this->settings_->setValue("sampleInterval", 500);
    /*   */

    this->timer_ = new QTimer(this);

    this->proc_loadavg_ = new QFile(this->settings_->value("loadAvgPath").toString(), this);
    this->proc_meminfo_ = new QFile(this->settings_->value("meminfoPath").toString(), this);
    this->proc_stat_ = new QFile(this->settings_->value("statPath").toString(), this);

    proc_loadavg_->open(QFile::ReadOnly);
    proc_meminfo_->open(QFile::ReadOnly);
    proc_stat_->open(QFile::ReadOnly);
     qDebug()<<TAG<<": constructor() - /proc files opened.";
    /** TEST SETTINGS **/
    timer_->setInterval(this->settings_->value("sampleInterval").toInt());
    connect(timer_, &QTimer::timeout, this, &SystemTelemetryProcessor::onTimerTimeout);
    timer_->start();
    qDebug()<<TAG<<": constructor() from thread: "<<QThread::currentThreadId()<<" - created and started timer.";

}

void SystemTelemetryProcessor::onData(ConcurrentQueue<DataItem> *queue)
{
    qDebug()<<TAG<<": onData() from thread: "<<QThread::currentThreadId();
}

void SystemTelemetryProcessor::onTimerTimeout()
{
    qDebug()<<TAG<<": onTimerTimeout() from thread: "<<QThread::currentThreadId();
    qDebug()<<proc_loadavg_->readAll();
}

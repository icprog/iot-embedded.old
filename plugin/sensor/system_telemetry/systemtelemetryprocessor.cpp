#include "systemtelemetryprocessor.h"
#include "QThread"
#include "qdebug.h"

const QString SystemTelemetryProcessor::TAG = "SystemTelemetryProcessor";

SystemTelemetryProcessor::SystemTelemetryProcessor(QObject* parent) : SensorProcessor(parent)
{
    this->timer_ = new QTimer(this);

    /** TEST SETTINGS **/
    timer_->setInterval(500);
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
}

#include "SensorWorker.h"

SensorWorker::SensorWorker(QSettings *settings, QObject *parent) : QObject(parent)
{
    this->settings_ = settings;
}

void SensorWorker::setSettings(QSettings *settings)
{
    settings_ = settings;
}

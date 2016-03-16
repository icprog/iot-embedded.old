#include "sensorprocessor.h"

SensorProcessor::SensorProcessor(QSettings *settings, QObject *parent) : QObject(parent)
{
    this->settings_ = settings;
}

void SensorProcessor::setSettings(QSettings *settings)
{
    settings_ = settings;
}

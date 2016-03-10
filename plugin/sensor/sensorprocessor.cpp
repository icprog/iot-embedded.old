#include "sensorprocessor.h"

SensorProcessor::SensorProcessor(QObject *parent) : QObject(parent)
{
    this->settings_ = new QSettings(this);
}

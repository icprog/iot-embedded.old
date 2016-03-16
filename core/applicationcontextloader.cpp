#include "applicationcontextloader.h"
#include "pipeline.h"
#include "onetomanypipeline.h"

ApplicationContextLoader::ApplicationContextLoader(QObject *parent) : QObject(parent)
{

}

void ApplicationContextLoader::loadApplicationContext(const QString &config_path)
{

}

void ApplicationContextLoader::loadTestContext()
{
    QString sts_factory_name = "SystemTelemetrySensorFactory";
    QString sensor_name = "SysTelemetrySensor1";
    node_container_->loadNodeFactoryTestSet();
    node_container_->getNodeFactory(sts_factory_name)->createNode(sensor_name);

    Pipeline *pipe = new OneToManyPipeline(this);
    pipe->setInboundChannel(node_container_->getNode(sensor_name));

}

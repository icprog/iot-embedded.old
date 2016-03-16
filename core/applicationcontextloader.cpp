#include "applicationcontextloader.h"
#include "pipeline.h"
#include "onetomanypipeline.h"

ApplicationContextLoader::ApplicationContextLoader(QObject *parent) : QObject(parent)
{
    this->node_container_ = nullptr;

}

void ApplicationContextLoader::loadApplicationContext(const QString &config_path)
{
    assertNodeContainerExists();

}

void ApplicationContextLoader::loadTestContext()
{
    assertNodeContainerExists();
    QString sts_factory_name = "SystemTelemetrySensorFactory";
    QString sensor_name = "SysTelemetrySensor1";
    node_container_->loadNodeFactoryTestSet();
    Node *sts1 = node_container_->getNodeFactory(sts_factory_name)->createNode(sensor_name);
    node_container_->registerNode(sts1);
    Pipeline *pipe = new OneToManyPipeline(this);
    pipe->setInboundChannel(node_container_->getNode(sensor_name));

    sts1->start();

}

void ApplicationContextLoader::setNodeContainer(NodeContainer *node_container)
{
    node_container_ = node_container;
}

void ApplicationContextLoader::assertNodeContainerExists()
{
    if(this->node_container_ == nullptr)
        throw new std::runtime_error("No NodeContainer specified.");
}

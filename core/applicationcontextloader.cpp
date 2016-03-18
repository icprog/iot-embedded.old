#include "applicationcontextloader.h"
#include "pipeline.h"
#include "onetomanypipeline.h"
#include <QDebug>
#include <stdexcept>

const QString ApplicationContextLoader::TAG = "ApplicationContextLoader";
const QString ApplicationContextLoader::NODE_SETTINGS_FILENAME = "nodes.config";
const QString ApplicationContextLoader::PIPE_SETTINGS_FILENAME = "pipelines.config";
const QString ApplicationContextLoader::NODE_LIB_FILENAME_KEY = "filename";
const QString ApplicationContextLoader::NODE_CLASSNAME_KEY = "classname";

ApplicationContextLoader::ApplicationContextLoader(QObject *parent) : QObject(parent)
{
    this->node_container_ = nullptr;

}

void ApplicationContextLoader::loadApplicationContext(const QString &config_path)
{
     qDebug()<<TAG<<": loadApplicationContext()";
    assertNodeContainerExists();
    /// Try loading settings
    node_settings_ = new QSettings(config_path+"\\"+NODE_SETTINGS_FILENAME, QSettings::NativeFormat, this);
    pipe_settings_ = new QSettings(config_path+"\\"+PIPE_SETTINGS_FILENAME, QSettings::NativeFormat, this);

    /// Load and instantiate nodes
    QStringList node_name_list = node_settings_->childGroups();
    if(node_name_list.empty()){
        qDebug()<<TAG<<": node configuration file contains no valid node descriptions.";
        throw new std::runtime_error("nodes.config contains no node description");
    }

    foreach (const QString &name, node_name_list) {
        QString lib_filename = node_settings_->value(NODE_CLASSNAME_KEY).toString();
        QString classname = node_settings_->value(NODE_CLASSNAME_KEY).toString();
        node_container_->loadNodeFactory(lib_filename);
        node_container_->getNodeFactory(classname)->createNode(name);

    }


    /// Load and create pipelines



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

#include "applicationcontextloader.h"
#include <QDebug>
#include <stdexcept>

const QString ApplicationContextLoader::TAG = "ApplicationContextLoader";
const QString ApplicationContextLoader::NODE_SETTINGS_FILENAME = "nodes.config";
const QString ApplicationContextLoader::PIPE_SETTINGS_FILENAME = "pipelines.config";
const QString ApplicationContextLoader::NODE_LIB_FILENAME_KEY = "filename";
const QString ApplicationContextLoader::NODE_CLASSNAME_KEY = "classname";
const QString ApplicationContextLoader::NODE_CONNECTIONS_KEY = "outboundTo";

ApplicationContextLoader::ApplicationContextLoader(QObject *parent) : QObject(parent)
{
    this->node_container_ = nullptr;

}

void ApplicationContextLoader::loadApplicationContext(const QString &config_path)
{
     qDebug()<<TAG<<": loadApplicationContext()";
    assertNodeContainerExists();
    /// Try loading settings
    node_settings_ = new QSettings(config_path+"/"+NODE_SETTINGS_FILENAME, QSettings::NativeFormat, this);
    pipe_settings_ = new QSettings(config_path+"/"+PIPE_SETTINGS_FILENAME, QSettings::NativeFormat, this);
    QSettings global_settings;
    qDebug()<<TAG<<": Node settings path: "<<node_settings_->fileName();
    qDebug()<<TAG<<": Pipe settings path: "<<pipe_settings_->fileName();
    qDebug()<<TAG<<": Global settings path: "<<global_settings.fileName();
    /// Load and instantiate nodes
    QStringList node_name_list = node_settings_->childGroups();
    if(node_name_list.empty()){
        qDebug()<<TAG<<": node configuration file contains no valid node descriptions.";
        throw new std::runtime_error("nodes.config contains no node description");
    }

    // Lambda alert! Used because I can.
    auto copySettingsToGlobal = [this, &global_settings](const QString &node_name)->void {
        global_settings.beginGroup(node_name);
        node_settings_->beginGroup(node_name);
        QStringList keys = node_settings_->allKeys();
        foreach (const QString &key, keys) {
           global_settings.setValue(key, node_settings_->value(key));
        }
        global_settings.endGroup();
        node_settings_->endGroup();
        global_settings.sync();
    };

    QMap<QString, QStringList> connections_by_name;
    foreach (const QString &name, node_name_list) {
        node_settings_->beginGroup(name);
        QString lib_filename = node_settings_->value(NODE_LIB_FILENAME_KEY).toString();
        QString classname = node_settings_->value(NODE_CLASSNAME_KEY).toString();
        connections_by_name.insert(name, node_settings_->value(NODE_CONNECTIONS_KEY).toStringList());
        node_settings_->endGroup();

        node_container_->loadNodeFactory(lib_filename);
//        Node * node = node_container_->getNodeFactory(classname)->createNode(name);
//        node_container_->registerNode(node);

        copySettingsToGlobal(name);
    }

    /// Load and create pipelines
    foreach (const QString &name, connections_by_name.keys()) {
        Node *in = nullptr;
        try {
//            in = node_container_->getNode(name);
        } catch (std::runtime_error e) {
            QString msg = "Cannot create connection: node " + name + "not found";
            throw new std::runtime_error(msg.toStdString());
        }
        Pipeline *pipe = new OneToManyPipeline(this);
        foreach (const QString &connection, connections_by_name[name]) {
//            Node *out = node_container_->getNode(connection);

//            pipe->setInboundChannel(in);
//            pipe->setOutboundChannel(out);
        }
        pipeline_container_.insert("name", pipe);
    }




}

void ApplicationContextLoader::loadTestContext()
{
    assertNodeContainerExists();
    QString sts_factory_name = "SystemTelemetrySensor";
    QString sensor_name = "SysTelemetrySensor1";
//    node_container_->loadNodeFactoryTestSet();
//    Node *sts1 = node_container_->getNodeFactory(sts_factory_name)->createNode(sensor_name);
//    node_container_->registerNode(sts1);
//    Pipeline *pipe = new OneToManyPipeline(this);
//    pipe->setInboundChannel(node_container_->getNode(sensor_name));

//    sts1->start();

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

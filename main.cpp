#include <QCoreApplication>
#include <QStringBuilder>
#include "core/applicationcontextloader.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("IoTEmbeddedClient");
    QCoreApplication::setOrganizationName("JMSsolutions");
    QCoreApplication a(argc, argv);

    ApplicationContextLoader context;
    NodeContainer* container = new NodeContainer(&context);
    context.setNodeContainer(container);


    context.loadTestContext();
    context.loadApplicationContext("/home/jakub/iot-embedded.config");
    context.loadApplicationContext("zzz");
    context.dumpObjectTree();

//    QString n_a_name = "SystemTelemetrySensor";
//    NodeFactory* nf2 = new SystemTelemetrySensorFactory(&a);
//    Node *n_a = nf2->createNode(n_a_name);


    return a.exec();

//    return 0;
}

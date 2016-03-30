#include <QCoreApplication>
#include <QStringBuilder>
#include "core/ApplicationContextLoader.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("IoTEmbeddedClient");
    QCoreApplication::setOrganizationName("JMSsolutions");
    QCoreApplication a(argc, argv);

    ApplicationContextLoader context(&a);
    NodeContainer* container = new NodeContainer(&context);
    context.setNodeContainer(container);


//    context.loadTestContext();
    context.loadApplicationContext("/home/jakub");
    context.dumpObjectTree();

    return a.exec();

//    return 0;
}

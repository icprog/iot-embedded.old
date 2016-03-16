#include <QCoreApplication>
#include "nodefactory.h"
#include "node.h"
#include "pipeline.h"
#include "onetomanypipeline.h"
#include "plugin/test/testendpoint.h"
#include "plugin/test/testendpointfactory.h"
#include "plugin/sensor/system_telemetry/systemtelemetrysensorfactory.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("IoTEmbeddedClient");
    QCoreApplication::setOrganizationName("JMSsolutions");
    QCoreApplication a(argc, argv);


//    NodeFactory* nf = new TestEndpointFactory();
//    Node* n_a = nf->createNode();
//    Node* n_b = nf->createNode();


//    Pipeline* p1 = new OneToManyPipeline();
//    Pipeline* p2 = new OneToManyPipeline();

//    p1->setInboundChannel(n_a);
//    p1->setOutboundChannel(n_b);

//    p2->setInboundChannel(n_b);
//    p2->setOutboundChannel(n_a);

//    TestEndpoint* e = dynamic_cast<TestEndpoint*>(n_a);
//    e->bang();

    QString n_a_name = "SystemTelemetrySensor";
    NodeFactory* nf2 = new SystemTelemetrySensorFactory(&a);
    Node *n_a = nf2->createNode(n_a_name);


    return a.exec();

//    return 0;
}

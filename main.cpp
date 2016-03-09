#include <QCoreApplication>
#include "nodefactory.h"
#include "node.h"
#include "pipeline.h"
#include "onetomanypipeline.h"
#include "plugin/test/testendpoint.h"
#include "plugin/test/testendpointfactory.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    NodeFactory* nf = new TestEndpointFactory();
    Node* n_a = nf->createNode();
    Node* n_b = nf->createNode();


    Pipeline* p1 = new OneToManyPipeline();
    Pipeline* p2 = new OneToManyPipeline();

    p1->setInboundChannel(n_a);
    p1->setOutboundChannel(n_b);

    p2->setInboundChannel(n_b);
    p2->setOutboundChannel(n_a);

    TestEndpoint* e = dynamic_cast<TestEndpoint*>(n_a);
    e->bang();

    return a.exec();
//    return 0;
}

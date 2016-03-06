#include "pipeline/onetomanypipeline.h"

OneToManyPipeline::OneToManyPipeline(QObject *parent) : QObject(parent),
                                                        outbound_channels_(0)
{

}

void OneToManyPipeline::setInboundChannel(Node &channel){
    this->inbound_channel_ = &channel;

}

void OneToManyPipeline::setOutboundChannel(Node &channel){
    this->outbound_channels_.push_back(&channel);
    connect(this->inbound_channel_, SIGNAL(dataSent(QByteArray)), this->outbound_channels_.last(), SLOT(onDataAvaliable(QByteArray)));

}
void OneToManyPipeline::addOutboundChannel(Node &sink){
    setOutboundChannel(sink);
}

#include "pipeline/onetomanypipeline.h"

OneToManyPipeline::OneToManyPipeline(QObject *parent) : QObject(parent),
                                                        outbound_channels_(0)
{

}

void OneToManyPipeline::setInboundChannel(DataSink &channel){
    this->inbound_channel_ = &channel;

}

void OneToManyPipeline::setOutboundChannel(DataSource &channel){
    this->outbound_channels_.push_back(&channel);
    connect(this->inbound_channel_, SIGNAL(dataSent(QByteArray)), this->outbound_channels_.last(), SLOT(onDataAvaliable(QByteArray)));

}
void OneToManyPipeline::addOutboundChannel(DataSource &sink){
    setOutboundChannel(sink);
}

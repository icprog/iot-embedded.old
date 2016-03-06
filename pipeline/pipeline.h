#ifndef PIPELINE_H
#define PIPELINE_H

#include "node.h"

class Pipeline {
public:
    virtual ~Pipeline() {}
    virtual void setInboundChannel(Node &channel) = 0;
    virtual void setOutboundChannel(Node &channel) = 0;
};


#include <QObject>
#define Pipeline_iid "com.jmssolutions.iot.embedded.Pipeline"
Q_DECLARE_INTERFACE(Pipeline, Pipeline_iid)


#endif // PIPELINE_H

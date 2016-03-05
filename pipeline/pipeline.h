#ifndef PIPELINE_H
#define PIPELINE_H

#include "datasink.h"
#include "datasource.h"


class Pipeline {
public:
    virtual ~Pipeline() {}
    virtual void setInboundChannel(DataSink &channel) = 0;
    virtual void setOutboundChannel(DataSource &channel) = 0;
};


#include <QObject>
#define Pipeline_iid "com.jmssolutions.iot.embedded.Pipeline"
Q_DECLARE_INTERFACE(Pipeline, Pipeline_iid)


#endif // PIPELINE_H

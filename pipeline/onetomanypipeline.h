#ifndef ONETOMANYPIPELINE_H
#define ONETOMANYPIPELINE_H

#include <QObject>
#include <QVector>

#include "pipeline.h"

class OneToManyPipeline : public QObject, public Pipeline
{
    Q_OBJECT
    Q_INTERFACES(Pipeline)

public:
    explicit OneToManyPipeline(QObject *parent = 0);

    void setInboundChannel(DataSink &channel) override final;
    void setOutboundChannel(DataSource &channel) override final;
    void addOutboundChannel(DataSource &sink);


signals:

public slots:

private:
    DataSink* inbound_channel_;
    QVector<DataSource*> outbound_channels_;
};

#endif // ONETOMANYPIPELINE_H

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

    void setInboundChannel(Node *channel) override final;
    void setOutboundChannel(Node *channel) override final;
    void addOutboundChannel(Node *sink);


signals:

public slots:

private:
    Node* inbound_channel_;
    QVector<Node*> outbound_channels_;
};

#endif // ONETOMANYPIPELINE_H

#ifndef DUMMYENDPOINT_H
#define DUMMYENDPOINT_H

#include <QObject>
#include <QThread>

#include "endpoint.h"
#include "worker.h"

class DummyEndpoint : public QObject, public Endpoint
{
    Q_OBJECT
    Q_INTERFACES(Endpoint)

public:
    explicit DummyEndpoint(QObject *parent = 0);

    DataSource &getSource() override;
    DataSink &getSink() override;


signals:

public slots:


private:
    Worker *worker_;
    QThread thread_;



};

#endif // DUMMYENDPOINT_H

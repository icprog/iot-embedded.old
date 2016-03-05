#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0) : QObject(parent) {}
    virtual ~Worker() {}

    virtual void process() = 0;

public slots:
    virtual void onDataAvaliable() = 0;

signals:
    void processingFinished();
};

#endif // WORKER_H

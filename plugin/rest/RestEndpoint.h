#ifndef RESTENDPOINT_H
#define RESTENDPOINT_H

#include <QObject>
#include <QSettings>
#include "node.h"

class RestEndpoint : public Node
{
public:
    RestEndpoint(const QString &name, QObject *parent = 0);
    QString getName() override final;
//    QSettings *getSettings() const;

public slots:
    virtual void onDataReceived(ConcurrentQueue<DataItem>* queue) override;
    virtual void start() override;
    virtual void stop() override;

private:
    const static QString TAG;
    QString name_;
    QSettings *settings;
};

#endif // RESTENDPOINT_H

#ifndef RESTENDPOINT_H
#define RESTENDPOINT_H

#include <QObject>
#include <QSettings>
#include <QNetworkAccessManager>
#include <ConnectivityNode.h>

class RestEndpoint : public ConnectivityNode
{
    Q_OBJECT
public:
    RestEndpoint(const QString &name, QObject *parent = 0);
    QString getName() override final;

public slots:
    virtual void sendData(DataItem data) override;
    virtual void start() override;
    virtual void stop() override;

private:
    const static QString TAG;
    QString name_;
    QSettings *settings;

    QNetworkAccessManager *network_manager_;
};

#endif // RESTENDPOINT_H

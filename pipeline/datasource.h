#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QByteArray>

class DataSource : public QObject{
public:
    Q_OBJECT

public slots:
    virtual void onDataAvaliable(QByteArray data) = 0;

signals:
    void dataReceived();

};

#endif // DATASOURCE_H

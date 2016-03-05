#ifndef DATASINK_H
#define DATASINK_H

#include <QObject>
#include <QByteArray>

class DataSink : public QObject{
public:
    Q_OBJECT

public slots:
    virtual void onDataReady() = 0;

signals:
    void dataSent(QByteArray data);

};


#endif // DATASINK_H

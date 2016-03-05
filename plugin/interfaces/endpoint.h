#ifndef ENDPOINT_H
#define ENDPOINT_H

#include "datasink.h"
#include "datasource.h"


class Endpoint {
public:
    virtual ~Endpoint() {}

    virtual DataSource &getSource() = 0;
    virtual DataSink &getSink() = 0;

};


#include <QObject>
#define Endpoint_iid "com.jmssolutions.iot.embedded.plugin.Endpoint"
Q_DECLARE_INTERFACE(Endpoint, Endpoint_iid)

#endif // ENDPOINT_H

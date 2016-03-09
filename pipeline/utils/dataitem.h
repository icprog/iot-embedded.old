#ifndef DATAITEM_H
#define DATAITEM_H

#include <QVariant>


class DataItem
{
public:
    DataItem();

    QVariantMap header() const;
    void setHeader(const QVariantMap &header);

    QVariantMap payload() const;
    void setPayload(const QVariantMap &payload);

private:
    QVariantMap header_;
    QVariantMap payload_;
};

#endif // DATAITEM_H

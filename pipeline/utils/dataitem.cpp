#include "dataitem.h"

DataItem::DataItem()
{

}

QVariantMap DataItem::header() const
{
    return header_;
}

void DataItem::setHeader(const QVariantMap &header)
{
    header_ = header;
}

QVariantMap DataItem::payload() const
{
    return payload_;
}

void DataItem::setPayload(const QVariantMap &payload)
{
    payload_ = payload;
}

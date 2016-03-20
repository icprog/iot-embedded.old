#ifndef DATAITEM_H
#define DATAITEM_H

#include <QVariant>
#include <QTime>


/**
 * @brief The DataItem class
 * @details Common representation of data
 */
class DataItem
{
public:
    DataItem();


    QVariantMap &payload() ;
    void setPayload(const QVariantMap &payload);

    QTime sendTime() const;
    void setSendTime(const QTime &send_time);

    QByteArray senderId() const;
    void setSenderId(const QByteArray &sender_id);

    QByteArray payloadType() const;
    void setPayloadType(const QByteArray &payload_type);

private:
    QByteArray payload_type_;
    QByteArray sender_id_;
    QTime   send_time_;
    QVariantMap payload_;
};

#endif // DATAITEM_H

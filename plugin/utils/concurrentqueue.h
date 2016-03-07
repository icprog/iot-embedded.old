#ifndef CONCURRENTQUEUE_H
#define CONCURRENTQUEUE_H

#include <QObject>
#include <QQueue>
#include <QMutex>

template <typename T>
class ConcurrentQueue final : public QObject
{
    Q_OBJECT
public:
    explicit ConcurrentQueue(QObject *parent = 0);

    void enqueue(const T &item);
    T& dequeue();



private:
    QQueue<T> queue_;
    QMutex lock;
};

#endif // CONCURRENTQUEUE_H

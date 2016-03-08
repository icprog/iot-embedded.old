#ifndef CONCURRENTQUEUE_H
#define CONCURRENTQUEUE_H

#include <QQueue>
#include <QMutex>

template <typename T>
class ConcurrentQueue final
{
public:
    ConcurrentQueue():{ }

    void enqueue(const T &item){
        QMutexLocker locker(&this->lock);
        this->queue_.enqueue(item);
    }

    T& dequeue(){
        QMutexLocker locker(&this->lock);
        return this->queue_.dequeue();
    }



private:
    QQueue<T> queue_;
    QMutex lock;


    const static QString TAG;
};

#endif // CONCURRENTQUEUE_H

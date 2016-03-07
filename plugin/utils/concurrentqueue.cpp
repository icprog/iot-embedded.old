#include "concurrentqueue.h"

ConcurrentQueue::ConcurrentQueue(QObject *parent) : QObject(parent)
{

}

void ConcurrentQueue::enqueue(const T &item)
{
    QMutexLocker locker(&this->lock);
    this->queue_.enqueue(item);


}

T &ConcurrentQueue::dequeue()
{
    QMutexLocker locker(&this->lock);
    return this->queue_.dequeue();
}

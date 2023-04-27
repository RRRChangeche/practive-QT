
#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

void Worker::run()
{
    // Threadpool runs this code

    for (int i = 0; i < 10; i ++){
        // lock
//        m_mutex->lock();  // we use QThreadLocker instead
        QMutexLocker locker(m_mutex);   // Lock the m_mutex - pay attention to SCOPE (recommended!)
        // unlock automatically from locker (Once m_mutex is out of the scope)

        int value = *m_count;
        value++;
        *m_count = value;   // DANGER!!! modifying value from different threads at the same time

        qInfo() << QThread::currentThread() << *m_count;
//        QThread::currentThread()->msleep(1000);

        // unlock
//        m_mutex->unlock();
        // unlock automatically from locker (Once m_mutex is out of the scope)
    }

    qInfo() << QThread::currentThread() <<"Done";
}

void Worker::setCount(int *newCount)
{
    m_count = newCount;
}

void Worker::setMutex(QMutex *newMutex)
{
    m_mutex = newMutex;
}


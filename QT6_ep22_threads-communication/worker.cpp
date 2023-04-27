
#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    m_producer = false;
    m_count = 0;
}

bool Worker::producer() const
{
    return m_producer;
}

void Worker::setProducer(bool newProducer)
{
    m_producer = newProducer;
}

void Worker::consume(int value)
{
    qInfo() << this << "Comsuming " << value << QThread::currentThread();

}

void Worker::start()
{
    qInfo() << this << "Starting " << QThread::currentThread();
    m_timer = new QTimer(this); // if remove pointer*, it would cause error

    connect(m_timer, &QTimer::timeout, this, &Worker::timeout);
    // timer timeout fires worker's timeout
    // all happening in the same thread

    if (m_producer){
        qInfo() << this << "Starting " << "timer "<< QThread::currentThread();
        m_timer->setInterval(1000);
        m_timer->start();
    }
}

void Worker::quit()
{
    qInfo() << this << "Quitting " << QThread::currentThread();
    m_timer->stop();
    emit finished();
}

void Worker::timeout()
{
    int value = QRandomGenerator::global()->bounded(1000);
    qInfo() << this << "Producing: " << value << QThread::currentThread();
    emit produced(value);
    m_count++;
    if (m_count == 5) quit();
}


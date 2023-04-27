
#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread(); // Q_FUNC_INFO print all of function info on the screen
}

Worker::~Worker()
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();
}

void Worker::run()
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();

    qInfo() << this << "Starting..." << QThread::currentThread();

    QScopedPointer<QEventLoop> loop(new QEventLoop); // pointers would automatically be deleted by QScopedPointer once out of scope (this function)
    QScopedPointer<QTimer> timer(new QTimer);   // we need to create things pointers in the thread that things need to be runnung on

    timer->setInterval(2000);   // timer is asynchronous, not actually threaded

    connect(timer.data(), &QTimer::timeout, this, &Worker::work, Qt::DirectConnection); // The slot is invoked immediately when the signal is emitted. The slot is executed in the signalling thread.
    connect(this, &Worker::finished, loop.data(), &QEventLoop::quit, Qt::DirectConnection);
    // If we start working with your know pointes out in run function, you're have to make sure that those signal and slots are firing in the same thread (using Qt::DirectConnection) in testPool() case

    timer->start();
    loop->exec();   // exec() block our current thread, wait until quit() to exit, quit will stop blocking
    // Runs a loop in the background, the loop blocks the thread

    qInfo() << this << "Finished" << QThread::currentThread();

}

void Worker::work()
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();

    // TO DO
    emit finished();

}


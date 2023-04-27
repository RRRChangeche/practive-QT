
#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QRunnable>
#include <QDebug>
#include <QEventLoop>   // could pause the thread (lock it up), but still gets signals and slots at the same time
#include <QScopedPointer>
#include <QTimer>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
    void finished();


    // QRunnable interface
public:
    virtual void run() override;

public slots:
    void work();

};

#endif // WORKER_H

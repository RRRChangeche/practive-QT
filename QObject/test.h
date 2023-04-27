
#ifndef TEST_H
#define TEST_H


#include <QObject>
#include <QDebug>


class Test : public QObject
{
    Q_OBJECT
public:
    // Optionally add a parent to constructor for parent child hierarchy.
    // Parent will automatically delete all its children.
    // https://youtu.be/KugPAznC4Yo?t=302
    explicit Test(QObject *parent = nullptr);

    // https://doc.qt.io/qt-6/signalsandslots.html
signals:
    void close();

public slots:
    void do_stuff();

};

#endif // TEST_H

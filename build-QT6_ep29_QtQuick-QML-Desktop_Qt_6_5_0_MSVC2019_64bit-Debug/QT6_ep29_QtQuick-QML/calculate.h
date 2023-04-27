
#ifndef CALCULATE_H
#define CALCULATE_H


#include <QObject>
#include <QVariant>
#include <QtQml>
#include <QRandomGenerator>


class Calculate : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Calculate(QObject *parent = nullptr);

signals:
    void calculatedNumber(QVariant data);

public slots:
    void calculate(QVariant data);

};

#endif // CALCULATE_H


#include "calculate.h"

Calculate::Calculate(QObject *parent)
    : QObject{parent}
{

}

void Calculate::calculate()
{
    qInfo() << "I'm being called";
}



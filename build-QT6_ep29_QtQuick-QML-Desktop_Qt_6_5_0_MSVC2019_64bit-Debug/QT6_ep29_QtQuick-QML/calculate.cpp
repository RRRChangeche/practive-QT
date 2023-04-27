
#include "calculate.h"

Calculate::Calculate(QObject *parent)
    : QObject{parent}
{

}

void Calculate::calculate(QVariant data)
{
    bool isNum;
    int input = data.toInt(&isNum);
    int output = 0;

    if(isNum) {
        int randNUm = QRandomGenerator::global()->bounded(100);
        output = input * random;
    }
    else{
        qWarning() << "Not a number...!";
    }

    emit calculatedNumber(QVariant(output));

}


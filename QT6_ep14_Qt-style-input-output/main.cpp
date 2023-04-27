/*
 * QTextStream
 * https://doc.qt.io/qt-6/qtextstream.html#details
 *
 * QIODevice
 * https://doc.qt.io/qt-6/qiodevice.html
 *
 *
*/
#include <QCoreApplication>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QTextStream
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    // endl
    qout << "Please enter your name:" << Qt::endl;  // \n and flush in endl

    // Reading
    QString name = qin.readLine();
    qout << name << Qt::endl;

    // Flushing
    qout << "You entered: " << name << "\n";
    qout << "Enter your age:\n";
    qout.flush();

    // Example
    bool ok;
    int age = qin.readLine().toInt(&ok);

    if (ok){
        qout << "You are " << age << " years old";
    }
    else{
        qout << "You failed to enter a valid number";
    }
    qout.flush();

    return a.exec();
}

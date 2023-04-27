/*
 * QString - Qts String class
 * Also touch on QChar
 *
 * 1. Creating string
 * 2. Reading each char
 *
 * each elements in QString is QChar
 *
 * 3. Comparing and searching
 * 4. Modfiying and parsing
 *
 * Escape sequence in C++
 * https://en.cppreference.com/w/cpp/language/escape
 *
 * 5. Conversion
 * 6. Not a QObject
*/
#include <QCoreApplication>
#include <iostream>

void test(QString data){
    qInfo() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    // Creating
    QString line("Hello World");
    qInfo() << line;

    QString name;
    name = "Al";
    qInfo() << name;

    int pos = 504;
    int max = 7439;
    QString status = QString("Processing file %1 of %2").arg(pos).arg(max);
    qInfo() << status;


    // Reading each char
    for (int i = 0; i < line.length(); i++){
        QChar c = line.at(i);
        qInfo() << c;
    }

    // Comparing and searching
    qInfo() << "Compare" << line.compare("hello world", Qt::CaseSensitivity::CaseInsensitive);  // ignore the case
    qInfo() << "Compare" << line.compare("hello world", Qt::CaseSensitivity::CaseSensitive);  // ignore the case
    qInfo() << "Starts" << line.startsWith("hello", Qt::CaseInsensitive);  // ignore the case
    qInfo() << "Ends" << line.endsWith("world", Qt::CaseInsensitive);  // ignore the case
    qInfo() << "Contains" << line.contains("world");  // default is CaseSensitive
    qInfo() << "Index" << line.indexOf("World");  // return where the word is

    // Modifying and parsing
//    line.append("\r\n Today Bob said \"Hello wife\" how are you"); // windows use \r\n for newline
    line.append("\r\n How are you?");
    qInfo() << "Escape" << line;

    line.append("\r\n<i>ThisM/</i> is HTML<br>");
    qInfo() << "HTML" << line.toHtmlEscaped();

    line.replace("?", "!");
    qInfo() << "Replaced" << line;

    qInfo() << "Upper" << line.toUpper();
    qInfo() << "Lower" << line.toLower();
    qInfo() << "Mid" << line.mid(3, 5);

    QStringList list = line.split("\n");
    foreach (QString item, list) {
        qInfo() << "item" << item.trimmed();    // trimmed remove white space char
    }


    // Conversion from Qt to std C++
    std::cout << "std " << line.toStdString() << std::endl;

    qInfo() << "UTF8" << line.toUtf8();
    qInfo() << "Base64" << line.toUtf8().toBase64();
    qInfo() << "Hex" << line.toUtf8().toHex();

    // Not a QObject
    test(line);


    return a.exec();
}

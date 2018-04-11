#ifndef DECODE_H
#define DECODE_H

#include <QString>
#include <QCryptographicHash>
#include <QTextStream>
#include <QFile>
#include <steg.h>
#include <aes.h>
#include <QList>

class Decode
{
public:
    Decode(QByteArray audioFileDir, QByteArray hash, QByteArray inputPassword, QByteArray &status);
private:
    void setTextToFile(QByteArray fileDir, QByteArray text);
    bool checkSum(QByteArray hash, QByteArray text);
    QByteArray hashing(QByteArray text, bool isKey);
    void decrypt(QByteArray &text, QByteArray encKey);
    QByteArray extract(QByteArray audioFileDir);
    void devider(QByteArray message, QByteArray &encKey, QByteArray &password, QByteArray &text);
    void makeDir(QByteArray audioFileDir, QByteArray &textOutFileDir);
};

#endif // DECODE_H

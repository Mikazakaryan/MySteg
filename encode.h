#ifndef Encode_H
#define Encode_H

#include <QString>
#include <QCryptographicHash>
#include <QTextStream>
#include <QFile>
#include <QTime>
#include <steg.h>

class Encode
{
public:
    Encode(QByteArray audioFileDir, QByteArray textFileDir, QByteArray password, QByteArray &status);

private:
    void outHash(QByteArray text, QByteArray dir);
    void keyGenerator(QByteArray &encKey);
    QByteArray getTextFromFile(QByteArray fileDir);
    QByteArray hashing(QByteArray text, bool isKey);
    void encrypt(QByteArray &text);
    QByteArray prepareToHide(QByteArray text, QByteArray encKey, QByteArray password);
    void hide(QByteArray audioFileDir, QByteArray audioOutFileDir, QByteArray text);
    void makeDirs(QByteArray audioFileDir, QByteArray &audioOutFileDir, QByteArray &hashFileDir);

};

#endif // Encode_H

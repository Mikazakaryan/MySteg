#ifndef Steg_H
#define Steg_H

#include "QString"

class Steg
{
    QString inputfilename;
    QString outputfilename;
    QByteArray Message;
public:
    Steg();
    void Setinput(QString);
    void Setoutput(QString);
    void Setmessage(QByteArray);
    int Encode();
    QByteArray Decode();
};


#endif // Steg_H

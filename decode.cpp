#include "decode.h"

Decode::Decode(QByteArray audioFileDir, QByteArray hash, QByteArray inputPassword, QByteArray &status)
{
    QByteArray message = extract(audioFileDir);
    QByteArray text;
    QByteArray encKey;
    QByteArray password;
    devider(message, encKey, password, text);
    if(hashing(inputPassword, true) != password){
        status = "Wrong pass";
    }else{
        decrypt(text);
        QByteArray textOutFileDir;
        makeDir(audioFileDir, textOutFileDir);
        setTextToFile(textOutFileDir, text);
        if(!checkSum(hash, text)){
            status = "Done, but hashes aint same";
        }else{
            status = "Done";
        }
    }
}

bool Decode::checkSum(QByteArray hashFile, QByteArray text){
    QFile file(hashFile);
    QString hash;
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          hash += line;
       }
       file.close();
    }
    text = hashing(text, false);
    if(QString::fromStdString(text.toStdString()) == hash){
        return true;
    }else{
        return false;
    }
}

void Decode::devider(QByteArray message, QByteArray &encKey, QByteArray &password, QByteArray &text){
    for (int i = 0; i < 32; ++i) {
        password.push_back(message[i]);
        encKey.push_back(message.at(i + 32));
    }
    message.remove(0, 64);
    text = message;
}

void Decode::makeDir(QByteArray audioFileDir, QByteArray &textOutFileDir){
    QByteArray dir;
    bool sudo = false;
    for (int i = audioFileDir.size() - 1; i >= 0; --i) {
        if(!sudo && audioFileDir[i] == '/'){
            sudo = true;
        }
        if(sudo){
            dir.push_front(audioFileDir[i]);
        }
    }
    textOutFileDir = dir + "out.txt";
}

QByteArray Decode::setTextToFile(QByteArray fileDir, QByteArray text){
    QFile file(fileDir);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << text;
    }
   file.close();
}

QByteArray Decode::hashing(QByteArray text, bool isKey){
    if(isKey){
        return QCryptographicHash::hash(text, QCryptographicHash::Sha256);
    }else{
        return QCryptographicHash::hash(text, QCryptographicHash::Sha512);
    }
}

void Decode::decrypt(QByteArray &text){

}

QByteArray Decode::extract(QByteArray audioFileDir){
    Steg steg;
    steg.Setinput(audioFileDir);
    return steg.Decode();
}
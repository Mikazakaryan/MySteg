#include "encode.h"

Encode::Encode(QByteArray audioFileDir, QByteArray textFileDir, QByteArray password, QByteArray &status) {
    QByteArray encKey;
    QByteArray text = getTextFromFile(textFileDir);
    QByteArray audioOutFileDir;
    QByteArray hashFileDir;
    makeDirs(audioFileDir, audioOutFileDir, hashFileDir);
    outHash(text, hashFileDir);
    keyGenerator(encKey);
    encrypt(text);
    QByteArray readyText = prepareToHide(text, encKey, password);
    hide(audioFileDir, audioOutFileDir, readyText);
    status = "done";
}

void Encode::makeDirs(QByteArray audioFileDir, QByteArray &audioOutFileDir, QByteArray &hashFileDir){
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
    audioOutFileDir = dir + "out.wav";
    hashFileDir = dir + "hash.txt";
}

void Encode::outHash(QByteArray text, QByteArray dir){
    QByteArray hashedText = hashing(text, false);
    QFile file(dir);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << hashedText;
    }
    file.close();
}

void Encode::keyGenerator(QByteArray &encKey){
    encKey = QByteArray::fromStdString(QTime::currentTime().toString().toStdString());
}

QByteArray Encode::getTextFromFile(QByteArray fileDir){
    QFile file(fileDir);
    QString text;
    if (file.open(QIODevice::ReadOnly)) {
       QTextStream in(&file);
       while (!in.atEnd()) {
          QString line = in.readLine();
          text += line;
       }
       file.close();
    }
    return text.toLatin1();
}

QByteArray Encode::hashing(QByteArray text, bool isKey){
    if(isKey) {
        return QCryptographicHash::hash(text, QCryptographicHash::Sha256);
    } else {
        return QCryptographicHash::hash(text, QCryptographicHash::Sha512);
    }
}

void Encode::encrypt(QByteArray &text){

}

QByteArray Encode::prepareToHide(QByteArray text, QByteArray encKey, QByteArray password){
    return hashing(password, true) + hashing(encKey, true) + text;
}

void Encode::hide(QByteArray audioFileDir, QByteArray audioOutFileDir, QByteArray text){
    Steg steg;
    steg.Setinput(audioFileDir);
    steg.Setoutput(audioOutFileDir);
    steg.Setmessage(text);
    steg.Encode();
}

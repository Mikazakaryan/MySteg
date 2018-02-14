#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QLineEdit>
#include "encode.h"
#include "decode.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void encodeSlot();
    void decodeSlot();
    void exitSlot();

    void audioFileBrowseSlot();
    void textFileBrowseSlot();
    void hashFileBrowseSlot();
    void encodingSlot();
    void decodingSlot();

private:
    QString m_password;
    QString m_audioDir;
    QString m_textDir;
    QString m_hashDir;

    QWidget *m_window = new QWidget();
    QFont m_font;

    QVBoxLayout *m_menuLayout = new QVBoxLayout();
    QLabel *m_header = new QLabel();
    QPushButton *m_encode = new QPushButton();
    QPushButton *m_decode = new QPushButton();
    QPushButton *m_exit = new QPushButton();

    QVBoxLayout *m_encodePage = new QVBoxLayout();
    QVBoxLayout *m_encodePageLayout = new QVBoxLayout();
    QLabel *m_status = new QLabel();

    QWidget *m_inputLine = new QWidget();
    QVBoxLayout *m_lines = new QVBoxLayout();
    QHBoxLayout *m_audioFileLine = new QHBoxLayout();
    QHBoxLayout *m_textFileLine = new QHBoxLayout();

    QLabel *m_audioFileDir = new QLabel();
    QPushButton *m_audioFileBrowse = new QPushButton();

    QLabel *m_textFileDir = new QLabel();
    QPushButton *m_textFileBrowse = new QPushButton();

    QWidget *m_passwordWidget = new QWidget();
    QHBoxLayout *m_passwordLine = new QHBoxLayout();
    QLabel *m_passwordLabel = new QLabel();
    QLineEdit *m_passwordInput = new QLineEdit();
    QPushButton *m_exitEncode = new QPushButton();
    QPushButton *m_encodeButton = new QPushButton();

    QVBoxLayout *m_decodePageLayout = new QVBoxLayout();
    QPushButton *m_decodeButton = new QPushButton();
    QPushButton *m_exitDecode = new QPushButton();
    QPushButton *m_hashFileBrowse = new QPushButton();
    QHBoxLayout *m_hashFileLine = new QHBoxLayout();
    QLabel *m_hashFileDir = new QLabel();

    QVBoxLayout *m_decodePage = new QVBoxLayout();

};

#endif // MAINWINDOW_H

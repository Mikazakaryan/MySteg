#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDeleteAll(m_window->children());
    setCentralWidget(m_window);

    m_menuLayout->setAlignment(Qt::AlignTop);

    m_font.setPixelSize(20);

    m_header->setText("this is header you piece of shit");
    m_header->setAlignment(Qt::AlignHCenter);
    m_header->setFont(m_font);

    m_encode->setText("Hide");
    m_encode->setFont(m_font);

    m_decode->setText("Extract");
    m_decode->setFont(m_font);

    m_exit->setText("Exit");
    m_exit->setFont(m_font);

    m_window->setLayout(m_menuLayout);

    m_menuLayout->addWidget(m_header);
    m_menuLayout->addWidget(m_encode);
    m_menuLayout->addWidget(m_decode);
    m_menuLayout->addWidget(m_exit);

    connect(m_encode, SIGNAL(clicked()), this, SLOT(encodeSlot()));
    connect(m_decode, SIGNAL(clicked()), this, SLOT(decodeSlot()));
    connect(m_exit, SIGNAL(clicked()), this, SLOT(exitSlot()));
}

void MainWindow::encodeSlot(){
    qDeleteAll(m_window->children());
    setCentralWidget(m_window);

    m_status->setText("this is status ffs");
    m_status->setFont(m_font);

    m_status->setAlignment(Qt::AlignHCenter);

    m_inputLine->setLayout(m_lines);
    m_lines->addLayout(m_audioFileLine);
    m_lines->addLayout(m_textFileLine);

    m_audioFileDir->setText("Choose audio file");
    m_audioFileBrowse->setText("Browse");
    m_audioFileLine->addWidget(m_audioFileDir);
    m_audioFileLine->addWidget(m_audioFileBrowse);

    m_textFileDir->setText("Choose text file");
    m_textFileBrowse->setText("Browse");
    m_textFileLine->addWidget(m_textFileDir);
    m_textFileLine->addWidget(m_textFileBrowse);

    m_encodeButton->setText("Encode");

    m_passwordWidget->setLayout(m_passwordLine);

    m_passwordLabel->setText("Password");
    m_passwordLine->addWidget(m_passwordLabel);

    m_passwordInput->setEchoMode(QLineEdit::Password);
    m_passwordLine->addWidget(m_passwordInput);

    m_exitEncode->setText("Exit");
    m_exitEncode->setFont(m_font);

    m_encodeButton->setFont(m_font);

    m_encodePageLayout->addWidget(m_status);
    m_encodePageLayout->addWidget(m_inputLine);
    m_encodePageLayout->addWidget(m_passwordWidget);
    m_encodePageLayout->addWidget(m_encodeButton);
    m_encodePageLayout->addWidget(m_exitEncode);

    m_window->setLayout(m_encodePageLayout);

    connect(m_audioFileBrowse, SIGNAL(clicked()), this, SLOT(audioFileBrowseSlot()));
    connect(m_textFileBrowse, SIGNAL(clicked()), this, SLOT(textFileBrowseSlot()));
    connect(m_encodeButton, SIGNAL(clicked()), this, SLOT(encodingSlot()));
    connect(m_exitEncode, SIGNAL(clicked()), this, SLOT(exitSlot()));
}

void MainWindow::audioFileBrowseSlot(){
    QString temp = "";
    temp = QFileDialog::getOpenFileName(this, "Select an audio file to open...", "", "*.wav");
    m_audioDir = temp;
    if(m_audioDir != ""){
        m_audioFileBrowse->setStyleSheet("background-color: green");
    }else{
        m_audioFileBrowse->setStyleSheet("background-color: red");
    }
}

void MainWindow::textFileBrowseSlot(){
    QString temp = "";
    temp = QFileDialog::getOpenFileName(this, "Select a text file to open...", "", "*.txt");
    m_textDir = temp;
    if(m_textDir != ""){
        m_textFileBrowse->setStyleSheet("background-color: green");
    }else{
        m_textFileBrowse->setStyleSheet("background-color: red");
    }
}

void MainWindow::hashFileBrowseSlot(){
    QString temp = "";
    temp = QFileDialog::getOpenFileName(this, "Select a hash file to open...", "", "*.txt");
    m_hashDir = temp;
    if(m_hashDir != ""){
        m_hashFileBrowse->setStyleSheet("background-color: green");
    }else{
        m_hashFileBrowse->setStyleSheet("background-color: red");
    }
}

void MainWindow::encodingSlot(){
    m_status->setStyleSheet("color: red");
    m_password = m_passwordInput->text();
    if(m_audioDir.isEmpty()){
        m_status->setText("No audio file");
    }else if(m_textDir.isEmpty()){
        m_status->setText("No text file");
    }else if(m_password.isEmpty()){
        m_status->setText("Empty password");
    }else{
        m_status->setText("oka aziz");
        m_status->setStyleSheet("color: green");
        QByteArray status;
        Encode enc(m_audioDir.toLatin1(), m_textDir.toLatin1(), m_password.toLatin1(), status);
        m_status->setText(QString::fromLatin1(status));
    }
}

void MainWindow::decodingSlot(){
    m_status->setStyleSheet("color: red");
    m_password = m_passwordInput->text();
    if(m_audioDir.isEmpty()){
        m_status->setText("No audio file");
    }else if(m_hashDir.isEmpty()){
        m_status->setText("Empty hash file");
    }else if(m_password.isEmpty()){
        m_status->setText("Empty password");
    }else{
        m_status->setText("oka aziz");
        m_status->setStyleSheet("color: green");
        QByteArray status;
        Decode dec(m_audioDir.toLatin1(), m_hashDir.toLatin1(), m_password.toLatin1(), status);
        if(status != "Done"){
            m_status->setStyleSheet("color: red");
        }
        m_status->setText(QString::fromLatin1(status));
    }
}

void MainWindow::decodeSlot(){
    qDeleteAll(m_window->children());
    setCentralWidget(m_window);

    m_status->setText("this is status ffs");
    m_status->setFont(m_font);

    m_status->setAlignment(Qt::AlignHCenter);

    m_inputLine->setLayout(m_lines);

    m_lines->addLayout(m_audioFileLine);
    m_lines->addLayout(m_hashFileLine);

    m_audioFileDir->setText("Choose audio file");
    m_audioFileBrowse->setText("Browse");
    m_audioFileLine->addWidget(m_audioFileDir);
    m_audioFileLine->addWidget(m_audioFileBrowse);

    m_hashFileDir->setText("Choose hash file");
    m_hashFileBrowse->setText("Browse");
    m_hashFileLine->addWidget(m_hashFileDir);
    m_hashFileLine->addWidget(m_hashFileBrowse);

    m_decodeButton->setText("Decode");

    m_passwordWidget->setLayout(m_passwordLine);

    m_passwordLabel->setText("Password");
    m_passwordLine->addWidget(m_passwordLabel);

    m_passwordInput->setEchoMode(QLineEdit::Password);
    m_passwordLine->addWidget(m_passwordInput);

    m_exitDecode->setText("Exit");
    m_exitDecode->setFont(m_font);

    m_decodeButton->setFont(m_font);

    m_decodePageLayout->addWidget(m_status);
    m_decodePageLayout->addWidget(m_inputLine);
    m_decodePageLayout->addWidget(m_passwordWidget);
    m_decodePageLayout->addWidget(m_decodeButton);
    m_decodePageLayout->addWidget(m_exitDecode);

    m_window->setLayout(m_decodePageLayout);

    connect(m_audioFileBrowse, SIGNAL(clicked()), this, SLOT(audioFileBrowseSlot()));
    connect(m_hashFileBrowse, SIGNAL(clicked()), this, SLOT(hashFileBrowseSlot()));
    connect(m_decodeButton, SIGNAL(clicked()), this, SLOT(decodingSlot()));
    connect(m_exitDecode, SIGNAL(clicked()), this, SLOT(exitSlot()));
}

void MainWindow::exitSlot(){
    close();
}

MainWindow::~MainWindow()
{
    qDeleteAll(m_window->children());
    delete m_window;
}

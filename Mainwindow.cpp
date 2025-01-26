#include "MainWindow.h"
#include "MainWindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QTextEdit>

#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    //, ui(new MainWindow())
    , smtpClient(new SmtpClient(this))
    , pop3Client(new Pop3Client(this))
{

    //mainWidget = new QWidget(this);
    mainWidget = new QWidget(this);

    layout = new QVBoxLayout(mainWidget);
    
    hostEdit = new QLineEdit();
    portEdit = new QLineEdit();
    userEdit = new QLineEdit();
    passwordEdit = new QLineEdit();
    fromEdit = new QLineEdit();
    toEdit = new QLineEdit();
    subjectEdit = new QLineEdit();
    bodyEdit = new QPlainTextEdit();
   


    hostLabel =     new QLabel("SerwerName:", hostEdit);
    hostLabel->setAlignment(Qt::Alignment::enum_type::AlignTop);
    portLabel =     new QLabel("Port:", portEdit);
    userLabel =     new QLabel("UserName:", userEdit);
    passwordLabel = new QLabel("Password:", passwordEdit);
    fromLabel =     new QLabel("From:", fromEdit);
    toLabel =       new QLabel("To:", toEdit);
    subjectLabel =  new QLabel("Title:", subjectEdit);
    bodyLabel =     new QLabel("Email content", bodyEdit);


    sendButton = new QPushButton("Send email");
    
    hostEdit->setFixedHeight(45);
    portEdit->setFixedHeight(45);
    userEdit->setFixedHeight(45);
    passwordEdit->setFixedHeight(45);
    fromEdit->setFixedHeight(45);
    toEdit->setFixedHeight(45);
    subjectEdit->setFixedHeight(45);

    layout->addWidget(hostEdit);
    layout->addWidget(portEdit);
    layout->addWidget(userEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(fromEdit);
    layout->addWidget(toEdit);
    layout->addWidget(subjectEdit);
    layout->addWidget(bodyEdit);
    layout->addWidget(sendButton);

    connect(this->sendButton, SIGNAL(clicked()), this, SLOT(on_sendButton_clicked()));
    
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    QString host = hostEdit->text();
    quint16 port = portEdit->text().toUShort();
    QString user = userEdit->text();
    QString password = passwordEdit->text();
    QString from = fromEdit->text();
    QString to = toEdit->text();
    QString subject = subjectEdit->text();
    QString body = bodyEdit->toPlainText();

    try {
        smtpClient->connectToServer("smtp.office365.com", 587);
        smtpClient->authenticate(user, password);
        smtpClient->sendMessage(from, to, subject, body);
        smtpClient->disconnectFromServer();
        QMessageBox::information(this, "Sukces", "Wiadomość została wysłana.");
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Błąd", e.what());
    }
}

void MainWindow::on_receiveButton_clicked()
{
    //QString host = ui->pop3ServerLineEdit->text();
    //quint16 port = ui->pop3PortLineEdit->text().toUShort();
    //QString user = ui->pop3UserLineEdit->text();
    //QString password = ui->pop3PasswordLineEdit->text();

    //try {
    //    pop3Client->connectToServer(host, port);
    //    pop3Client->authenticate(user, password);
    //    pop3Client->retrieveMessages();
    //    pop3Client->disconnectFromServer();
    //    QMessageBox::information(this, "Sukces", "Wiadomości zostały pobrane.");
    //}
    //catch (const std::exception& e) {
    //    QMessageBox::critical(this, "Błąd", e.what());
    //}
}

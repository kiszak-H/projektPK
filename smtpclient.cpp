#include "SmtpClient.h"
#include <QTextStream>
#include <QDebug>
#include<Windows.h>
#include <iostream> 

#include <qsslconfiguration.h>

SmtpClient::SmtpClient(QObject* parent)
    : EmailClient(parent)
{
    connect(socket, &QSslSocket::readyRead, this, &SmtpClient::onReadyRead);
    connect(socket, &QSslSocket::errorOccurred, this, &SmtpClient::onError);

}

SmtpClient::~SmtpClient()
{
    
}

void SmtpClient::connectToServer(const QString& host, quint16 port)
{
    QSslConfiguration conf = socket->sslConfiguration();
    conf.setPeerVerifyMode(QSslSocket::VerifyNone);
    conf.setProtocol(QSsl::TlsV1_2OrLater);
    socket->setSslConfiguration(conf);

    socket->connectToHostEncrypted(host, port);

    if (!socket->waitForConnected(30000)) {
        qWarning() << "Nie można połączyć z serwerem SMTP";
        throw std::runtime_error("Nie można połączyć z serwerem SMTP");
    }


}

void SmtpClient::authenticate(const QString& user, const QString& password)
{

    //this->user = user;
    //this->password = password;
    //QString messenge = "HELO localhost\r\n";

    //QByteArray data = messenge.toUtf8();
    //socket->write(data);

    //socket->waitForBytesWritten();
    //socket->write(QString("STARTTLS\r\n").toUtf8());
    //socket->waitForBytesWritten();
    //socket->startClientEncryption();
    //socket->write(QString("AUTH LOGIN\r\n").toUtf8());

    // Implementacja uwierzytelniania SMTP (np. AUTH LOGIN)
    // Należy zakodować dane w Base64
}

void SmtpClient::sendMessage(const QString& from, const QString& to, const QString& subject, const QString& body)
{


    // Implementacja wysyłania wiadomości SMTP
    // Należy wysłać odpowiednie komendy SMTP
}

void SmtpClient::disconnectFromServer()
{
    //socket->disconnectFromHost();
}

void SmtpClient::onReadyRead()
{
    lastResponse = socket->readAll();
    qDebug() << "SMTP Response:" << lastResponse;
    // Obsługa odpowiedzi z serwera SMTP
}

void SmtpClient::onError()
{
    std::cout << "ERROR: " << socket->errorString().toStdString() << std::endl;
}

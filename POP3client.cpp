#include "Pop3Client.h"
#include <QTextStream>
#include <QDebug>

Pop3Client::Pop3Client(QObject* parent)
    : EmailClient(parent)
{
    connect(socket, &QTcpSocket::readyRead, this, &Pop3Client::onReadyRead);
}

Pop3Client::~Pop3Client()
{
}

void Pop3Client::connectToServer(const QString& host, quint16 port)
{
    socket->connectToHost(host, port);
    if (!socket->waitForConnected(30000)) {
        qWarning() << "Nie można połączyć z serwerem POP3";
        throw std::runtime_error("Nie można połączyć z serwerem POP3");
    }
}

void Pop3Client::authenticate(const QString& user, const QString& password)
{
    this->user = user;
    this->password = password;
    // Implementacja uwierzytelniania POP3 (USER, PASS)
}

void Pop3Client::retrieveMessages()
{
    // Implementacja pobierania wiadomości z serwera POP3
}

void Pop3Client::disconnectFromServer()
{
    socket->disconnectFromHost();
}

void Pop3Client::onReadyRead()
{
    lastResponse = socket->readAll();
    qDebug() << "POP3 Response:" << lastResponse;
    // Obsługa odpowiedzi z serwera POP3
}

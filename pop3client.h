#ifndef POP3CLIENT_H
#define POP3CLIENT_H

#include "EmailClient.h"

class Pop3Client : public EmailClient
{
    Q_OBJECT
public:
    explicit Pop3Client(QObject* parent = nullptr);
    ~Pop3Client();

    void connectToServer(const QString& host, quint16 port) override;
    void authenticate(const QString& user, const QString& password) override;
    void retrieveMessages();
    void disconnectFromServer() override;

private slots:
    void onReadyRead();

private:
    QString lastResponse;
    QString user;
    QString password;
};

#endif // POP3CLIENT_H
#pragma once

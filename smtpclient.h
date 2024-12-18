#pragma once
#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include "EmailClient.h"

class SmtpClient : public EmailClient
{
    Q_OBJECT
public:
    explicit SmtpClient(QObject* parent = nullptr);
    ~SmtpClient();

    void connectToServer(const QString& host, quint16 port) override;
    void authenticate(const QString& user, const QString& password) override;
    void sendMessage(const QString& from, const QString& to, const QString& subject, const QString& body);
    void disconnectFromServer() override;

private slots:
    void onReadyRead();

private:
    QString lastResponse;
    QString user;
    QString password;
};

#endif // SMTPCLIENT_H

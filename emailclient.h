#pragma once
#ifndef EMAILCLIENT_H
#define EMAILCLIENT_H

#include <QObject>
#include <QSslSocket>
#include <QString>

class EmailClient : public QObject
{
    Q_OBJECT
public:
    explicit EmailClient(QObject* parent = nullptr);
    virtual ~EmailClient();

    virtual void connectToServer(const QString& host, quint16 port) = 0;
    virtual void authenticate(const QString& user, const QString& password) = 0;
    virtual void disconnectFromServer() = 0;

protected:
    QSslSocket* socket;
};

#endif // EMAILCLIENT_H

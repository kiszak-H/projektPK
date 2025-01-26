#include "EmailClient.h"

EmailClient::EmailClient(QObject* parent)
    : QObject(parent), socket(new QSslSocket(this))
{
}

EmailClient::~EmailClient()
{
   
}

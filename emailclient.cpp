#include "EmailClient.h"

EmailClient::EmailClient(QObject* parent)
    : QObject(parent), socket(new QTcpSocket(this))
{
}

EmailClient::~EmailClient()
{
   
}

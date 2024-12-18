#include "MainWindow.h"
#include "MainWindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , smtpClient(new SmtpClient(this))
    , pop3Client(new Pop3Client(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    QString host = ui->smtpServerLineEdit->text();
    quint16 port = ui->smtpPortLineEdit->text().toUShort();
    QString user = ui->smtpUserLineEdit->text();
    QString password = ui->smtpPasswordLineEdit->text();
    QString from = ui->fromLineEdit->text();
    QString to = ui->toLineEdit->text();
    QString subject = ui->subjectLineEdit->text();
    QString body = ui->bodyTextEdit->toPlainText();

    try {
        smtpClient->connectToServer(host, port);
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
    QString host = ui->pop3ServerLineEdit->text();
    quint16 port = ui->pop3PortLineEdit->text().toUShort();
    QString user = ui->pop3UserLineEdit->text();
    QString password = ui->pop3PasswordLineEdit->text();

    try {
        pop3Client->connectToServer(host, port);
        pop3Client->authenticate(user, password);
        pop3Client->retrieveMessages();
        pop3Client->disconnectFromServer();
        QMessageBox::information(this, "Sukces", "Wiadomości zostały pobrane.");
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this, "Błąd", e.what());
    }
}

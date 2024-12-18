#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SmtpClient.h"
#include "Pop3Client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
    void on_receiveButton_clicked();

private:
    Ui::MainWindow* ui;
    SmtpClient* smtpClient;
    Pop3Client* pop3Client;
};

#endif // MAINWINDOW_H
#pragma once

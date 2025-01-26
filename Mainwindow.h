#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SmtpClient.h"
#include "Pop3Client.h"

#include <qplaintextedit.h>
#include <qlineedit.h>
#include <qpushbutton.h>

#include <qlayout.h>

#include <qlabel.h>

#include <memory>

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
    QLabel* hostLabel;
    QLabel* portLabel;
    QLabel* userLabel;
    QLabel* passwordLabel;
    QLabel* fromLabel;
    QLabel* toLabel;
    QLabel* subjectLabel;
    QLabel* bodyLabel;


    QWidget*   mainWidget;
    QLineEdit* hostEdit;
    QLineEdit*  portEdit;
    QLineEdit* userEdit;
    QLineEdit* passwordEdit;
    QLineEdit* fromEdit;
    QLineEdit* toEdit;
    QLineEdit* subjectEdit;
    QPlainTextEdit* bodyEdit;

    QPushButton* sendButton;
   

    QVBoxLayout* layout;

    //Ui::MainWindow* ui;
    SmtpClient* smtpClient;
    Pop3Client* pop3Client;

    signals:
};

#endif // MAINWINDOW_H
#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void NetworkCleanup();
    void OnListReadFinished();

    ~MainWindow();

private slots:


    void on_pushButton_clicked();

private:
    QNetworkAccessManager *m_Manager;
    QNetworkRequest m_Request;
    QNetworkReply m_Reply;
    Ui::MainWindow *ui;
    const QString m_URL ="https://api.github.com";
    QString m_Profile;
    QByteArray* m_Buffer;
};
#endif // MAINWINDOW_H

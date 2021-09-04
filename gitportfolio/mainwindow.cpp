#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_Manager = new QNetworkAccessManager();
    QObject::connect(m_Manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *m_Reply) {
            if (m_Reply->error()) {
                qDebug() << m_Reply->errorString();
                return;
            }

            QString answer = m_Reply->readAll();

            qDebug() << answer;
        }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    m_Request.setUrl(QUrl(m_URL)) ;
    m_Manager->get(m_Request);
}


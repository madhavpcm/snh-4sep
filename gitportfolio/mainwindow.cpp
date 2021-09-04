#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_Reply(nullptr)

{
    ui->setupUi(this);

    m_Manager = new QNetworkAccessManager();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString usrname= ui->username->text();
    if(usrname.size() == 0){
        QMessageBox::information(this, "Username empty","Please Enter a github user name or URL");
        return;
    }

    m_Request.setUrl(QUrl(m_URL+"/users/"+usrname)) ;
    m_Reply= m_Manager->get(m_Request);

            if (m_Reply->error()) {
              QMessageBox::warning(this,"Network Error",m_Reply->errorString());
                return;
            }

            QString answer = m_Reply->readAll();
            m_Buffer = m_Reply->readAll();
            QMessageBox::information(this,"recieved",answer);
            m_GotUser = true;
}
void MainWindow::NetworkCleanup()
{
  m_Reply->deleteLater();
  m_Reply = nullptr;
  m_Buffer.clear();
}
void MainWindow::gotUser()
{

    QStringList propertyNames;
    QStringList propertyKeys;
    QString strReply = (QString)m_Reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();

}

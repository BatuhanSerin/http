#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::downloadfinished(QNetworkReply *rep){

    QByteArray bts = rep->readAll();
    QString str(bts);
    ui->plainTextEdit->setPlainText(str);

}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
       QNetworkAccessManager * mgr = new QNetworkAccessManager(this);
       connect(mgr,SIGNAL(finished(QNetworkReply*)),this,SLOT(downloadfinished(QNetworkReply*)));
       connect(mgr,SIGNAL(finished(QNetworkReply*)),mgr,SLOT(deleteLater()));

       mgr->get(QNetworkRequest(QUrl("https://api.openweathermap.org/data/2.5/weather?q=ankara&appid=95edf34d0dd7709f36b7ac7f67cf2399")));


}


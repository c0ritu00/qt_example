#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_btnGetAllPersons_clicked()
{
    QString site_url="http://localhost:3000/example/allpersons";
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    allPersonsManager = new QNetworkAccessManager(this);
    connect(allPersonsManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(allPersonsSlot(QNetworkReply*)));
    allPersonsReply = allPersonsManager->get(request);
}

void MainWindow::allPersonsSlot(QNetworkReply * reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc=QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString persons;
    foreach(const QJsonValue &value, json_array){
        QJsonObject json_obj=value.toObject();
        persons+=QString::number((json_obj["id_person"].toInt()))+" "+json_obj["fname"].toString()+"\r\n";
    }
    ui->labelResult->setText(persons);
    allPersonsReply->deleteLater();
    reply->deleteLater();
    allPersonsManager->deleteLater();
}

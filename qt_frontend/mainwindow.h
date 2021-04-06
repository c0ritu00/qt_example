#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGetAllPersons_clicked();
    void allPersonsSlot(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager * allPersonsManager;
    QNetworkReply * allPersonsReply;
};
#endif // MAINWINDOW_H

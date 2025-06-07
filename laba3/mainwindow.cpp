#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QEventLoop>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_interface = ClientInterface::getInstance();
    ClientInterface* interface2 = ClientInterface::getInstance();
    ClientInterface* interface3 = ClientInterface::getInstance();

    qDebug() << "m_interface = " << m_interface;
    qDebug() << "interface2 = " << interface2;
    qDebug() << "interface3 = " << interface3;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getButton_clicked()
{

    bool ok;
    int id = ui->idLineEdit->text().toInt(&ok);
    if (!ok) {
        qDebug() << "Invalid ID entered.";
        return;
    }

    Event result = m_interface->GetEvent(id);
    qDebug() << result;
}

void MainWindow::on_createButton_clicked()
{
    Event result = m_interface->CreateEvent();
    qDebug() << result;
}

void MainWindow::on_listButton_clicked()
{
    QList<Event> list = m_interface->GetEvents();
    for (const Event &p : list)
        qDebug() << p;
}

void MainWindow::on_updateButton_clicked()
{
    bool ok;
    int id = ui->idLineEdit->text().toInt(&ok);
    if (!ok) {
        qDebug() << "Invalid ID entered.";
        return;
    }

    Event result = m_interface->UpdateEvent(id);
    qDebug() << result;
}

void MainWindow::on_deleteButton_clicked()
{
    bool ok;
    int id = ui->idLineEdit->text().toInt(&ok);
    if (!ok) {
        qDebug() << "Invalid ID entered.";
        return;
    }

    bool result = m_interface->DeleteEvent(id);
    qDebug() << "Deleted:" << result;
}



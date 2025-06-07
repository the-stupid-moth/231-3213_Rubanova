#include "clientinterface.h"
#include <QJsonArray>


ClientInterface* ClientInterface::existing_object = nullptr;

ClientInterface::ClientInterface(QString& root_url) {
    m_root_url = root_url;
    m_client = new QNetworkAccessManager();
}

Event ClientInterface::GetEvent(int id) {
    QNetworkRequest request(QUrl(m_root_url + "event/" + QString::number(id) + "/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = m_client->get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return Event::fromJson(reply->readAll());
}

QList<Event> ClientInterface::GetEvents() {
    QNetworkRequest request(QUrl(m_root_url + "event/"));
    QNetworkReply* reply = m_client->get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray response = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(response);
    QJsonArray array = doc.array();

    QList<Event> result;
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        result.append(Event::fromJson(QJsonDocument(obj).toJson()));
    }
    return result;
}

Event ClientInterface::CreateEvent() {
    QJsonObject body;
    body["title"] = "Концерт";
    body["location"] = "Стадион";
    body["date"] = "2025-07-01";
    body["start_time"] = "19:00:00";
    body["is_free"] = false;
    body["ticket_price"] = 1500.00;

    QNetworkRequest request(QUrl(m_root_url + "event/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply* reply = m_client->post(request, QJsonDocument(body).toJson());

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return Event::fromJson(reply->readAll());
}

Event ClientInterface::UpdateEvent(int id) {
    QJsonObject body;
    body["location"] = "Арена";

    QNetworkRequest request(QUrl(m_root_url + "event/" + QString::number(id) + "/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply* reply = m_client->sendCustomRequest(request, "PATCH", QJsonDocument(body).toJson());

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return Event::fromJson(reply->readAll());
}

bool ClientInterface::DeleteEvent(int id) {
    QNetworkRequest request(QUrl(m_root_url + "event/" + QString::number(id) + "/"));
    QNetworkReply* reply = m_client->deleteResource(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    return reply->error() == QNetworkReply::NoError;
}


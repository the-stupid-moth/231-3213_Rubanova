#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QUrl>
#include "event.h"

class ClientInterface
{
public:
    // Singleton
    static ClientInterface* existing_object;
    static ClientInterface* getInstance() {
        QString root_url = "http://localhost/api/";
        if(existing_object == nullptr) {
            existing_object = new ClientInterface(root_url);
        }
        return existing_object;
    }

    static void removeInstance() {
        if(existing_object)
            delete existing_object;
        existing_object = nullptr;
    }

    Event GetEvent(int id);
    QList<Event> GetEvents();
    Event CreateEvent();
    Event UpdateEvent(int id);
    bool DeleteEvent(int id);


private:
    ClientInterface(QString& root_url);
    QNetworkAccessManager* m_client = nullptr;
    QString m_root_url;
};

#endif // CLIENTINTERFACE_H

#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

class Event
{
public:
    Event();
    Event(int id, QString title, QString location, QString date, QString start_time, bool is_free, double ticket_price);

    static Event fromJson(const QByteArray &jsonData);

    friend QDebug operator<<(QDebug dbg, const Event &e);

private:
    int id;
    QString title;
    QString location;
    QString date;
    QString start_time;
    bool is_free;
    double ticket_price;
};

#endif // EVENT_H

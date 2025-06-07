#include "event.h"

Event::Event() {}

Event::Event(int id, QString title, QString location, QString date, QString start_time, bool is_free, double ticket_price)
    : id(id), title(title), location(location), date(date), start_time(start_time), is_free(is_free), ticket_price(ticket_price) {}

Event Event::fromJson(const QByteArray &jsonData) {
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (!doc.isObject()) throw std::runtime_error("Invalid JSON");

    QJsonObject obj = doc.object();
    return Event(
        obj["id"].toInt(),
        obj["title"].toString(),
        obj["location"].toString(),
        obj["date"].toString(),
        obj["start_time"].toString(),
        obj["is_free"].toBool(),
        obj.contains("ticket_price") && !obj["ticket_price"].isNull() ? obj["ticket_price"].toDouble() : 0.0
        );
}

QDebug operator<<(QDebug dbg, const Event &e) {
    dbg.nospace() << "Event("
                  << "id: " << e.id
                  << ", title: " << e.title
                  << ", location: " << e.location
                  << ", date: " << e.date
                  << ", start_time: " << e.start_time
                  << ", is_free: " << e.is_free
                  << ", ticket_price: " << e.ticket_price
                  << ")";
    return dbg.space();
}

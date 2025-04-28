#include "Event.h"

Event::Event() {
    id = 0;
    type = "";
    date = "";
    maxParticipants = 0;
}

Event::Event(int id, string type, string date, int maxParticipants) {
    this->id = id;
    this->type = type;
    this->date = date;
    this->maxParticipants = maxParticipants;
}

int Event::getId() const {
    return id;
}



Event& Event::operator=(const Event& other) {
    if (this != &other) {
        id = other.id;
        type = other.type;
        date = other.date;
        maxParticipants = other.maxParticipants;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Event& event) {
    out << "ID: " << event.id << endl;
    out << "Type: " << event.type << endl;
    out << "Date: " << event.date << endl;
    out << "Max Participants: " << event.maxParticipants << endl;
    return out;
}

istream& operator>>(istream& in, Event& event) {
    cout << "Entrez ID Evenement: "; in >> event.id;
    in.ignore(10000, '\n');
    cout << "Entrez Type: "; getline(in, event.type);
    cout << "Entrez Date: "; getline(in, event.date);
    cout << "Entrez Max Participants: "; in >> event.maxParticipants;
    in.ignore(10000, '\n');
    return in;
}

void Event::addEvent(vector<Event>& events, istream& in) {
    Event e;
    in >> e;
    events.push_back(e);
    cout << "Evenement ajoute!" << endl;
}

void Event::viewEvents(const vector<Event>& events, ostream& out) {
    if (events.empty()) {
        out << "Aucun evenement trouve." << endl;
        return;
    }
    for (size_t i = 0; i < events.size(); i++) {
        out << events[i] << "-------------------" << endl;
    }
}
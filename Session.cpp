#include "Session.h"

Session::Session() {
    id = 0;
    type = "";
    date = "";
    time = "";
}

Session::Session(int id, string type, string date, string time) {
    this->id = id;
    this->type = type;
    this->date = date;
    this->time = time;
}

int Session::getId() const {
    return id;
}

Session::~Session() {
}

Session::Session(const Session& other) {
    id = other.id;
    type = other.type;
    date = other.date;
    time = other.time;
}

Session& Session::operator=(const Session& other) {
    if (this != &other) {
        id = other.id;
        type = other.type;
        date = other.date;
        time = other.time;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Session& session) {
    out << "ID: " << session.id << endl;
    out << "Type: " << session.type << endl;
    out << "Date: " << session.date << endl;
    out << "Heure: " << session.time << endl;
    return out;
}

istream& operator>>(istream& in, Session& session) {
    cout << "Entrez ID Session: "; in >> session.id;
    in.ignore(10000, '\n');
    cout << "Entrez Type: "; getline(in, session.type);
    cout << "Entrez Date: "; getline(in, session.date);
    cout << "Entrez Heure: "; getline(in, session.time);
    return in;
}

void Session::addSession(vector<Session>& sessions, istream& in) {
    Session s;
    in >> s;
    sessions.push_back(s);
    cout << "Session ajoutee!" << endl;
}

void Session::viewSessions(const vector<Session>& sessions, ostream& out) {
    if (sessions.empty()) {
        out << "Aucune session trouvee." << endl;
        return;
    }
    for (size_t i = 0; i < sessions.size(); i++) {
        out << sessions[i] << "-------------------" << endl;
    }
}
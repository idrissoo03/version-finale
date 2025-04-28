#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Event {
private:
    int id;
    string type;
    string date;
    int maxParticipants;
public:
    Event();
    Event(int id, string type, string date, int maxParticipants);
    Event(const Event& other);
    ~Event();
    int getId() const;
    static void addEvent(vector<Event>& events, istream& in = cin);
    static void viewEvents(const vector<Event>& events, ostream& out = cout);

    Event& operator=(const Event& other);
    friend ostream& operator<<(ostream& out, const Event& event);
    friend istream& operator>>(istream& in, Event& event);
};

#endif
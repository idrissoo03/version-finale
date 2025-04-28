#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Session {
private:
    int id;
    string type;
    string date;
    string time;
public:
    Session();
    Session(int id, string type, string date, string time);
    int getId() const;
    static void addSession(vector<Session>& sessions, istream& in = cin);
    static void viewSessions(const vector<Session>& sessions, ostream& out = cout);

    Session& operator=(const Session& other);
    friend ostream& operator<<(ostream& out, const Session& session);
    friend istream& operator>>(istream& in, Session& session);
};

#endif
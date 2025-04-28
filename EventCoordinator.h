#ifndef EVENTCOORDINATOR_H
#define EVENTCOORDINATOR_H

#include "Person.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class EventCoordinator : public Person {
private:
    string department;
public:
    EventCoordinator();
    EventCoordinator(int id, string name, int age, string phone, string department);
    static void addEventCoordinator(vector<EventCoordinator>& coordinators, istream& in = cin);
    static void viewEventCoordinators(const vector<EventCoordinator>& coordinators, ostream& out = cout);

    EventCoordinator& operator=(const EventCoordinator& other);
    friend ostream& operator<<(ostream& out, const EventCoordinator& coordinator);
    friend istream& operator>>(istream& in, EventCoordinator& coordinator);
};

#endif
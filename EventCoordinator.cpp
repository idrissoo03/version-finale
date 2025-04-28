#include "EventCoordinator.h"
#include "Person.h"
EventCoordinator::EventCoordinator() : Person(){
    department = "";
}



EventCoordinator::EventCoordinator(int id, string name, int age, string phone, string department) 
    : Person(id, name, age, phone) {
    this->department = department;
}

EventCoordinator& EventCoordinator::operator=(const EventCoordinator& other) {
    if (this != &other) {
        Person::operator=(other);
        department = other.department;
    }
    return *this;
}

EventCoordinator::~EventCoordinator() {
}

EventCoordinator::EventCoordinator(const EventCoordinator& other) : Person(other) {
    department = other.department;
}



ostream& operator<<(ostream& out, const EventCoordinator& coordinator) {
    out << static_cast<const Person&>(coordinator);
    out << "Departement: " << coordinator.department << endl;
    return out;
}

istream& operator>>(istream& in, EventCoordinator& coordinator) {
    Person person;
    in >> person;
    coordinator.id = person.getId();
    coordinator.name = person.getName();
    coordinator.age = person.getAge();
    coordinator.phone = person.getPhone();
    cout << "Entrez Departement: ";
    getline(in, coordinator.department);
    return in;
}

void EventCoordinator::addEventCoordinator(vector<EventCoordinator>& coordinators, istream& in) {
    EventCoordinator c;
    in >> c;
    coordinators.push_back(c);
    cout << "Coordinateur ajoute!" << endl;
}

void EventCoordinator::viewEventCoordinators(const vector<EventCoordinator>& coordinators, ostream& out) {
    if (coordinators.empty()) {
        out << "Aucun coordinateur trouve." << endl;
        return;
    }
    for (size_t i = 0; i < coordinators.size(); i++) {
        out << coordinators[i] << "-------------------" << endl;
    }
}
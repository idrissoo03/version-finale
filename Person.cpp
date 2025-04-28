#include "Person.h"

Person::Person() {
    id = 0;
    name = "";
    age = 0;
    phone = "";
}

Person::Person(int id, string name, int age, string phone) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->phone = phone;
}

int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

string Person::getPhone() const {
    return phone;
}



Person& Person::operator=(const Person& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        age = other.age;
        phone = other.phone;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Person& person) {
    out << "ID: " << person.id << endl;
    out << "Nom: " << person.name << endl;
    out << "Age: " << person.age << endl;
    out << "Telephone: " << person.phone << endl;
    return out;
}

istream& operator>>(istream& in, Person& person) {
    cout << "Entrez ID: "; in >> person.id;
    in.ignore(10000, '\n');
    cout << "Entrez Nom: "; getline(in, person.name);
    cout << "Entrez Age: "; in >> person.age;
    in.ignore(10000, '\n');
    cout << "Entrez Telephone: "; getline(in, person.phone);
    return in;
}
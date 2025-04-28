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

void Person::display(ostream& out) const {
    out << "ID: " << id << endl;
    out << "Nom Entite: " << entityName << endl;
    out << "Nom: " << name << endl;
    out << "Age: " << age << endl;
    out << "Telephone: " << phone << endl;
}

void Person::edit(istream& in) {
    cout << "Entrez ID: "; in >> id;
    in.ignore(10000, '\n');
    cout << "Entrez Nom Entite: "; getline(in, entityName);
    cout << "Entrez Nom: "; getline(in, name);
    cout << "Entrez Age: "; in >> age;
    in.ignore(10000, '\n');
    cout << "Entrez Telephone: "; getline(in, phone);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        id = other.id;
        entityName = other.entityName;
        name = other.name;
        age = other.age;
        phone = other.phone;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Person& person) {
    person.display(out);
    return out;
}

istream& operator>>(istream& in, Person& person) {
    person.edit(in);
    return in;
}
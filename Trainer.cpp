#include "Trainer.h"

Trainer::Trainer() : Person() {
    specialty = "";
}

Trainer::Trainer(int id, string name, int age, string phone, string specialty) 
    : Person(id, name, age, phone) {
    this->specialty = specialty;
}

Trainer& Trainer::operator=(const Trainer& other) {
    if (this != &other) {
        Person::operator=(other);
        specialty = other.specialty;
    }
    return *this;


}



ostream& operator<<(ostream& out, const Trainer& trainer) {
    out << static_cast<const Person&>(trainer);
    out << "Specialite: " << trainer.specialty << endl;
    return out;
}

istream& operator>>(istream& in, Trainer& trainer) {
    Person person;
    in >> person;
    trainer.id = person.getId();
    trainer.name = person.getName();
    trainer.age = person.getAge();
    trainer.phone = person.getPhone();
    cout << "Entrez Specialite: ";
    getline(in, trainer.specialty);
    return in;
}

void Trainer::addTrainer(list<Trainer>& trainers, istream& in) {
    Trainer t;
    in >> t;
    trainers.push_back(t);
    cout << "Entraineur ajoute!" << endl;
}

void Trainer::viewTrainers(const list<Trainer>& trainers, ostream& out) {
    if (trainers.empty()) {
        out << "Aucun entraineur trouve." << endl;
        return;
    }
    for (const auto& trainer : trainers) {
        out << trainer << "-------------------" << endl;
    }
}
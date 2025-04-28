#include "Equipment.h"

Equipment::Equipment() {
    id = 0;
    name = "";
    condition = "";
}

Equipment::Equipment(int id, string name, string condition) {
    this->id = id;
    this->name = name;
    this->condition = condition;
}

int Equipment::getId() const {
    return id;
}


Equipment::~Equipment() {
}

Equipment::Equipment(const Equipment& other) {
    id = other.id;
    name = other.name;
    condition = other.condition;
}

Equipment& Equipment::operator=(const Equipment& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        condition = other.condition;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Equipment& equipment) {
    out << "ID: " << equipment.id << endl;
    out << "Nom: " << equipment.name << endl;
    out << "Etat: " << equipment.condition << endl;
    return out;
}

istream& operator>>(istream& in, Equipment& equipment) {
    cout << "Entrez ID Equipement: "; in >> equipment.id;
    in.ignore(10000, '\n');
    cout << "Entrez Nom: "; getline(in, equipment.name);
    cout << "Entrez Etat: "; getline(in, equipment.condition);
    return in;
}

void Equipment::addEquipment(vector<Equipment>& equipment, istream& in) {
    Equipment e;
    in >> e;
    equipment.push_back(e);
    cout << "Equipement ajoute!" << endl;
}

void Equipment::viewEquipment(const vector<Equipment>& equipment, ostream& out) {
    if (equipment.empty()) {
        out << "Aucun equipement trouve." << endl;
        return;
    }
    for (size_t i = 0; i < equipment.size(); i++) {
        out << equipment[i] << "-------------------" << endl;
    }
}
#include "Membership.h"

Membership::Membership() {
    id = 0;
    type = "";
    price = 0.0;
}

Membership::Membership(int id, string type, double price) {
    this->id = id;
    this->type = type;
    this->price = price;
}

int Membership::getId() const {
    return id;
}

Membership::~Membership() {
}

Membership::Membership(const Membership& other) {
    id = other.id;
    type = other.type;
    price = other.price;
}

Membership& Membership::operator=(const Membership& other) {
    if (this != &other) {
        id = other.id;
        type = other.type;
        price = other.price;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Membership& membership) {
    out << "ID: " << membership.id << endl;
    out << "Type: " << membership.type << endl;
    out << "Prix: " << membership.price << endl;
    return out;
}

istream& operator>>(istream& in, Membership& membership) {
    cout << "Entrez ID Abonnement: "; in >> membership.id;
    in.ignore(10000, '\n');
    cout << "Entrez Type: "; getline(in, membership.type);
    cout << "Entrez Prix: "; in >> membership.price;
    in.ignore(10000, '\n');
    return in;
}

void Membership::addMembership(vector<Membership>& memberships, istream& in) {
    Membership m;
    in >> m;
    memberships.push_back(m);
    cout << "Adhesion ajoutee!" << endl;
}

void Membership::viewMemberships(const vector<Membership>& memberships, ostream& out) {
    if (memberships.empty()) {
        out << "Aucun Abonnement trouvee." << endl;
        return;
    }
    for (size_t i = 0; i < memberships.size(); i++) {
        out << memberships[i] << "-------------------" << endl;
    }
}
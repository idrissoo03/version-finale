#include "Resource.h"

Resource::Resource() {
    id = 0;
    name = "";
    availability = false;
}

Resource::Resource(int id, string name, bool availability) {
    this->id = id;
    this->name = name;
    this->availability = availability;
}

int Resource::getId() const {
    return id;
}

Resource::~Resource() {
}

Resource::Resource(const Resource& other) {
    id = other.id;
    name = other.name;
    availability = other.availability;
}

Resource& Resource::operator=(const Resource& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        availability = other.availability;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Resource& resource) {
    out << "ID: " << resource.id << endl;
    out << "Nom: " << resource.name << endl;
    out << "Disponibilite: " << (resource.availability ? "Oui" : "Non") << endl;
    return out;
}

istream& operator>>(istream& in, Resource& resource) {
    cout << "Entrez ID Ressource: "; in >> resource.id;
    in.ignore(10000, '\n');
    cout << "Entrez Nom: "; getline(in, resource.name);
    cout << "Disponible (1 pour oui, 0 pour non): "; in >> resource.availability;
    in.ignore(10000, '\n');
    return in;
}

void Resource::addResource(vector<Resource>& resources, istream& in) {
    Resource r;
    in >> r;
    resources.push_back(r);
    cout << "Ressource ajoutee!" << endl;
}

void Resource::viewResources(const vector<Resource>& resources, ostream& out) {
    if (resources.empty()) {
        out << "Aucune ressource trouvee." << endl;
        return;
    }
    for (size_t i = 0; i < resources.size(); i++) {
        out << resources[i] << "-------------------" << endl;
    }
}
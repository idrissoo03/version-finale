#include "Member.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>


Member::Member() : Person() {
    memberID = 0;
    membershipType = "";
}

Member::Member(int id, string name, int age, string phone, string membershipType)
    : Person(id, name, age, phone) {
    this->memberID = id;
    this->membershipType = membershipType;
}

Member::Member(const Member& other) : Person(other) {
    memberID = other.memberID;
    membershipType = other.membershipType;
}

Member::~Member() {
}




int Member::getMemberID() const {
    return memberID;
}

string Member::getMembershipType() const {
    return membershipType;
}

Member& Member::operator=(const Member& other) {
    if (this != &other) {
        Person::operator=(other);
        memberID = other.memberID;
        membershipType = other.membershipType;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Member& member) {
    out << static_cast<const Person&>(member);
    out << "ID Membre: " << member.memberID << endl;
    out << "Type Adhesion: " << member.membershipType << endl;
    return out;
}

istream& operator>>(istream& in, Member& member) {
    Person person;
    in >> person;
    member.id = person.getId();
    member.name = person.getName();
    member.age = person.getAge();
    member.phone = person.getPhone();
    member.memberID = member.id;
    cout << "Entrez Type Adhesion (Basique/Standard/Premium): ";
    getline(in, member.membershipType);
    return in;
}

void Member::addMember(map<int, Member>& members, istream& in) {
    Member m;
    in >> m;
    int id = m.getMemberID();
    if (members.find(id) != members.end()) {
        cout << "Erreur: Un membre avec l'ID " << id << " existe deja." << endl;
        return;
    }
    members[id] = m;
    cout << "Membre ajoute!" << endl;
}

void Member::viewMembers(const map<int, Member>& members, ostream& out) {
    if (members.empty()) {
        out << "Aucun membre trouve." << endl;
        return;
    }
    for (const auto& pair : members) {
        out << pair.second << "-------------------" << endl;
    }
}

void Member::updateMember(map<int, Member>& members, istream& in) {
    int id;
    cout << "Entrez ID Membre a modifier: "; in >> id;
    in.ignore(10000, '\n');
    if (members.find(id) == members.end()) {
        cout << "Membre non trouve." << endl;
        return;
    }
    Member m;
    in >> m;
    members[id] = m;
    cout << "Membre modifie!" << endl;
}

void Member::deleteMember(map<int, Member>& members, istream& in) {
    int id;
    cout << "Entrez ID Membre a supprimer: "; in >> id;
    in.ignore(10000, '\n');
    if (members.find(id) == members.end()) {
        cout << "Membre non trouve." << endl;
        return;
    }
    members.erase(id);
    cout << "Membre supprime!" << endl;
}

string toLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}


void Member::RechercheMemberByName(const map<int, Member>& members, const string& name, ostream& out) {
    if (members.empty()) {
        out << "Aucun membre trouve." << endl;
        return;
    }
    string searchName = toLower(name);
    bool found = false;
    for (const auto& pair : members) {
        string memberName = toLower(pair.second.getName());
        if (memberName.find(searchName) != string::npos) {
            out << pair.second << "-------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        out << "Aucun membre trouve avec le nom: " << name << endl;
    }
}

void Member::RechercheMemberByID(const map<int, Member>& members, int id, ostream& out) {
    auto it = members.find(id);
    if (it != members.end()) {
        out << it->second << "-------------------" << endl;
    } else {
        out << "Aucun membre trouve avec l'ID: " << id << endl;
    }
}

void Member::writeToFile(const map<int, Member>& members, const string& filename) {
    ofstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Erreur: Impossible d'ouvrir le fichier " << filename << " pour ecriture." << endl;
        return;
    }
    for (auto it = members.begin(); it != members.end(); ++it) {
        const Member& member = it->second;
        file << member.getId() << "|"  << member.getName() << "|"<< member.getAge() << "|" << member.getPhone() << "|" << member.getMembershipType();
        if (next(it) != members.end()) file << "\n"; 
    }
    file.close();
    cout << "Membres sauvegardes dans " << filename << endl;
}

void Member::readFromFile(map<int, Member>& members, const string& filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cout << "Attention: Fichier " << filename << " non trouve ou inaccessible. Liste vide." << endl;
        return;
    }
    members.clear();
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        int id, age;
        string  name, phone, membershipType;
        try {
            getline(ss, token, '|'); id = stoi(token);
            getline(ss, name, '|');
            getline(ss, token, '|'); age = stoi(token);
            getline(ss, phone, '|');
            getline(ss, membershipType, '|');
            members[id] = Member(id, name, age, phone, membershipType);
        } catch (const exception& e) {
            cout << "Erreur lors de la lecture de la ligne: " << line << " (" << e.what() << ")" << endl;
            continue;
        }
    }
    file.close();
    cout << "Lecture terminee: " << members.size() << " membres charges depuis " << filename << endl;
}
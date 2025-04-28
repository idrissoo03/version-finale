#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Equipment {
private:
    int id;
    string name;
    string condition;
public:
    Equipment();
    Equipment(int id, string name, string condition);
    int getId() const;
    static void addEquipment(vector<Equipment>& equipment, istream& in = cin);
    static void viewEquipment(const vector<Equipment>& equipment, ostream& out = cout);

    Equipment& operator=(const Equipment& other);
    friend ostream& operator<<(ostream& out, const Equipment& equipment);
    friend istream& operator>>(istream& in, Equipment& equipment);
};

#endif
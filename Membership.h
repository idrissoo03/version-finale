#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Membership {
private:
    int id;
    string type;
    double price;
public:
    Membership();
    Membership(int id, string type, double price);
    int getId() const;
    static void addMembership(vector<Membership>& memberships, istream& in = cin);
    static void viewMemberships(const vector<Membership>& memberships, ostream& out = cout);

    Membership& operator=(const Membership& other);
    friend ostream& operator<<(ostream& out, const Membership& membership);
    friend istream& operator>>(istream& in, Membership& membership);
};

#endif
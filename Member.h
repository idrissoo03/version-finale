#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <string>
#include <map>

#include <vector>
#include <iostream>

using namespace std;
class Trainer;
class EventCoordinator;

class Member : public Person {
private:
    int memberID;
    string membershipType;
    friend class Trainer;
    friend class EventCoordinator;
public:
    Member();
    Member(int id, string name, int age, string phone, string membershipType);
    ~Member();
    Member(const Member& other) = default; 

    
    int getMemberID() const;
    string getMembershipType() const;
    static void addMember(map<int, Member>& members, istream& in = cin);
    static void updateMember(map<int, Member>& members, istream& in = cin);
    static void deleteMember(map<int, Member>& members, istream& in = cin);
    static void viewMembers(const map<int, Member>& members, ostream& out = cout);
    static void RechercheMemberByName(const map<int, Member>& members, const string& name, ostream& out = cout);
    static void RechercheMemberByID(const map<int, Member>& members, int id, ostream& out = cout);
    static void writeToFile(const map<int, Member>& members, const string& filename);
    static void readFromFile(map<int, Member>& members, const string& filename);

    Member& operator=(const Member& other);
    friend ostream& operator<<(ostream& out, const Member& member);
    friend istream& operator>>(istream& in, Member& member);
};

#endif
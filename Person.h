#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
    string phone;
public:
    Person();
    Person(int id, string name, int age, string phone);
    int getId() const;
    string getName() const;
    int getAge() const;
    string getPhone() const;

    Person& operator=(const Person& other);
    friend ostream& operator<<(ostream& out, const Person& person);
    friend istream& operator>>(istream& in, Person& person);
};

#endif
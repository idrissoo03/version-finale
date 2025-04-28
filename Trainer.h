#ifndef TRAINER_H
#define TRAINER_H

#include "Person.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Trainer : public Person {
private:
    string specialty;
public:
    Trainer();
    Trainer(int id, string name, int age, string phone, string specialty);
    static void addTrainer(list<Trainer>& trainers, istream& in = cin);
    static void viewTrainers(const list<Trainer>& trainers, ostream& out = cout);

    Trainer& operator=(const Trainer& other);
    friend ostream& operator<<(ostream& out, const Trainer& trainer);
    friend istream& operator>>(istream& in, Trainer& trainer);
};

#endif
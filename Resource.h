#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Resource {
private:
    int id;
    string name;
    bool availability;
public:
    Resource();
    Resource(int id, string name, bool availability);
    Resource(const Resource& other);
    ~Resource();
    int getId() const;
    static void addResource(vector<Resource>& resources, istream& in = cin);
    static void viewResources(const vector<Resource>& resources, ostream& out = cout);

    Resource& operator=(const Resource& other);
    friend ostream& operator<<(ostream& out, const Resource& resource);
    friend istream& operator>>(istream& in, Resource& resource);
};

#endif
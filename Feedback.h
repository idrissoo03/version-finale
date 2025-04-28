#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Feedback {
private:
    int feedbackID;
    int memberID;
    string comment;
    int rating;
public:
    Feedback();
    Feedback(int feedbackID, int memberID, string comment, int rating);
    ~Feedback(); // Destructor
    Feedback(const Feedback& other)  ; // Copy constructor
    ~Feedback();

    int getFeedbackID() const;
    int getMemberID() const;
    int getRating() const;
    void afficher() const;
    void writeToFile(const std::vector<Feedback>& feedback, const string& filename);
    void readFromFile(std::vector<Feedback>& feedback, const string& filename);
    static void addFeedback(vector<Feedback>& feedback, const string& filename, istream& in = cin);
    static void submitFeedback(vector<Feedback>& feedback, const string& filename, istream& in = cin);
    static void viewFeedback(const vector<Feedback>& feedback, ostream& out = cout);
    static void trierFeedbackParNote(vector<Feedback>& feedback, ostream& out);
    static void afficherMemberFeedback(const vector<Feedback>& feedback, int memberID, ostream& out = cout);


    Feedback& operator=(const Feedback& other);
    friend ostream& operator<<(ostream& out, const Feedback& feedback);
    friend istream& operator>>(istream& in, Feedback& feedback);
};

#endif
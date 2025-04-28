#include "Feedback.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>    


const string FEEDBACK_FILE = "C:/Users/USER/Desktop/doss/projee7/feedback.txt";

Feedback::Feedback() {
    feedbackID = 0;
    memberID = 0;
    comment = "";
    rating = 0;
}

Feedback::Feedback(int feedbackID, int memberID, string comment, int rating) {
    this->feedbackID = feedbackID;
    this->memberID = memberID;
    this->comment = comment;
    this->rating = rating;
}


void Feedback::afficher() const {
    cout << "ID Feedback: " << feedbackID << endl;
    cout << "ID Membre: " << memberID << endl;
    cout << "Commentaire: " << comment << endl;
    cout << "Note (1-5): " << rating << endl;
}

int Feedback::getFeedbackID() const {
    return feedbackID;
}

int Feedback::getMemberID() const {
    return memberID;
}

int Feedback::getRating() const {
    return rating;
}

Feedback& Feedback::operator=(const Feedback& other) {
    if (this != &other) {
        feedbackID = other.feedbackID;
        memberID = other.memberID;
        comment = other.comment;
        rating = other.rating;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Feedback& feedback) {
    out << "ID Feedback: " << feedback.feedbackID << endl;
    out << "ID Membre: " << feedback.memberID << endl;
    out << "Commentaires: " << feedback.comment << endl;
    out << "Note: " << feedback.rating << endl;
    return out;
}

istream& operator>>(istream& in, Feedback& feedback) {
    cout << "Entrez ID Feedback: "; in >> feedback.feedbackID;
    cout << "Entrez ID Membre: "; in >> feedback.memberID;
    in.ignore(10000, '\n');
    cout << "Entrez Commentaires: "; getline(in, feedback.comment);
    cout << "Entrez Note (1-5): "; in >> feedback.rating;
    in.ignore(10000, '\n');
    return in;
}

void Feedback::writeToFile(const vector<Feedback>& feedback, const string& filename) {
    try {
        ofstream file(filename.c_str());
        if (!file.is_open()) {
            throw runtime_error("Erreur: Impossible ouvrir fichier " + filename);
        }

        for (size_t i = 0; i < feedback.size(); i++) {
            cout << "Ecriture de l entree " << i + 1 << ": " 
                 << feedback[i].feedbackID << "|" 
                 << feedback[i].memberID << "|" 
                 << feedback[i].comment << "|" 
                 << feedback[i].rating << endl;
            file << feedback[i].feedbackID << "|" 
                 << feedback[i].memberID << "|" 
                 << feedback[i].comment << "|" 
                 << feedback[i].rating;
            if (i < feedback.size() - 1) {
                file << "\n";
            }
        }

        file.flush();
        if (file.fail()) {
            throw runtime_error("Erreur: Echec lors de l ecriture dans le fichier " + filename);
        }

        file.close();
        if (file.fail()) {
            throw runtime_error("Erreur: Echec lors de la fermeture du fichier " + filename);
        }

        cout << "Fichier " << filename << " ecrit avec succes." << endl;
    }
    catch (const exception& e) {
        cerr << "Exception attrapée: " << e.what() << endl;
    }
}

void Feedback::readFromFile(vector<Feedback>& feedback, const string& filename) {
    try {
        ifstream file(filename.c_str());
        if (!file.is_open()) {
            throw runtime_error("Attention: Fichier " + filename + " non trouve.");
        }

        feedback.clear();
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;

            int feedbackID, memberID, rating;
            string comment;

            getline(ss, token, '|'); feedbackID = stoi(token);
            getline(ss, token, '|'); memberID = stoi(token);
            getline(ss, comment, '|');
            getline(ss, token, '|'); rating = stoi(token);

            Feedback f(feedbackID, memberID, comment, rating);
            feedback.push_back(f);
        }

        file.close();
    }
    catch (const exception& e) {
        cerr << "Exception attrapée: " << e.what() << endl;
    }
}


void Feedback::addFeedback(vector<Feedback>& feedback, const string& filename, istream& in) {
    Feedback f;
    in >> f;
    feedback.push_back(f);
    f.writeToFile(feedback, filename);
    cout << "Feedback ajoute!" << endl;
}

void Feedback::submitFeedback(vector<Feedback>& feedback, const string& filename, istream& in) {
    Feedback f;
    in >> f;
    feedback.push_back(f);
    f.writeToFile(feedback, filename);
    cout << "Feedback soumis!" << endl;
}

void Feedback::viewFeedback(const vector<Feedback>& feedback, ostream& out) {
    if (feedback.empty()) {
        out << "Aucun feedback trouve." << endl;
        return;
    }
    for (size_t i = 0; i < feedback.size(); i++) {
        out << feedback[i] << "-------------------" << endl;
    }
}

void Feedback::trierFeedbackParNote(vector<Feedback>& feedback, ostream& out) {
    sort(feedback.begin(), feedback.end(), [](const Feedback& a, const Feedback& b) {
        return a.getRating() > b.getRating(); 
    });
    for (const auto& f : feedback) {
        out << f << "-------------------" << endl;

    out << "Feedbacks trier par note!" << endl;

    }
}

void Feedback::afficherMemberFeedback(const vector<Feedback>& feedback, int memberID, ostream& out) {
    bool trouve = false;

    for (vector<Feedback>::const_iterator it = feedback.begin(); it != feedback.end(); ++it) {
        if (it->getMemberID() == memberID) {
            out << *it << "-------------------" << endl;
            trouve = true;
        }
    }

    if (!trouve) {
        out << "Aucun feedback trouvé pour le membre avec l'ID " << memberID << "." << endl;
    }
}

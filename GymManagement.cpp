#include "Member.h"
#include "Trainer.h"
#include "EventCoordinator.h"
#include "Event.h"
#include "Resource.h"
#include "Session.h"
#include "Equipment.h"
#include "Membership.h"
#include "Feedback.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <conio.h>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string FEEDBACK_FILE = "C:/Users/USER/Desktop/doss/projee7/feedback.txt";
const string MEMBERS_FILE = "C:/Users/USER/Desktop/doss/projee7/members.txt";


string getPassword() {
    string password = "";
    char ch;

    while (true) {
        ch = _getch(); 
        if (ch == 13) {
            break;
        } else if (ch == 8) {  
            if (password.length() > 0) {
                password.pop_back(); 
                cout << "\b \b"; 
            }
        } else {
            password += ch;
            cout << "*";  
        }
    }

    cout << endl; 
    return password;
}

void ensureDirectoryExists(const string& filepath) {
    string directory = filepath.substr(0, filepath.find_last_of("/\\"));
    fs::create_directories(directory);
}

void adminMenu(map<int, Member>& members, list<Trainer>& trainers,
               vector<EventCoordinator>& coordinators, vector<Event>& events,
               vector<Resource>& resources, vector<Session>& sessions,
               vector<Equipment>& equipment, vector<Membership>& memberships,
               vector<Feedback>& feedback) {
    int choice;
    while (true) {
        cout << "\n=== Menu Admin ===\n";
        cout << "1. Gerer Membres\n2. Gerer Entraineurs\n3. Gerer Coordinateurs\n";
        cout << "4. Gerer Evenements\n5. Gerer Ressources\n6. Gerer Sessions\n";
        cout << "7. Gerer Equipements\n8. Gerer Abonnement\n9. Gerer Feedback\n10. Retour\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore(10000, '\n');
        if (choice == 1) {
            int subChoice;
            cout << "\n=== Gestion Membres ===\n";
            cout << "1. Ajouter Membre\n2. Voir Membres\n3. Modifier Membre\n";
            cout << "4. Supprimer Membre\n5. Rechercher Membre par Nom\n6. Rechercher Membre par ID\n7. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1){
                Member::addMember(members, cin);
                Member::writeToFile(members, MEMBERS_FILE);
                cout << "Membre ajoute!" << endl;
            } 
            else if (subChoice == 2) Member::viewMembers(members, cout);
            else if (subChoice == 3) {
                Member::updateMember(members, cin);
                Member::writeToFile(members, MEMBERS_FILE);
            }
            else if (subChoice == 4) Member::deleteMember(members, cin);
            else if (subChoice == 5) {
                string name;
                cout << "Entrez le nom a rechercher: ";
                getline(cin, name);
                Member::RechercheMemberByName(members, name, cout);
            }
            else if (subChoice == 6) {
                int id;
                cout << "Entrez l'ID a rechercher: ";
                cin >> id;
                cin.ignore(10000, '\n');
                Member::RechercheMemberByID(members, id, cout);
            }
            else if (subChoice == 7) continue;  
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 2) {
            int subChoice;
            cout << "\n=== Gestion Entraineurs ===\n";
            cout << "1. Ajouter Entraineur\n2. Voir Entraineurs\n3. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) Trainer::addTrainer(trainers, cin);
            else if (subChoice == 2) Trainer::viewTrainers(trainers, cout);
            else if (subChoice == 3) continue;
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 3) {
            int subChoice;
            cout << "\n=== Gestion Coordinateurs ===\n";
            cout << "1. Ajouter Coordinateur\n2. Voir Coordinateurs\n3. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) EventCoordinator::addEventCoordinator(coordinators, cin);
            else if (subChoice == 2) EventCoordinator::viewEventCoordinators(coordinators, cout);
            else if (subChoice == 3) continue;
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 4) {
            int subChoice;
            cout << "\n=== Gestion Evenements ===\n";
            cout << "1. Ajouter Evenement\n2. Voir Evenements\n3. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) Event::addEvent(events, cin);
            else if (subChoice == 2) Event::viewEvents(events, cout);
            else if (subChoice == 3) continue;
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 5) {
            int subChoice;
            cout << "\n=== Gestion Ressources ===\n";
            cout << "1. Ajouter Ressource\n2. Voir Ressources\n3. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) Resource::addResource(resources, cin);
            else if (subChoice == 2) Resource::viewResources(resources, cout);
            else if (subChoice == 3) continue;
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 6) {
            int subChoice;
            cout << "\n=== Gestion Sessions ===\n";
            cout << "1. Ajouter Session\n2. Voir Sessions\n3. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) Session::addSession(sessions, cin);
            else if (subChoice == 2) Session::viewSessions(sessions, cout);
            else if (subChoice == 3) continue;
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 7) {
            int subChoice;
            cout << "\n=== Gestion Equipements ===\n";
            cout << "1. Ajouter Equipement\n2. Voir Equipements\n3. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) Equipment::addEquipment(equipment, cin);
            else if (subChoice == 2) Equipment::viewEquipment(equipment, cout);
            else if (subChoice == 3) continue;
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 8) {
            int subChoice;
            cout << "\n=== Gestion Abonnement ===\n";
            cout << "1. Ajouter Abonnement\n2. Voir Abonnement\n3. Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) Membership::addMembership(memberships, cin);
            else if (subChoice == 2) Membership::viewMemberships(memberships, cout);
            else if (subChoice == 3) continue;
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 9) {
            int subChoice;
            cout << "\n=== Gestion Feedback ===\n";
            cout << "1. Ajouter Feedback\n2. Voir Feedback\n3. Trier les Feedbacks par note\n4. Trouver Le membre qui a soumis un feedback Retour\n";
            cout << "Entrez votre choix: ";
            cin >> subChoice;
            cin.ignore(10000, '\n');
            if (subChoice == 1) Feedback::addFeedback(feedback, FEEDBACK_FILE, cin);
            else if (subChoice == 2) Feedback::viewFeedback(feedback, cout);
            else if (subChoice == 3) Feedback::trierFeedbackParNote(feedback,cout);
            else if (subChoice == 4) {
                int memberID;
                cout << "Entrez l'ID du membre: ";
                cin >> memberID;
                Feedback::afficherMemberFeedback(feedback, memberID, cout);
            }
            else if (subChoice == 5) continue;  
            else cout << "Choix invalide." << endl;
        }
        else if (choice == 10) {
            return;
        }
        else {
            cout << "Choix invalide." << endl;
        }
    }
}

void userMenu(const vector<Event>& events, const vector<Session>& sessions, 
              const vector<Membership>& memberships, vector<Feedback>& feedback) {
    int choice;
    while (true) {
        cout << "\n=== Menu Utilisateur ===\n";
        cout << "1. Voir Evenements\n2. Voir Sessions\n3. Voir Abonnement\n4. Soumettre Feedback\n5. Retour\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore(10000, '\n');
        if (choice == 1) Event::viewEvents(events, cout);
        else if (choice == 2) Session::viewSessions(sessions, cout);
        else if (choice == 3) Membership::viewMemberships(memberships, cout);
        else if (choice == 4) Feedback::submitFeedback(feedback, FEEDBACK_FILE, cin);
        else if (choice == 5) return;
        else cout << "Choix invalide." << endl;
    }
}

int main() {
    map<int, Member> members;
    list<Trainer> trainers;
    vector<EventCoordinator> coordinators;
    vector<Event> events;
    vector<Resource> resources;
    vector<Session> sessions;
    vector<Equipment> equipment;
    vector<Membership> memberships;
    vector<Feedback> feedback;

    ensureDirectoryExists(FEEDBACK_FILE);
    ensureDirectoryExists(MEMBERS_FILE);
    cout << "Chargement des feedbacks depuis " << FEEDBACK_FILE << endl;
    Feedback().readFromFile(feedback, FEEDBACK_FILE);
    cout << "Chargement des membres depuis " << MEMBERS_FILE << endl;
    Member::readFromFile(members, MEMBERS_FILE);

    int choice;
    while (true) {
        cout << "\n=== Systeme Gestion D'abonnement d'une salle de sport  ===\n";
        cout << "1. Connexion Admin\n2. Connexion Utilisateur\n3. Quitter\n";
        cout << "Entrez votre choix: ";
        cin >> choice;
        cin.ignore(10000, '\n');

        if (choice == 1) {
            string password;
            cout << "\n=== Veuillez Saisir le Mot de Passe Admin ===\n";
            cout << "Mot de passe: ";
            password = getPassword();  
            if (password != "admin123") {
                cout << "Mot de passe incorrect. Retour au menu principal." << endl;
                continue;
            } else {
                cout << "Mot de passe correct. Acces admin accorde." << endl;
                adminMenu(members, trainers, coordinators, events, resources,
                          sessions, equipment, memberships, feedback);
            }
        }
        else if (choice == 2) {
            userMenu(events, sessions, memberships, feedback);
        }
        else if (choice == 3) {
            cout << "Sauvegarde des feedbacks avant de quitter..." << endl;
            Feedback().writeToFile(feedback, FEEDBACK_FILE);
            cout << "Quitter..." << endl;
            return 0;
        }
        else {
            cout << "Choix invalide." << endl;
        }
    }
    return 0;
}
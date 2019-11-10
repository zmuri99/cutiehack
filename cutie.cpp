#include <iostream>
#include <fstream>
#include "person.h"
#include "participant.h"
#include "volunteer.h"
#include "mentor.h"
#include "bst.h"

using namespace std;

bool file(BST* A) {
    string filename;

    printf("Please enter filename with extension (for example, .txt)\n");
    printf("(The file list.txt will be automatically entered)\n");

    filename = "list.txt";

    ifstream fin(filename.c_str());
    if(!fin.is_open()) {
        return false;
    }

    string s1, s2, s3, s4, s5;

    while((fin >> s1) && (fin >> s2) && (fin >> s3) && (fin >> s4) && (fin >> s5)) {
        if(s4 == "participant") {
            A->insert(new Participant(s1, s2, s3, s5));
        }
        else if(s4 == "volunteer") {
            A->insert(new Volunteer(s1, s2, s3, s5));
        }
        else if(s4 == "mentor") {
            A->insert(new Mentor(s1, s2, s3, s5));
        }
        else {
            //nothing
        }
    }
    fin.close();

    return true;
}

int main() {
    printf("Cutie Hack personnel management version 1.0\n");
    printf("Current build supports the management of participant, volunteer, and mentor with varying permissions\n");
    printf("The input will be gathered from a file consisting of the individuals first names, last names, id numbers, and status\n\n");

    BST *Tree = new BST();

    if(!file(Tree)) {
        printf("Failure to open file\n");
    }
    else {
        printf("File succesfully opened\n");
    }

    bool finished = false;
    string name = "";

    printf("Please enter full name.\n");
    printf("For example: Johnny Appleseed\n");
    printf("(Given name: Jack Black)\n");
    
    getline(cin, name);
    cin.clear();
    Person *p = Tree->search(name);

    if(p != NULL) {
        cout << "Found " << p->getStatus() << " " << name << endl;
    }
    else {
        printf("Not a valid name. Logging off.\n");
        return 0;
    }

    if(p->getStatus() == "participant") {
        printf("Participant cannot access information. Logging off.\n");
        return 0;
    }
    
    printf("Please enter password to access data records.\n");
    printf("(Password for Jack Black is \"12s\"\n");
    cin >> name;
    cout << "PASSWPRD:" << p->getPassword() << endl << endl;
    if(name != p->getPassword()) {
        printf("Not a valid password");
        return 0;
    }

    printf("Password accepted.\n\n");
    printf("Enter \"done\" when finished accessing system.\n");
    printf("Enter full name to access users records.\n");

    bool done;
    string s;

    while(!done) {
        cin.ignore();
        getline(cin,name);
        name = name + s;

        p = Tree->search(name);
        if(p!=NULL) {
            printf("Information:\n");
            cout << p->getName() << endl;
            cout << p->getStatus() << endl;
            cout << p->getEmail() << endl << endl;
        }
        else {
            printf("Invalid name");
        }
        printf("Please enter anything but \"done\" to continue.\n");
        cin >> name;
        cin.clear();
        if(name == "done") {
            done = true;
        }
    }

    return 0;
}
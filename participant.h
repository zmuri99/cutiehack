#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <iostream>
#include "person.h"

using namespace std;

class Participant : public Person {
    private:
        string firstname;
        string lastname;
        string email;
        string password;
        Person *left;
        Person *right;
    public:
        Participant() {
            firstname = "Default";
            lastname = "Daniel";
            email = "NULL@gmail.com";
            password = "1";
            left = right = 0;
        }
        Participant(string s1, string s2, string e, string p) {
            firstname = s1;
            lastname = s2;
            email = e;
            password = p;
        }
        string getName() {
            string s = firstname;
            s += " ";
            s += lastname;
            return s;
        }
        
        string getEmail() {
            return email;
        }

        string getStatus() {
            return "participant";
        }

        Person *getLeft() {
            return left;
        }

        Person *getRight() {
            return right;
        }

        void setLeft(Person *p) {
            left = p;
        }

        void setRight(Person *p) {
            right = p;
        }

        string getPassword() {
            return password;
        }
};
#endif
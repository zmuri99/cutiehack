#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
    public:
        Person() {}
        Person(std::string s1, std::string s2, std::string s3, std::string s4, std::string s5);
        virtual std::string getName() = 0;
        virtual std::string getEmail() = 0;
        virtual std::string getStatus() = 0;
        virtual Person* getLeft() = 0;
        virtual Person* getRight() = 0;
        virtual void setLeft(Person * p) = 0;
        virtual void setRight(Person * p) = 0;
        virtual std::string getPassword() = 0;
};
#endif
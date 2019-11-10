#ifndef BST_H
#define BST_H

#include "person.h"

class BST {
    private:
        Person *root;
    public:
        BST() {
            root = NULL;
        }
        BST(Person *p) {
            root = p;
        }
        void insert(Person *p) {
            if(root == NULL) {
                root = p;
            }
            else {
                insertR(root, p);
            }
        }
        void insertR(Person *r, Person *p) {
            if(p->getName() <= r->getName()) {
                if(r->getLeft() == NULL) {
                    r->setLeft(p);
                }
                else {
                    insertR(r->getLeft(), p);
                }
            }
            else {
                if(r->getRight() == NULL) {

                    r->setRight(p);
                }
                else {
                    insertR(r->getRight(), p);
                }
            }
        }
        Person* search(string s) {
            if(root == NULL) {
                return NULL;
            }

            return searchR(root, s);
        }
        Person* searchR(Person *r, string s) {
            if(r == NULL) {
                return NULL;
            }
            else if(r->getName() == s) {
                return r;
            }

            if(s <= r->getName()) {
                return searchR(r->getLeft(), s);
            }
            else {
                return searchR(r->getRight(), s);
            }
        }
};
#endif
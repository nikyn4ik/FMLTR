#pragma once
#ifndef TREE_H
#define TREE_H

#include "Person.h"

class Tree {
private:
    Person* root;

public:
    Tree(Person* root);
    void addMom(Person mom);
    void addDad(Person dad);
    void addGrandmaMom(Person grandma);
    void addGrandpaMom(Person grandpa);
    void addGrandmaDad(Person grandma);
    void addGrandpaDad(Person grandpa);
    void printTree();
};

#endif

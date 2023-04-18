#pragma once
#ifndef TREE_H
#define TREE_H

#include "Person.h"

class Tree {
private:
    Person* root;
    std::string name;

public:
    Tree(Person* root, std::string name);
    void addMom(Person mom);
    void addDad(Person dad);
    void addGrandmaMom(Person grandma);
    void addGrandpaMom(Person grandpa);
    void addGrandmaDad(Person grandma);
    void addGrandpaDad(Person grandpa);
    void printTree();
};

#endif
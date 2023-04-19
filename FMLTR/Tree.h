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
    void addPerson(Person person);
    void printPerson(Person* person, int depth, int generation);
    void printTree();
    void print();
};
#endif
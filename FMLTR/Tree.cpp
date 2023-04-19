#include "Tree.h"
#include <iostream>

Tree::Tree(Person* root, std::string name) {
    this->root = root;
    this->name = name;
}

void Tree::addPerson(Person person) {
    this->root->setPerson(new Person(person.getName(), person.getDateOfBirth(), person.getDateOfDeath()));
}

void Tree::printPerson(Person* person, int depth, int generation) {
    if (person == nullptr) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        std::cout << "  ";
    }
    std::cout << "- " << person->getName() << " (" << person->getDateOfBirth() << " - ";
    if (person->getDateOfDeath() == "") {
        std::cout << "alive)";
    }
    else {
        std::cout << person->getDateOfDeath() << ")";
    }
    std::cout << " [Generation " << generation << "]" << std::endl;
}

void Tree::printTree() {
    std::cout << "Family Tree: " << name << std::endl;
    std::cout << "--------------------------" << std::endl;
    printPerson(root, 0, 0);
}
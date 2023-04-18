#include "Tree.h"
#include <iostream>

Tree::Tree(Person* root) {
    this->root = root;
}

void Tree::addMom(Person mom) {
    this->root->setMother(new Person(mom));
}

void Tree::addDad(Person dad) {
    this->root->setFather(new Person(dad));
}

void Tree::addGrandmaMom(Person grandma) {
    if (this->root->getMother() == nullptr) {
        std::cout << "Please add mother first." << std::endl;
    }
    else {
        this->root->getMother()->setMother(new Person(grandma));
    }
}

void Tree::addGrandpaMom(Person grandpa) {
    if (this->root->getMother() == nullptr) {
        std::cout << "Please add mother first." << std::endl;
    }
    else {
        this->root->getMother()->setFather(new Person(grandpa));
    }
}

void Tree::addGrandmaDad(Person grandma) {
    if (this->root->getFather() == nullptr) {
        std::cout << "Please add father first." << std::endl;
    }
    else {
        this->root->getFather()->setMother(new Person(grandma));
    }
}

void Tree::addGrandpaDad(Person grandpa) {
    if (this->root->getFather() == nullptr) {
        std::cout << "Please add father first." << std::endl;
    }
    else {
        this->root->getFather()->setFather(new Person(grandpa));
    }
}

void printPerson(Person* person, int depth, int generation) {
    if (person == nullptr) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        std::cout << "  ";
    }
    std::cout << "- " << person->getName() << " (" << person->getDateOfBirth() << " - ";
    if (person->getDateOfDeath() == "") {
        std::cout << "-)";
    }
    else {
        std::cout << person->getDateOfDeath() << ")";
    }
    std::cout << " [Generation " << generation << "]" << std::endl;
    printPerson(person->getMother(), depth + 1, generation + 1);
    printPerson(person->getFather(), depth + 1, generation + 1);
}

void Tree::printTree() {
    printPerson(this->root, 0, 1);
}

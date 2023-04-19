#include "Person.h"

Person::Person(std::string name, std::string dateOfBirth, std::string dateOfDeath) {
    this->name = name;
    this->dateOfBirth = dateOfBirth;
    this->dateOfDeath = dateOfDeath;
    this->person = nullptr;
}

void Person::setPerson(Person* person) {
    this->person = person;
}

void Person::setDateOfBirth(std::string dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

void Person::setDateOfDeath(std::string dateOfDeath) {
    this->dateOfDeath = dateOfDeath;
}

std::string Person::getName() const {
    return this->name;
}

std::string Person::getDateOfBirth() const {
    return this->dateOfBirth;
}

std::string Person::getDateOfDeath() const {
    return this->dateOfDeath;
}
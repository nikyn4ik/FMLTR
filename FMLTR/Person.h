#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    std::string dateOfBirth;
    std::string dateOfDeath;
    Person* person;

public:
    Person(std::string name, std::string dateOfBirth = "", std::string dateOfDeath = "");
    void setPerson(Person* person);
    void setDateOfBirth(std::string dateOfBirth);
    void setDateOfDeath(std::string dateOfDeath);
    std::string getName() const;
    std::string getDateOfBirth() const;
    std::string getDateOfDeath() const;
    void display(Person* person, int level = 0) const;
    std::string getDateOfBirthAndDeath() const;
};

#endif

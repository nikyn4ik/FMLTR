#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
private:
    std::string name;
    std::string dateOfBirth;
    std::string dateOfDeath;
    Person* mother;
    Person* father;

public:
    Person(std::string name, std::string dateOfBirth = "", std::string dateOfDeath = "");
    void setMother(Person* mother);
    void setFather(Person* father);
    void setDateOfBirth(std::string dateOfBirth);
    void setDateOfDeath(std::string dateOfDeath);
    std::string getName();
    std::string getDateOfBirth();
    std::string getDateOfDeath();
    Person* getMother();
    Person* getFather();
};
#endif

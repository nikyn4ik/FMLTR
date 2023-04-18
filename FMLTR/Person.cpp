#include "Person.h"

Person::Person(std::string name, std::string dateOfBirth, std::string dateOfDeath) {
	this->name = name;
	this->dateOfBirth = dateOfBirth;
	this->dateOfDeath = dateOfDeath;
	this->mother = nullptr;
	this->father = nullptr;
}

void Person::setMother(Person* mother) {
	this->mother = mother;
}

void Person::setFather(Person* father) {
	this->father = father;
}

void Person::setDateOfBirth(std::string dateOfBirth) {
	this->dateOfBirth = dateOfBirth;
}

void Person::setDateOfDeath(std::string dateOfDeath) {
	this->dateOfDeath = dateOfDeath;
}

std::string Person::getName() {
	return this->name;
}

std::string Person::getDateOfBirth() {
	return this->dateOfBirth;
}

std::string Person::getDateOfDeath() {
	return this->dateOfDeath;
}

Person* Person::getMother() {
	return this->mother;
}

Person* Person::getFather() {
	return this->father;
}

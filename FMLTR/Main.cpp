// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*—оздание семейного древа :
1. ¬ывод семейного древа
2. —охранение семейного древа
3. —равнение поколений в семейном древе */

//директивы
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <regex>
#include "Person.h"

Person::Person(std::string n, std::string d, Person* m, Person* f) { //конструктор "Person"
	name = n;
	dob = d;
	mother = m;
	father = f;
	if (m == 0) {
		generation = 0;
	}
	else {
		generation = 1;
	}
}

void Person::addChild(Person* child) { //метод addChild
	try {
		if (child == 0) {
			throw std::invalid_argument("Invalid child. Child cannot be null.");
		}
		children.push_back(child);
		generation = child->generation + 1;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception in addChild: " << e.what() << std::endl;
	}
}

void Person::setMother(Person* m) {//метод setMother
	mother = m;
	try {
		if (m == 0) {
			throw std::invalid_argument("Invalid mother. Mother cannot be null.");
		}
		m->addChild(this);
		generation = m->generation - 1;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception in setMother: " << e.what() << std::endl;
	}
}

void Person::setFather(Person* f) {//метод setFather
	father = f;
	try {
		if (f == 0) {
			throw std::invalid_argument("Invalid father. Father cannot be null.");
		}
		f->addChild(this);
		generation = f->generation - 1;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception in setFather: " << e.what() << std::endl;
	}
}

void Person::printTree(int depth) { //вывод дерева
	try {
		for (int i = 0; i < depth; i++) {
			std::cout << "  ";
		}
		std::cout << "-> " << name << " (generation " << generation << ", " << dob;
		if (dod != "") {
			std::cout << " - " << dod;
		}
		std::cout << ")" << std::endl;
		if (mother != 0) {
			mother->printTree(depth + 1);
		}
		if (father != 0) {
			father->printTree(depth + 1);
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception in printTree: " << e.what() << std::endl;
	}
};

bool checkName(const std::string& name, const std::map<std::string, Person*>& people) {
	\
		std::regex namePattern("^[a-zA-Z]+$");
	return std::regex_match(name, namePattern);
}


bool checkDate(const std::string& date) {
	\
		std::regex datePattern("^\\d{2}-\\d{2}-\\d{4}$");
	return std::regex_match(date, datePattern);
}


bool checkChoice(int choice) {
	return choice >= 1 && choice <= 3;
}

void saveTree(Person* root) { //сохранение дерева в файл
	std::string filename;
	std::cout << "Enter file name or file path to save the family tree: ";
	std::cin >> filename;
	std::string fileformat = filename.substr(filename.find_last_of(".") + 1);

	try {
		std::ofstream file(filename);
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file for writing!");
		}

		file << "Family Tree\n\n";
		std::map<Person*, int> generationMap;

		int currentGeneration = 0;
		std::vector<Person*> currentLevel, nextLevel;
		currentLevel.push_back(root);
		generationMap[root] = 0;

		while (!currentLevel.empty()) {
			for (Person* person : currentLevel) {
				file << person->name << " (generation " << generationMap[person] << ", " << person->dob;
				if (person->dod != "") {
					file << " - " << person->dod;
				}
				file << ")\n";
				if (person->mother != 0) {
					file << "  Mother: " << person->mother->name << "\n";
					nextLevel.push_back(person->mother);
					generationMap[person->mother] = generationMap[person] + 1;
				}
				if (person->father != 0) {
					file << "  Father: " << person->father->name << "\n";
					nextLevel.push_back(person->father);
					generationMap[person->father] = generationMap[person] + 1;
				}
			}
			file << "\n";
			currentLevel = nextLevel;
			nextLevel.clear();
		}

		file.close();
		std::cout << "Family tree saved to " << filename << " (" << fileformat << " format)" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void addRelationship(std::map<std::string, Person*>& people) { //добавление св€зей между родственниками
	std::string childName, parentName;
	int relationshipType;

	try {
		std::cout << "Enter the name of the child: ";
		std::cin >> childName;
		if (!checkName(childName, people)) {
			throw std::runtime_error("A person with this name does not exist.");
		}

		std::cout << "Enter the name of the parent: ";
		std::cin >> parentName;
		if (!checkName(parentName, people)) {
			throw std::runtime_error("A person with this name does not exist.");
		}

		std::cout << "Select relationship type:" << std::endl;
		std::cout << "1. Mother" << std::endl;
		std::cout << "2. Father" << std::endl;
		std::cin >> relationshipType;
		if (!checkChoice(relationshipType)) {
			throw std::runtime_error("Invalid choice.");
		}

		Person* child = people[childName];
		Person* parent = people[parentName];
		if (relationshipType == 1) {
			if (child->mother != 0) {
				throw std::runtime_error(childName + " already has a mother.");
			}
			child->setMother(parent);
		}
		else {
			if (child->father != 0) {
				throw std::runtime_error(childName + " already has a father.");
			}
			child->setFather(parent);
		}

		std::cout << "Relationship added." << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
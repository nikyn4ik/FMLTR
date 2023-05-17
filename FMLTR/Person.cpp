//директивыss
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <regex>
#include "Person.h"

void createTree() { //создание дерева
	std::map<std::string, Person*> people;
	int choice;
	int generation = 0;
	Person* root = 0;
	bool personCreated = false;

	while (true) {
		std::cout << "Select option:" << std::endl;
		if (!personCreated) {
			std::cout << "1. Add person" << std::endl;
		}
		else {
			std::cout << "1. Add another person" << std::endl;
		}
		std::cout << "2. Add relationship" << std::endl;
		std::cout << "3. Print tree" << std::endl;
		std::cout << "4. Exit" << std::endl;
		std::cin >> choice;

		try {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::runtime_error("Invalid input. Please enter a number.");
			}

			if (choice == 1) {
				std::string name, dob, dod;
				std::cout << "Enter name: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				if (!std::regex_match(name, std::regex("^[a-zA-Z]+$"))) {
					std::cout << "Invalid name format. Please enter only letters." << std::endl;
					continue;
				}
				std::cout << "Enter date of birth (DD-MM-YYYY): ";
				std::cin >> dob;
				if (!std::regex_match(dob, std::regex("^\\d{2}-\\d{2}-\\d{4}$"))) {
					std::cout << "Invalid date format. Please enter the date in DD-MM-YYYY format." << std::endl;
					continue;
				}
				std::cout << "Enter date of death (DD-MM-YYYY) or (press Enter to skip): ";
				std::cin.ignore();
				std::getline(std::cin, dod);
				if (!dod.empty() && !std::regex_match(dod, std::regex("^\\d{2}-\\d{2}-\\d{4}$"))) {
					std::cout << "Invalid date format. Please enter the date in DD-MM-YYYY format or press Enter to skip." << std::endl;
					continue;
				}
				Person* newPerson = new Person(name, dob);
				if (!dod.empty()) {
					newPerson->dod = dod;
				}
				if (root == 0) {
					root = newPerson;
				}
				people[name] = newPerson;
				personCreated = true;
				std::cout << "Person added." << std::endl;
			}
			else if (choice == 2) {
				addRelationship(people);
			}
			else if (choice == 3) {
				if (!personCreated) {
					std::cout << "Please create a person first." << std::endl;
					continue;
				}
				root->printTree();
				int printChoice;
				std::cout << "Select option:" << std::endl;
				std::cout << "1. Save tree" << std::endl;
				std::cout << "2. Exit" << std::endl;
				std::cin >> printChoice;
				if (printChoice == 1) {
					saveTree(root);
				}
				else if (printChoice == 2) {
					continue;
				}
				else {
					std::cout << "Invalid choice." << std::endl;
					continue;
				}
			}
			else if (choice == 4) {
				return;
			}
			else {
				std::cout << "Invalid choice." << std::endl;
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
			continue;
		}
	}
}

void SelectFile() //выбор файла
{
	std::string filename;
	std::cout << "Enter file name or file path: ";
	std::cin >> filename;

	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Failed to open file!" << std::endl;
	}
	else {
		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();
	}
}

void Compare() //сравнение (в каком из файлов большее кол-во поколений)
{
	std::string filename1;
	std::cout << "Enter the name of the first file: ";
	std::cin >> filename1;
	std::ifstream file1(filename1);

	if (!file1) {
		std::cerr << "Failed to open file " << filename1 << std::endl;
		return;
	}

	std::string filename2;
	std::cout << "Enter the name of the second file: ";
	std::cin >> filename2;
	std::ifstream file2(filename2);

	if (!file2) {
		std::cerr << "Failed to open file " << filename2 << std::endl;
		return;
	}

	int num_generations1 = 0, num_generations2 = 0;
	std::string line;
	std::string _;
	while (std::getline(file1, line)) {
		if (line.find("generation") != std::string::npos) {
			std::stringstream ln(line);
			ln >> _ >> _ >> num_generations1;
		}
	}
	while (std::getline(file2, line)) {
		if (line.find("generation") != std::string::npos) {
			std::stringstream ln(line);
			ln >> _ >> _ >> num_generations2;
		}
	}

	if (num_generations1 > num_generations2) {
		std::cout << filename1 << " has more generations (" << num_generations1 + 1 << " vs " << num_generations2 + 1 << ")" << std::endl;
	}
	else if (num_generations2 > num_generations1) {
		std::cout << filename2 << " has more generations (" << num_generations2 + 1 << " vs " << num_generations1 + 1 << ")" << std::endl;
	}
	else {
		std::cout << "The two files have the same number of generations (" << num_generations1 + 1 << ")" << std::endl;
	}
	file1.close();
	file2.close();
}

int main() { //осн. функция - осн. меню
	while (true) {
		std::cout << "Select option:" << std::endl;
		std::cout << "1. Create a family tree" << std::endl;
		std::cout << "2. Read a family tree" << std::endl;
		std::cout << "3. Compare" << std::endl;
		std::cout << "4. Exit" << std::endl;

		int choice;
		try {
			std::cin >> choice;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw std::runtime_error("Invalid input. Please enter a number.");
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
			continue;
		}

		if (choice == 1) {
			createTree();
		}
		else if (choice == 2) {
			SelectFile();
		}
		else if (choice == 3) {
			Compare();
		}
		else if (choice == 4) {
			return 0;
		}
		else {
			std::cout << "Invalid choice. Please try again." << std::endl;
			continue;
		}
	}
	return 0;
}
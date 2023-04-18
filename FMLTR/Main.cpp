// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Tree.h"
#include <iostream>
#include <regex>

bool checkName(const std::string& name) {
    for (const char& c : name) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

bool checkChoice(char choice) {
    return choice == 'y' || choice == 'n';
}

bool checkDate(const std::string& date) {
    std::regex regex("\\d{4}-\\d{2}-\\d{2}");
    return std::regex_match(date, regex);
}
//добавить меню, сохранение сравнение и тд
int main() {
    std::string myName, momName, dadName, grandmaName, grandpaName, grandmaName2, grandpaName2;
    std::string myBirth, momBirth, dadBirth, grandmaBirth, grandpaBirth, grandmaBirth2, grandpaBirth2;
    std::string momDeath, dadDeath, grandmaDeath, grandpaDeath, grandmaDeath2, grandpaDeath2;
    bool addMom = true, addDad = true;

    std::cout << "Enter your name: "; //ME
    std::getline(std::cin, myName);
    while (!checkName(myName)) {
        std::cout << "Invalid name. Please enter a name containing only letters: ";
        std::getline(std::cin, myName);
    }
    std::cout << "Enter your's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, myBirth);
    while (!checkDate(myBirth)) {
        std::cout << "Invalid date. Please enter a date in the format YYYY-MM-DD: ";
        std::getline(std::cin, myBirth);
    }
    Person me(myName, myBirth);

    std::cout << "Do you want to add your mother? (y/n) "; //ADD MOM
    char answer;
    std::cin >> answer;
    while (!checkChoice(answer)) {
        std::cout << "Invalid choice. Please enter either 'y' or 'n': ";
        std::cin >> answer;
    }
    std::cin.ignore();
    if (answer == 'n') {
        addMom = false;
    }
    std::cout << "Do you want to add your father? (y/n) "; //ADD DAD
    std::cin >> answer;
    while (!checkChoice(answer)) {
        std::cout << "Invalid choice. Please enter either 'y' or 'n': ";
        std::cin >> answer;
    }
    std::cin.ignore();
    if (answer == 'n') {
        addDad = false;
    }
    if (addDad || addMom) {
        if (addMom) {
            std::cout << "Enter your mother's name: "; //MOM
            std::getline(std::cin, momName);
            while (!checkName(momName)) {
                std::cout << "Invalid name. Please enter a name containing only letters: ";
                std::getline(std::cin, momName);
            }
            std::cout << "Enter your mother's date of birth (YYYY-MM-DD): ";
            std::getline(std::cin, momBirth);
            while (!checkDate(momBirth)) {
                std::cout << "Invalid date. Please enter a date in the format YYYY-MM-DD: ";
                std::getline(std::cin, momBirth);
            }
            std::cout << "Enter your mother's date of death (if alive enter '-'): ";
            std::getline(std::cin, momDeath);
            Person mom(momName, momBirth, momDeath);

            std::cout << "Enter your mother's mother's name: "; //GRANDMOM MOM
            std::getline(std::cin, grandmaName);
            while (!checkName(grandmaName)) {
                std::cout << "Invalid name. Please enter a name containing only letters: ";
                std::getline(std::cin, grandmaName);
            }
            std::cout << "Enter your mother's mother's date of birth (YYYY-MM-DD): ";
            std::getline(std::cin, grandmaBirth);
            while (!checkDate(grandmaBirth)) {
                std::cout << "Invalid date. Please enter a date in the format YYYY-MM-DD: ";
                std::getline(std::cin, grandmaBirth);
            }
            std::cout << "Enter your mother's mother's date of death (if alive enter '-'): ";
            std::getline(std::cin, grandmaDeath);
            Person grandma(grandmaName, grandmaBirth, grandmaDeath);

            std::cout << "Enter your mother's father's name: "; //GRANDPA MOM
            std::getline(std::cin, grandpaName);
            while (!checkName(grandpaName)) {
                std::cout << "Invalid name. Please enter a name containing only letters: ";
                std::getline(std::cin, grandpaName);
            }
            std::cout << "Enter your mother's father's date of birth (YYYY-MM-DD): ";
            std::getline(std::cin, grandpaBirth);
            while (!checkDate(grandpaBirth)) {
                std::cout << "Invalid date. Please enter a date in the format YYYY-MM-DD: ";
                std::getline(std::cin, grandpaBirth);
            }
            std::cout << "Enter your mother's father's date of death (if alive enter '-'): ";
            std::getline(std::cin, grandpaDeath);
            Person grandpa(grandpaName, grandpaBirth, grandpaDeath);


            if (addDad) {
                std::cout << "Enter your father's name: "; //DAD
                std::getline(std::cin, dadName);
                while (!checkName(dadName)) {
                    std::cout << "Invalid name. Please enter a name containing only letters: ";
                    std::getline(std::cin, dadName);
                }
                std::cout << "Enter your father's date of birth (YYYY-MM-DD): ";
                std::getline(std::cin, dadBirth);
                while (!checkDate(dadBirth)) {
                    std::cout << "Invalid date. Please enter a date in the format YYYY-MM-DD: ";
                    std::getline(std::cin, dadBirth);
                }
                std::cout << "Enter your father's date of death (if alive enter '-'): ";
                std::getline(std::cin, dadDeath);
                Person dad(dadName, dadBirth, dadDeath);

                std::cout << "Enter your father's mother's name: "; //GRANDMA DAD
                std::getline(std::cin, grandmaName2);
                while (!checkName(grandmaName2)) {
                    std::cout << "Invalid name. Please enter a name containing only letters: ";
                    std::getline(std::cin, grandmaName2);
                }
                std::cout << "Enter your father's mother's date of birth (YYYY-MM-DD): ";
                std::getline(std::cin, grandmaBirth2);
                while (!checkDate(grandmaBirth2)) {
                    std::cout << "Invalid date. Please enter a date in the format YYYY-MM-DD: ";
                    std::getline(std::cin, grandmaBirth2);
                }
                std::cout << "Enter your father's mother's date of death (if alive enter '-'): ";
                std::getline(std::cin, grandmaDeath2);
                Person grandma2(grandmaName2, grandmaBirth2, grandmaDeath2);

                std::cout << "Enter your father's father's name: "; //GRANDPA DAD
                std::getline(std::cin, grandpaName2);
                while (!checkName(grandpaName2)) {
                    std::cout << "Invalid name. Please enter a name containing only letters: ";
                    std::getline(std::cin, grandpaName2);
                }
                std::cout << "Enter your father's father's date of birth (YYYY-MM-DD): "; 
                std::getline(std::cin, grandpaName2);
                while (!checkDate(grandpaName2)) {
                    std::cout << "Invalid date. Please enter a date in the format YYYY-MM-DD: ";
                    std::getline(std::cin, grandpaName2);
                }
                std::cout << "Enter your father's father's date of death (if alive enter '-'): ";
                std::getline(std::cin, grandpaDeath2);
                Person grandpa2(grandpaName2, grandpaBirth2, grandpaDeath2);

                std::string treeName;
                std::cout << "Enter the name of the tree: ";
                std::getline(std::cin, treeName);
                //Tree familyTree(&me);
                Tree familyTree(&me, treeName);
                familyTree.addMom(mom);
                familyTree.addDad(dad);
                familyTree.addGrandmaMom(grandmaName);
                familyTree.addGrandpaMom(grandpaName);
                familyTree.addGrandmaDad(grandmaName2);
                familyTree.addGrandpaDad(grandpaName2);
                familyTree.printTree();
            }

            else {

                std::string treeName;
                std::cout << "Enter the name of the tree: " << std::endl;;
                std::getline(std::cin, treeName);
                Tree familyTree(&me, treeName);
                familyTree.printTree();
            }

            return 0;
        }
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

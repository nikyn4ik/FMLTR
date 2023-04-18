// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Tree.h"
#include <iostream>

//добавить меню, сохранение сравнение и тд
int main() {
    std::string myName, momName, dadName, grandmaName, grandpaName, grandmaName2, grandpaName2;
    std::string myBirth, momBirth, dadBirth, grandmaBirth, grandpaBirth, grandmaBirth2, grandpaBirth2;
    std::string momDeath, dadDeath, grandmaDeath, grandpaDeath, grandmaDeath2, grandpaDeath2;

    std::cout << "Enter your name: ";
    std::getline(std::cin, myName);
    std::cout << "Enter your's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, myBirth);
    Person me(myName, myBirth);

    std::cout << "Enter your mother's name: ";
    std::getline(std::cin, momName);
    std::cout << "Enter your mother's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, momBirth);
    std::cout << "Enter your mother's date of death (if alive enter '-'): ";
    std::getline(std::cin, momDeath);
    Person mom(momName, momBirth, momDeath);

    std::cout << "Enter your mother's mother's name: ";
    std::getline(std::cin, grandmaName);
    std::cout << "Enter your mother's mother's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, grandmaBirth);
    std::cout << "Enter your mother's mother's date of death (if alive enter '-'): ";
    std::getline(std::cin, grandmaDeath);
    Person grandma(momName, grandmaBirth, grandmaDeath);

    std::cout << "Enter your mother's father's name: ";
    std::getline(std::cin, grandpaName);
    std::cout << "Enter your mother's father's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, grandpaBirth);
    std::cout << "Enter your mother's father's date of death (if alive enter '-'): ";
    std::getline(std::cin, grandpaDeath);
    Person grandpa(momName, grandpaBirth, grandpaDeath);



    std::cout << "Enter your father's name: ";
    std::getline(std::cin, dadName);
    std::cout << "Enter your father's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, dadBirth);
    std::cout << "Enter your father's date of death (if alive enter '-'): ";
    std::getline(std::cin, dadDeath);
    Person dad(dadName, dadBirth, dadDeath);

    std::cout << "Enter your father's mother's name: ";
    std::getline(std::cin, grandmaName2);
    std::cout << "Enter your father's mother's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, grandmaBirth2);
    std::cout << "Enter your father's mother's date of death (if alive enter '-'): ";
    std::getline(std::cin, grandmaDeath2);
    Person grandma2(dadName, grandmaBirth2, grandmaDeath2);

    std::cout << "Enter your father's father's name: ";
    std::getline(std::cin, grandpaName2);
    std::cout << "Enter your father's father's date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, grandpaName2);
    std::cout << "Enter your father's father's date of death (if alive enter '-'): ";
    std::getline(std::cin, grandpaDeath2);
    Person grandpa2(dadName, grandpaBirth2, grandpaDeath2);

    Tree familyTree(&me);
    familyTree.addMom(mom);
    familyTree.addDad(dad);
    familyTree.addGrandmaMom(grandmaName);
    familyTree.addGrandpaMom(grandpaName);
    familyTree.addGrandmaDad(grandmaName2);
    familyTree.addGrandpaDad(grandpaName2);

    std::cout << std::endl << "Family tree:" << std::endl;
    familyTree.printTree();

    return 0;
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

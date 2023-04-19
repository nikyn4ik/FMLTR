// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Tree.h"
#include <iostream>
#include <regex>
#include <vector>
#include "Person.h"
using namespace std;

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
    std::vector<Tree> trees;
    bool running = true;
    int choice;
    int treeIndex = 0;

    while (running) {

        cout << "What would you like to do?" << endl;
        cout << "1. Create a family tree" << endl;
        cout << "2. Add a family member" << endl;
        cout << "3. Print the current family tree" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice) {

        case 1: {
            string name;
            string dob;

            cout << "What is the name of the root person?" << endl;
            cin >> name;

            cout << "What is the date of birth of " << name << "?" << endl;
            cin >> dob;

            Person* root = new Person(name, dob);
            Tree tree(root, name);
            trees.push_back(tree);
            treeIndex = trees.size() - 1;
            break;
        }

        case 2: {
            if (trees.size() == 0) {
                cout << "No family tree created yet. Please create a tree first." << endl;
                break;
            }
            int choice2;
            string name, dob;

            cout << "Which family member would you like to add to?" << endl;
            cout << "1. Root person" << endl;
            cout << "2. Mother of root person" << endl;
            cout << "3. Father of root person" << endl;
            cin >> choice2;

            cout << "What is the name of the new family member?" << endl;
            cin >> name;

            cout << "What is the date of birth of " << name << "?" << endl;
            cin >> dob;

            Person* person = new Person(name, dob);

            switch (choice2) {

            case 1:
                trees[treeIndex].addPerson(*person);
                break;

            case 2:
                //exit
                break;
            }
            break;
        }

        case 3: {
            if (trees.size() == 0) {
                cout << "No family tree created yet. Please create a tree first." << endl;
                break;
            }
            trees[treeIndex].printTree();
            break;
        }

        case 4: {
            cout << "Exiting the program..." << endl;
            running = false;
            break;
        }

        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }

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

#ifndef PERSON_H
#define PERSON_H

//директивы
#include <string>
#include <vector>
#include <map>

class Person {
public:
    //переменные, содержащие информацию о человеке
    std::string name; // имя человека
    std::string dob; // дата рождения
    std::string dod; // дата смерти
    int generation; //поколение
    Person* mother; //мать
    Person* father; //отец
    std::vector<Person*> children; //ребёнок

    Person(std::string n, std::string d, Person* m = 0, Person* f = 0); //конструктор класса "Person".
    void addChild(Person* child); //добавление "child" текущему объекту "Person"
    void setMother(Person* m); //мать "m" для текущего объекта "Person"
    void setFather(Person* f); //отец "f" для текущего объекта "Person"
    void printTree(int depth = 0); //вывод семейного дерева
};

bool checkName(const std::string& name, const std::map<std::string, Person*>& people); // исключение - сущ. ли заданное имя в "People"
bool checkDate(const std::string& date); // исключение - является ли заданная дата "date" допустимой
bool checkChoice(int choice); // исключение - является ли заданный выбор "choice" допустимым
void saveTree(Person* root); ////сохранение дерева в файл
void addRelationship(std::map<std::string, Person*>& people); //добавление связей между родственниками
void createTree(); //создание дерева
void SelectFile(); //выбор файла
void Compare(); //сравнение (в каком из файлов большее кол-во поколений)

#endif

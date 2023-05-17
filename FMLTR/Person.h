#ifndef PERSON_H
#define PERSON_H

//���������
#include <string>
#include <vector>
#include <map>

class Person {
public:
    //����������, ���������� ���������� � ��������
    std::string name; // ��� ��������
    std::string dob; // ���� ��������
    std::string dod; // ���� ������
    int generation; //���������
    Person* mother; //����
    Person* father; //����
    std::vector<Person*> children; //������

    Person(std::string n, std::string d, Person* m = 0, Person* f = 0); //����������� ������ "Person".
    void addChild(Person* child); //���������� "child" �������� ������� "Person"
    void setMother(Person* m); //���� "m" ��� �������� ������� "Person"
    void setFather(Person* f); //���� "f" ��� �������� ������� "Person"
    void printTree(int depth = 0); //����� ��������� ������
};

bool checkName(const std::string& name, const std::map<std::string, Person*>& people); // ���������� - ���. �� �������� ��� � "People"
bool checkDate(const std::string& date); // ���������� - �������� �� �������� ���� "date" ����������
bool checkChoice(int choice); // ���������� - �������� �� �������� ����� "choice" ����������
void saveTree(Person* root); ////���������� ������ � ����
void addRelationship(std::map<std::string, Person*>& people); //���������� ������ ����� ��������������
void createTree(); //�������� ������
void SelectFile(); //����� �����
void Compare(); //��������� (� ����� �� ������ ������� ���-�� ���������)

#endif

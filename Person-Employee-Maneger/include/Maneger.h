#include<iostream>
#include"Person.h"
#include"Employee.h"
#include <vector>
#ifndef MANEGER_H
#define MANEGER_H

using namespace std;

class Maneger :public Employee {
private:
	int manegerBonus;
public:
	Maneger(string name, string surname, string department, string position,string ID, int salary, int year) :Employee(name, surname, department, position, ID, salary, year) {
		manegerBonus = year * 150;
		int random = rand() % 8999 + 1000;
		Maneger::setID("MNG" + to_string(random)); 
	}
	void print() {
		Person::print();
		cout << "Bonus: " << manegerBonus << endl;
		cout << "-----------------------------------------" << endl;
	}
	void extractEmployees(vector<Employee>& employeeList) {
		cout << "Maneger Name: " << Maneger::getName() << " " << Maneger::getSurnamee() << endl;
		cout << "Maneger ID: " << Maneger::getID() << endl;
		cout << "Maneger Department: " << Maneger::getDepartment() << endl; 
		cout << Maneger::getDepartment() << " Department Employees List" << endl;
		cout << "-----------------------------------------" << endl;
		for (int i = 0; i < employeeList.size(); i++) {
			if (getDepartment() == employeeList[i].getDepartment()) {
				employeeList[i].print();
			}
		}
	}
};
#endif
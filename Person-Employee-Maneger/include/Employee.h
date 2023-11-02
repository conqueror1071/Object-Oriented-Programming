#include<iostream>
#include"Person.h"
#ifndef EMPLOYEE_H 
#define EMPLOYEE_H

using namespace std;

class Employee :public Person {
private:
	int employeeBonus;
public:
	Employee(string name, string surname, string department, string position, string ID, int salary, int year) :Person(name, surname, department, position, ID, salary, year) { 
		employeeBonus = year * 85;
		int random = rand() % 8999 + 1000;
		Employee::setID("EMP" + to_string(random));  
	}
	void print() {
		Person::print();
		cout << "Bonus: " << employeeBonus << endl;
		cout << "-----------------------------------------" << endl;
	}
};
#endif

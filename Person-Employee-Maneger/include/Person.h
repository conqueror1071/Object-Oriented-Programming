#include<iostream>
#include <string>
#ifndef PERSON_H 
#define PERSON_H
using namespace std;

class Person {
protected:
	string personName, personSurname, personDepartment, personPosition, personID;
	int personSalary, personYear;
public:
	Person(string name, string surname, string department, string position, string ID, int salary, int year) {
		personName = name; personSurname = surname;
		personDepartment = department; personPosition = position;
		personID = ID; personSalary = salary; personYear = year;
	}
	void setName(string name){personName = name;}
	void setSurame(string surname) {personSurname = surname;}
	void setDepartment(string department) {personDepartment = department;}
	void setPosition(string position) {personPosition = position;}
	void setID(string ID) {personID = ID;}
	void setSalary(int salary) {personSalary = salary;}
	void setYear(int year) {personYear = year; }
	string getName() { return personName; }
	string getSurnamee() { return personSurname; }
	string getDepartment() { return personDepartment; }
	string getPosition() { return personPosition; }
	string getID() { return personID; }
	int getSalary() { return personSalary; }
	int getYear() { return personYear; }
	void print() {
		cout << "NAME: " << personName << " " << personSurname << endl;
		cout << "ID: " << personID << endl; 
		cout << "Department: " << personDepartment << endl;
		cout << "Position: " << personPosition << endl;
		cout << "Years worked: " << personYear << endl;
		cout << "Salary: " << personSalary << endl; 
	}
};
#endif 
#include<iostream>
#include <vector> 
#include"Person.h"
#include"Employee.h"
#include"Maneger.h"
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");  


	Employee emp1("Fatih", "Altunel", "Software", "Engineer", "1111", 12350, 5);
	Employee emp2("Mustafa", "Öztürk", "Software", "Designer", "1112", 6780, 1);
	Employee emp3("Ukbe", "Þahinkaya", "Software", "Programmer", "1113", 10000, 2);
	Employee emp4("Arda", "Timuçin", "IT", "Analysis", "1114", 11780, 2);
	Employee emp5("Alperen", "Ögke", "HumanResource", "Çaycý", "1115", 34780, 4);

	Maneger mng1("Poyraz", "Yýlmaz", "Software", "Maneger", "2001", 72860, 11);  
	Maneger mng2("Eren", "Genç", "HumanResource", "Maneger", "2002", 72860, 9); 


	vector<Employee> employeeList = { emp1, emp2, emp3, emp4, emp5 };  
	mng1.extractEmployees(employeeList); 
	cout << "*****************************************" << endl;
	mng2.extractEmployees(employeeList);
	return 0;
}
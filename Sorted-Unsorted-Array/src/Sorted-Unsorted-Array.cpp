#include<iostream>
#include <ctime> 
#include"Header.h"
#include"SortedArray.h"
using namespace std;

int main() {
	srand(time(0));
	int random = rand() % 10 + 1; 
	int random2 = rand() % 10 + 1;  
	Array array1(10);            
	SortedArray array2(10);        

	for (int i = 0; i < random; i++) {
		int random_element = rand() % 99 + 1;
		array1.addElement(random_element);
	}
	array1.printElements();
	cout << "\n------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < random2; i++) {  
		int random_element = rand() % 99 + 1; 
		array2.addElement(random_element); 
	} 
	array2.printElements(); 
}
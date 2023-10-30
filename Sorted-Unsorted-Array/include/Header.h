#include<iostream>
#ifndef HEADER_H
#define HEADER_H
using namespace std;
class Array {  
protected:  
	int* data;   
	int size; 
	int capacity;  
public:
	Array(int user_capasity=5) { 
		capacity = user_capasity;
		data = new int[capacity]; 
		size = 0;
	}
	~Array() {
		if (data != nullptr) {
			delete[] data; 
			data = nullptr; 
		}
	}
	//Dizinin elemanlarýný yazdýrýr
	void printElements() { 
		if (size != 0) {
			cout << "Array => ";
			for (int i = 0; i < size; i++) {
				if (i == 0) {
					cout << "[" << data[i]<<", ";
				}
				else if (i > 0 && i < size - 1) {
					cout << data[i] << ", ";
				}
				if (i == size - 1) {
					cout << data[i] << "]";
				}
			}
		}
		else {
			cout << "Your array does not include any element!" << endl;
		}
		cout << "\nCapacity: " << capacity << "\nSize: " << size; 
	}
	//Dizinin belirtilen indexindeki terimi siler 
	void removeIndexElement(int index) {
		if (index<0 || index>capacity) {
			cout << "There isn't any element at that index!" << endl; 
		}
		else {
			for (int i = index; i < size; i++) {
				data[i] = data[i+1]; 
			}
		} 
		size--; 
		cout << "Element at the index" << index << " is succesfully deleted" << endl; 
	}
	//Dizinin belirtilen teriminden kaç tane varsa bulur ve hepsini siler
	void removeElement(int element) {
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (data[i] == element) {
				counter++;
				for (int j = i; j < size; j++) {
					data[j] = data[j + 1];
				}
				i--; 
			}
		}
		size -= counter; 
		if (counter == 1) {
			cout << "There is " << counter << " set of " << element << " element at this array" << endl;
			cout << "Element " << element << " is deleted from tha array succesfully" << endl;
		}
		else if(counter > 1) { 
			cout << "There are " << counter << " sets of " << element << " elements at this array" << endl;
			cout << "Elements of " << element << " are deleted from tha array" << endl; 
		}
	}
	//Kullanýcýnýn belirttiði indexten sonra yine kullanýcýnýn belirttiði terimin olup olmadýðýný kontrol eder. Terim varsa hangi indexlerde olduðunu yazdýrýr
	void FindIndex(int index, int element) {
		int counter = 0;
		int size2 = 0;    
		int *temp = new int[size];      
		for (int i = index; i < size; i++) {
			if (data[i] == element) {
				counter++;
				temp[size2] = i; 
				size2++; 
			}
		}
		if (size2 == 1) {
			cout << "There is " << counter << " occurences of the term " << element << " at the " << temp[0] << ". index after the " << index << ". index." << endl;
			delete[]temp;
		}
		else if (size2>1) {
			cout << "There are " << counter << " occurences of the term " << element << " in the fallowing indicies after the " << index << ". index" << endl;
			for (int i = 0; i < size2; i++) {
				cout << temp[i]<<". "; 
			}
			delete[]temp; 
		}
		else {
			cout<<"There is " << counter << " occurences of the term " << element << "in the fallowing indicies after the " << index << ". index" << endl; 
			delete[]temp; 
		}
	}
	//Diziye terim ekler. Kapasite yetmezse iki katýna çýkarýlýr ve eleman eklenir
	void addElement(int element) { 
		if (size < capacity) {     
			data[size] = element;    
			size++;    
		} 
		else {
			capacity *= 2;
			int* temp_data = new int[capacity];
			for (int i = 0; i < size; i++) {
				temp_data[i] = data[i];  
			}
			delete[]data; 
			data = temp_data;    
			data[size] = element;     
			size++;    
		} 
	} 
};
#endif 

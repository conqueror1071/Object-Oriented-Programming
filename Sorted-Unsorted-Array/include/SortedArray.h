#include<iostream>
#ifndef SORTEDARRAY_H   
#define	SORTEDARRAY_H
using namespace std;
class SortedArray : public Array {
public:   
	SortedArray(int user_capacity = 5) :Array(user_capacity) {}; 
	~SortedArray() {
		if (data != nullptr) {
			delete[] data;  
			data = nullptr; 
		} 
	}
	void addElement(int element);
	void printElements();
};
void SortedArray::addElement(int element) {
	int i; 
	if (size == capacity) {  
		capacity = capacity * 2; 
		int *temp_data = new int[capacity]; 
		for (int i = 0; i < size; i++) {
			temp_data[i] = data[i];
		}
		delete[]data; 
		data = temp_data;    
	} 
	for (i = size - 1; (i >= 0 && data[i] > element); i--) {   
		data[i + 1] = data[i];  
	}
	data[i + 1] = element;  
	size++;
}
void SortedArray::printElements() {
	cout << "Sorted ";
	Array::printElements();
}
#endif

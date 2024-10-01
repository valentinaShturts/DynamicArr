#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr; 
	int size;  
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); 
	~DynamicArray();

	void Input();
	void Output() const;
	int* GetPointer() const;
	int GetSize() const;

	
	void ReSize(int new_size);
	void Sort();
	int Search(int a); 
	void Reverse(); 

	DynamicArray operator+(int a);
	DynamicArray operator-(int a);
	DynamicArray operator*(int a);
	DynamicArray operator+(DynamicArray b);
	DynamicArray operator-(DynamicArray b);
	DynamicArray operator++();
	DynamicArray operator--();
};


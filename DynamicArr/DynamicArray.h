#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr; // указатель на динам. массив
	int size;  // размер массива 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();

	void Input();// rand
	void Output() const;// вывод на консоль
	int* GetPointer() const;
	int GetSize() const;

	// реилизовать следующие методы:
	void ReSize(int new_size);// изменение размера массива
	void Sort();// сортировка(любой алгоритм сортировки)
	int Search(int a); // поиск элемента в массиве, возвращает индекс наиденного эл., либо -1.
	void Reverse(); // перезаписывает последовательность элементов в обратном порядке, напрмер 12345 -> 54321



};


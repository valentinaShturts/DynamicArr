#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)// copy constructor
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	delete[] ptr;


}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << "\n---------------------------------\n";
}
int* DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize() const
{
	return size;
}
void DynamicArray::ReSize(int new_size)
{
	int* new_ptr = new int[new_size];
	for (int i = 0; i < new_size; i++)
	{
		new_ptr[i] = this->ptr[i];
	}
	this->size = new_size;
	for (int i = 0; i < size; i++)
	{
		ptr[i] = new_ptr[i];
	}
	delete[] new_ptr;
}
void DynamicArray::Sort()
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (ptr[j] > ptr[j + 1]) swap(ptr[j], ptr[j + 1]);
		}
	}
}

int DynamicArray::Search(int a)
{
	bool isFound = false;
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] == a) {
			isFound = true; 
			return i;
		}
	}
	if (!isFound) return -1;
}

void DynamicArray::Reverse()
{
	int end = size - 1;
	for (int i = 0; i < end; i++)
	{
		swap(ptr[i], ptr[end]);
		end--;
	}
}
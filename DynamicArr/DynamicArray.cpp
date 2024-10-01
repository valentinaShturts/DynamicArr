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

DynamicArray::DynamicArray(const DynamicArray& a)
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

	int temp;
	if (new_size < this->size) temp = new_size;
	else { temp = this->size;}

	for (int i = 0; i < temp; i++)
	{
		new_ptr[i] = this->ptr[i];
	}

	for (int i = temp; i < new_size; i++)
	{
		new_ptr[i] = 0;
	}

	delete[] this->ptr;
	this->ptr = new_ptr;
	this->size = new_size;
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

DynamicArray DynamicArray::operator+(int a)
{
	int new_size = this->size + a;
	int* new_ptr = new int[new_size];

	for (int i = 0; i < new_size; i++)
	{
		if (i<size)
		{
			new_ptr[i] = ptr[i];
		}
		else { new_ptr[i] = 0; }
	}
	delete[] this->ptr;
	this->ptr = new_ptr;
	this->size = new_size;
	return *this;
}

DynamicArray DynamicArray::operator-(int a)
{
	if (this->size > 2)
	{
		int new_size = this->size - a;
		int* new_ptr = new int[new_size];

		for (int i = 0; i < new_size; i++)
		{
			new_ptr[i] = ptr[i];
		}
		delete[] this->ptr;
		this->ptr = new_ptr;
		this->size = new_size;
		return *this;
	}
	else { cout << "Array too small " << endl;  return *this; }
}

DynamicArray DynamicArray::operator*(int a)
{
	DynamicArray new_ptr;
	new_ptr.size = this->size;
	new_ptr.ptr = new int[new_ptr.size];

	for (int i = 0; i < new_ptr.size; i++)
	{
		new_ptr.ptr[i] = ptr[i] * a;
	}
	
	return new_ptr;
}

DynamicArray DynamicArray::operator+(DynamicArray b)
{
	DynamicArray new_ptr;
	new_ptr.size = this->size + b.size;
	new_ptr.ptr = new int[new_ptr.size];

	for (int i = 0; i < this->size; i++)
	{
		new_ptr.ptr[i] = ptr[i];
	}
	for (int i = 0; i < b.size; i++)
	{
		new_ptr.ptr[this->size + i] = b.ptr[i];
	}
	return new_ptr;
}

DynamicArray DynamicArray::operator-(DynamicArray b)
{
	int min_size, max_size;
	int* arr;

	if (this->size > b.size)
	{
		min_size = b.size;
		max_size = this->size;
		arr = this->ptr;
	}
	else if (this->size < b.size)
	{
		min_size = this->size;
		max_size = b.size;
		arr = b.ptr;
	}
	else
	{
		cout << "0  They are the same size "; return *this;
	}

	DynamicArray new_ptr;
	new_ptr.size = max_size-min_size;
	new_ptr.ptr = new int[new_ptr.size];

	for (int i = 0; i < new_ptr.size; i++)
	{
		new_ptr.ptr[i] = arr[min_size+i];
	}
	return new_ptr;
}

DynamicArray DynamicArray::operator++()
{
	int new_size = this->size + 1;
	int* new_ptr = new int[new_size];

	for (int i = 0; i < new_size; i++)
	{
		if (i < size)
		{
			new_ptr[i] = ptr[i];
		}
		else { new_ptr[i] = 0; }
	}
	delete[] this->ptr;
	this->ptr = new_ptr;
	this->size = new_size;
	return *this;
}

DynamicArray DynamicArray::operator--()
{
	if (this->size > 1)
	{
		int new_size = this->size - 1;
		int* new_ptr = new int[new_size];

		for (int i = 0; i < new_size; i++)
		{
			new_ptr[i] = ptr[i];
		}
		delete[] this->ptr;
		this->ptr = new_ptr;
		this->size = new_size;
		return *this;
	}
	else { cout << "Array too small " << endl;  return *this; }
}

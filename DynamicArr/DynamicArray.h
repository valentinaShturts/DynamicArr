#pragma once
#include <iostream>
using namespace std;

class DynamicArray
{
	int* ptr; // ��������� �� �����. ������
	int size;  // ������ ������� 
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&); // copy constructor
	~DynamicArray();

	void Input();// rand
	void Output() const;// ����� �� �������
	int* GetPointer() const;
	int GetSize() const;

	// ����������� ��������� ������:
	void ReSize(int new_size);// ��������� ������� �������
	void Sort();// ����������(����� �������� ����������)
	int Search(int a); // ����� �������� � �������, ���������� ������ ���������� ��., ���� -1.
	void Reverse(); // �������������� ������������������ ��������� � �������� �������, ������� 12345 -> 54321



};


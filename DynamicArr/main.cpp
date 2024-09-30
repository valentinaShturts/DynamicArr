//#pragma once
#include <iostream>
#include "DynamicArray.h"



DynamicArray GetObj() //возврат по значению
{
	DynamicArray obj(3);
	obj.Input();

	return obj;
}
int main()
{
	DynamicArray a(5); // constructor 1 param
	a.Input();
	a.Output();
	a.Sort();
	a.Output();
	a.ReSize(3); // copy constructor
	a.Output();
	a.Reverse();
	a.Output();
	cout << "Search number 7 by index: " << a.Search(7) << endl << endl;

	//DynamicArray rezult = GetObj();
	DynamicArray rez = a + 10;
	rez.Output();

	system("pause");
}
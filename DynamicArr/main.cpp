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
	DynamicArray a(5); 
	a.Input();
	a.Output();

	DynamicArray rez = a + 10;
	rez.Output();
	DynamicArray rez1 = a - 2;
	rez1.Output();
	system("pause");
}
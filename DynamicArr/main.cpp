//#pragma once
#include <iostream>
#include "DynamicArray.h"



DynamicArray GetObj() 
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
	DynamicArray rez2 = a * 2;
	rez2.Output();
	DynamicArray rez4 = a + rez2;
	rez4.Output();
	DynamicArray rez3 = a - rez4;
	rez3.Output();
	DynamicArray rez5 = ++a;
	rez5.Output();
	DynamicArray rez6 = --a;
	rez6.Output();
	system("pause");
}
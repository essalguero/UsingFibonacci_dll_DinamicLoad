// UsingFibonacci_dll_DynamicLoad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <Windows.h>

using namespace std;

typedef double(__stdcall* f_fibonacci_DAC)(int);

int main()
{

	//LPCWSTR LIBRARY_PATH = (LPCWSTR)"Fibonacci_dll.dll";

	HINSTANCE hGetProcIDDLL = LoadLibrary(TEXT("c:\\Library\\Fibonacci_dll.dll"));

	if (!hGetProcIDDLL) {
		//cout << "Could not load library: " << LIBRARY_PATH << endl << endl; 
		cout << "Could not load library: c:\\Library\\Fibonacci_dll.dll" << endl << endl;

		return EXIT_FAILURE;
	}

	f_fibonacci_DAC funcionFibonacci = (f_fibonacci_DAC)GetProcAddress(hGetProcIDDLL, "fibonacci_DivideAndConquer");

	if (!funcionFibonacci) {
		cout << "Could not load the funcion fibonacci_DivideAndConquer" << endl << endl;

		FreeLibrary(hGetProcIDDLL);

		return EXIT_FAILURE;
	}

	cout << "Fibonacci(46)" << funcionFibonacci(46) << endl << endl;

    return 0;
}


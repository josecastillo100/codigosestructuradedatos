#include <iostream>

using namespace std;

int main()
{
	int *p;
	int i;
	int k;
	i = 42;
	k = i;
	p = &i;
	
	cout << "i: " <<i << endl;
	cout << "*p -> &i: " <<p << endl;
	
	//Cambiar valor de i
	
	*p = 75;
	
	cout << "i: " <<i << endl;
		
	return 0;
}



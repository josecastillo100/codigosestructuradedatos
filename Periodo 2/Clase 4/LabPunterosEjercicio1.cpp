#include <iostream>

using namespace std;

int main()
{
	char c = 'T', d = 'S';
	char *p1 = &c;
	char *p2 = &d;
	char *p3;
	
	cout << "*p2: " << (void*)p2 << endl;
	
	p3 = &d;
	cout << "*p3 = " << *p3 << endl; 	// (1) S
	p3 = p1;
	cout << "*p3 = " << *p3 			// (2) T
	<< ", p3 = " << (void*)p3 << endl; 	// (3) 6940
	*p1 = *p2;
	cout << "*p1 = " << *p1 			// (4) S
	<< ", p1 = " << (void*)p1 << endl; 	// (5) 6940
	
	cout << "*p2: " << (void*)p2 << endl;
		
	return 0;
}



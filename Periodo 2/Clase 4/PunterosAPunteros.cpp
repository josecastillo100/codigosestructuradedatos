#include <iostream>

using namespace std;

int main()
{
	int **ramon;
	int *paul;
	int melissa = 5;
	paul = &melissa;
	ramon = &paul;
	
	cout << "ramon = " << ramon << endl;
	cout << "&paul = " << &paul << endl;
	cout << "*ramon = " << *ramon << endl;
	cout << "&melissa = " << &melissa << endl;
	cout << "**ramon = " << **ramon << endl;
	
	return 0;
}

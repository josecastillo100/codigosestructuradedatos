#include <iostream>

using namespace std;

int main()
{
	char bloques[3] = {'A','B','C'};
	char *ptr = &bloques[0];
	char temp;
	
	temp = bloques[0];
	cout << "temp = bloques[0]: " << temp << endl;
	temp = *(bloques + 2);
	cout << "temp = *(bloques + 2): " << temp << endl;
	temp = *(ptr + 1);
	cout << "temp = *(ptr + 1): " << temp << endl;
	temp = *ptr;
	cout << "temp = *ptr: " << temp << endl;
	
	ptr = bloques + 1;
	cout << "ptr = bloques + 1: " << ptr << endl;
	temp = *ptr;
	cout << "temp = *ptr: " << temp << endl;
	temp = *(ptr + 1);
	cout << "temp = *(ptr + 1): " << temp << endl;
		
	ptr = bloques;
	cout << "ptr = bloques: " << (void*)ptr << endl;
	temp = *++ptr;
	cout << "temp = *++ptr: " << temp << endl;
	temp = ++*ptr;
	cout << "temp = ++*ptr: " << temp << endl;
	temp = *ptr++;
	cout << "temp = *ptr++: " << temp << endl;
	temp = *ptr;
	cout << "temp = *ptr: " << temp << endl;

	return 0;
}



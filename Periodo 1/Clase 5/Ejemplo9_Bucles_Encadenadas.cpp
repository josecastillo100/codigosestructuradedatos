#include <iostream>

using namespace std;

int main()
{
	for(int i = 0; i < 10; i++)
	{
		for(char c = 'a'; c <= 'z'; c++)
			cout << c;
		cout << endl;
	}
	
	return 0;
}

#include <iostream>

using namespace std;

int conejos(int n)
{
	if(n <= 2)
	{
		return (1);
	}
	else
	{
		return conejos(n-1) + conejos(n-2);
	}
}

int main()
{
	int num, valor;
	cout << "Ingrese el numero de conejos inicial: ";
	cin >> valor;
	num = conejos(valor);
	cout << "El numero de parejas de conejitos resultantes es: " << num << endl;
	
	return 0;
}

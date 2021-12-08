#include <iostream>

using namespace std;

int main()
{
	int contador = 1;				//Inicialización
	while(contador != 10)				//Condicion
	{
		cout << contador << "\n";
		contador+= 2;				//Actualización
	}
	return 0;
}

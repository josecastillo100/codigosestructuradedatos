#include <iostream>

using namespace std;

int main()
{
	int contador = 1;				//Inicializaci�n
	while(contador < 0)				//Condicion
	{
		cout << contador << "\n";
		contador --;				//Actualizaci�n
	}
	return 0;
}

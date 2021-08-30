#include <iostream>

using namespace std;

int main()
{
	int contador = 1;				//Inicialización
	while(contador < 0)				//Condicion
	{
		cout << contador << "\n";
		contador --;				//Actualización
	}
	return 0;
}

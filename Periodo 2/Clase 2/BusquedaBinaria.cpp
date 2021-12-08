#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 7> numeros = {1, 2, 3, 4, 5, 6, 7};
	int inferior = 0;							//Indice inferior
	int superior = (int)numeros.size() - 1;		//Indice superior
	int medio;									//Indice central
	int valorBuscando = 6;						//Valor a buscar
	int indice = -1;
	while(inferior <= superior)
	{
		medio = inferior + (superior - inferior) / 2;
		cout << "Inferior: " << inferior << " -> " << numeros[inferior];
		cout << " Medio: " << medio << " -> " << numeros[medio];
		cout << " Superior: " << superior << " -> " << numeros[superior] << endl;
		
		if(valorBuscando == numeros[medio])
		{
			indice = medio;
			break;
		}
		else if(valorBuscando > numeros[medio])
		{
			inferior = medio + 1;
		}
		else if(valorBuscando < numeros[medio])
		{
			superior = medio - 1;
		}
		else
		{
			cout << "Error";
		}
	}
	cout << "Indice del valor " << valorBuscando << " : " << indice << endl;
	return 0;
}

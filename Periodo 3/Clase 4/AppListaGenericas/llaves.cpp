#include <iostream>
#include <string>
#include "pila.h"

using namespace std;

bool estanLlavesBalanceadas(string expresion)
{
	Pila<char> unaPila;
	for(size_t i = 0; i < expresion.length(); i++)
	{
		char caracter = expresion[i];
		cout << caracter << endl; //esto se puede borrar despues
		if(caracter == '{')
		{
			unaPila.push(caracter);
			cout << unaPila.pilaComoCadena() << endl;
		}
		else if(caracter == '}')
		{
			if(unaPila.estaPilaVacia())
			{
				return false;
			}
			unaPila.pop();
			cout << unaPila.pilaComoCadena() << endl;
		}
	}
	return unaPila.estaPilaVacia();
}

//int main()
int mainLlave()
{
	string cadena;
	cout << "Ingrese una expresion: " << endl;
	cin >> cadena;
	if(estanLlavesBalanceadas(cadena))
	{
		cout << "Las llaves estan balanceadas.";
	}
	else
	{
		cout << "Las llaves no estan balanceadas.";
	}
	return 0;
}

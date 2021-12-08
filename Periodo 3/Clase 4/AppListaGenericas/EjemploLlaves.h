#include "Utilidades.h"
#include "pila.h"
#include <iostream>
//Created by Jose Alfredo Castillo on 31/10/2021

#include <windows.h>
#include <string>

#ifndef EJEMPLOLLAVES_H
#define EJEMPLOLLAVES_H

class EjemploLlaves
{
	private:
		bool estanLlavesBalanceadas(string expresion);
	public:
		EjemploLlaves();
		void ImplementarLlaves();
};

EjemploLlaves::EjemploLlaves()
{
	
}

bool EjemploLlaves::estanLlavesBalanceadas(string expresion)
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

void EjemploLlaves::ImplementarLlaves()
{
	//Instanciando clases
	Utilidades _Utilidad;
	
	string cadena;
	cout << "Ingrese una expresion: " << endl;
	cin >> cadena;
	if(estanLlavesBalanceadas(cadena))
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "Las llaves estan balanceadas.", true);
	}
	else
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "Las llaves no estan balanceadas.", true);
	}
}


#endif

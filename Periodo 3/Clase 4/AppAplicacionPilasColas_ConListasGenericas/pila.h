//Created by Jose Alfredo Castillo on 31/10/2021

#include "listagenerica.h"
#include <string>
#ifndef PILA_H
#define PILA_H


template <typename TIPODATO> 
class Pila : private Lista<TIPODATO>
{
	public:
		//Constructor
		Pila();
		//Agregar un elemento en la parte superior
		push(TIPODATO item);
		//Remover un elemento de la parte superior
		TIPODATO pop();
		TIPODATO top();
		bool estaPilaVacia();
		string pilaComoCadena();
};

template<typename TIPODATO>
Pila<TIPODATO>::Pila()
{
	Lista<TIPODATO> Lista;
}

template<typename TIPODATO>
Pila<TIPODATO>::push(TIPODATO item)
{
	this->adjuntar(item);
}

template<typename TIPODATO>
TIPODATO Pila<TIPODATO>::pop()
{
	return this->remover(this->tamano() - 1);
}

template<typename TIPODATO>
TIPODATO Pila<TIPODATO>::top()
{
	return this->obtener(this->tamano() - 1);
}

template<typename TIPODATO>
bool Pila<TIPODATO>::estaPilaVacia()
{
	return this->estaVacia();
}
template<typename TIPODATO>
string Pila<TIPODATO>::pilaComoCadena()
{	
	int cuenta = this->tamano();
	int i = 0;
	ostringstream s;
	s << "[";
	while(cuenta != 0)
	{
		i ++;
		s << this->obtener(cuenta - 1);
		if((cuenta - 1) != 0)
		{
			s << ", ";	
		}		
		cuenta--;
	}
		s << "]";
	return s.str();
}

#endif

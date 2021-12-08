#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <string>
#include <ctime>

class Personaje
{
	private:
		string nombres;
		int puntosVida;
	public:
		Personaje(string nombres, int puntosVida);
		void recibirGolpe(int puntosPerdidos);
		bool estaVivo();
		int getPuntosVida();
		string getNombre();
		void comer(int puntosGanados);
};

//Implementando el constructor
Personaje::Personaje(string nombres, int puntosVida)
{
	this->nombres = nombres;
	this->puntosVida = puntosVida;
}

void Personaje::recibirGolpe(int puntosPerdidos)
{
	this->puntosVida -= puntosPerdidos;
}

bool Personaje::estaVivo()
{
	bool _IsVivo = false;
	if(this->puntosVida > 0)
	{
		_IsVivo = true;
	}
	else
	{
		_IsVivo = false;
	}
	return _IsVivo;
}

int Personaje::getPuntosVida()
{
	return this->puntosVida;
}

string Personaje::getNombre()
{
	return this->nombres;
}

void Personaje::comer(int puntosGanados)
{
	this->puntosVida += puntosGanados;
}

#endif

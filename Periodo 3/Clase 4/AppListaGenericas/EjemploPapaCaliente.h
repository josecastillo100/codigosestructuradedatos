//Created by Jose Alfredo Castillo on 31/10/2021

#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Utilidades.h"
#include "cola.h"

#ifndef EJEMPLOPAPACALIENTE_H
#define EJEMPLOPAPACALIENTE_H

class EjemploPapaCaliente
{
	public:
		EjemploPapaCaliente();
		void ImplementarPapaCaliente();
		
	private:
		int numeroAleatorio(int max);
		void papaCaliente(const vector<string> &listaNombres);
};

EjemploPapaCaliente::EjemploPapaCaliente()
{
	
}

void EjemploPapaCaliente::ImplementarPapaCaliente()
{
 	vector<string> jugadores = {"1.Erick", "2.Emmanuel", "3.Briam", "4.Gabrial", "5.Maria", "6.Oscar", "7.Krista",
								"8.Eduardo", "9.Alejandra", "10.Carlos", "11.Diego", "12.Manuel", "13.Jose",
								"14.Mateo", "15.Fernando", "16.Martinez", "17.Ernesto", "18.Gustavo", "19.Graham"};
								
	papaCaliente(jugadores);
}
int EjemploPapaCaliente::numeroAleatorio(int max)
{
	static bool semillaCreada = false;
	if(!semillaCreada)
	{
		srand(time(0));
		semillaCreada = true;
	}
	return rand() % max;
}

void EjemploPapaCaliente::papaCaliente(const vector<string> &listaNombres)
{
	//Instanciando clases
	Utilidades _Utilidad;
	
	int cantidadJugadores = listaNombres.size();
	Cola<string> simulacion;
	for(int i = 0; i < cantidadJugadores; i++)
	{
		simulacion.enqueue(listaNombres[i]);
	}
	
	for(int i = cantidadJugadores; i > 1; i--)
	{
		cout << "Quien tiene la papa caliente?" << endl;
		for(int pases = numeroAleatorio(2*cantidadJugadores); pases > 0; pases--)
		{
			string jugador = simulacion.dequeue();
			cout << jugador << endl;
			simulacion.enqueue(jugador);
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
		string funado = simulacion.dequeue();
		cout << funado << endl;
		//cout << "Alto!!! " << funado << " sale del juego..." << endl << endl;
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "Alto!!! " + funado + " sale del juego...", true);
	}
	string ganador = simulacion.dequeue();
	//cout << ganador << " gano el juego." << endl;
	_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, ganador + " gano el juego.", true);
}

#endif

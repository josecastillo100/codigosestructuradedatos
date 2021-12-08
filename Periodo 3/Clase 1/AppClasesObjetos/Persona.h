#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
#include <ctime>

class Persona
{
	private:
		string nombres;
		string apellidos;
		int anioNacimiento;
	public:
		Persona(string nombres, string apellidos, int anioNacimiento);
		string nombreCompleto();
		int edad();
};

Persona::Persona(string nombres, string apellidos, int anioNacimiento)
{
	this->nombres = nombres;
	this->apellidos = apellidos;
	this->anioNacimiento = anioNacimiento;
}

string Persona::nombreCompleto()
{
	string nombreCompleto = this->nombres + " " + this->apellidos;
	return nombreCompleto;
}
Persona::edad()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	
	int anioActual = 1900 + ltm->tm_year;
	
	int edad = (anioActual - this->anioNacimiento);
	return edad;
}
#endif

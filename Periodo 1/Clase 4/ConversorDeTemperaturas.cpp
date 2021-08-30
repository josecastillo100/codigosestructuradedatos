#include <iostream> //Modulo o librerias propias de C++ se colocan entre <>

using namespace std;

double LeerTemperatura()
{
	double _Temperatura;
	cout << "Ingrese un valor de temperatura: ";
	while (!(cin >> _Temperatura))
	{
		cout << "No es un valor de temperatura valido. Intente de nuevo." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
}

int LeerSeleccionUsuario()
{
	int _Eleccion;
	cout << "Seleccione el tipo de conversión" << endl;
	cout << "1 - De Celsius a Fahrenheit" << endl;
	cout << "2 - De Celsius a Kelvin" << endl;
	cout << "3 - De Fahrenheit a Celsius" << endl;
	cout << "4 - De Fahrenheit a kelvin" << endl;
	cout << "5 - De Kelvin a Celsius" << endl;
	cout << "4 - De Kelvin a Fahrenheit" << endl;
	
	while(!(cin >> _Eleccion) || _Eleccion < 1 || _Eleccion > 6)
	{
		cout << "Opcion no valida. Ingrese un valor entre 1 y 6 " << endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
}

void ConvertirTemperatura(double pTempertaru, int pTipo)
{
	double _TemperaturaConvertida,
	
	switch(pTipo)
	{
		case 1: //De Celsius a Fahrenheit
			_TemperaturaConvertida = 1.8 * pTempertaru + 32;
			cout << "La temperatura " << pTempertaru << " C equivale a " << _TemperaturaConvertida <<  " F." + << endl;
			break;
		case 2: //De Celsius a Kelvin
			_TemperaturaConvertida =  pTempertaru + 273.15;
			cout << "La temperatura " << pTempertaru << " C equivale a " << _TemperaturaConvertida <<  " F." + << endl;
			break;
		case 3: //De Fahrenheit a Celsius
			_TemperaturaConvertida = 1.8 * pTempertaru + 32;
			cout << "La temperatura " << pTempertaru << " C equivale a " << _TemperaturaConvertida <<  " F." + << endl;
			break;
		case 4: //De Celsius a Fahrenheit
			_TemperaturaConvertida = 1.8 * pTempertaru + 32;
			cout << "La temperatura " << pTempertaru << " C equivale a " << _TemperaturaConvertida <<  " F." + << endl;
			break;
		case 5: //De Celsius a Fahrenheit
			_TemperaturaConvertida = 1.8 * pTempertaru + 32;
			cout << "La temperatura " << pTempertaru << " C equivale a " << _TemperaturaConvertida <<  " F." + << endl;
			break;
		case 6: //De Celsius a Fahrenheit
			_TemperaturaConvertida = 1.8 * pTempertaru + 32;
			cout << "La temperatura " << pTempertaru << " C equivale a " << _TemperaturaConvertida <<  " F." + << endl;
			break;
	}
}

int main()
{
	cout << "------------------------------- Convertir temperaturas ------------ <<" endl;
	
	double _Temperatura, _temperaturaConvertidad;
	int _Eleccion,
	
	_Temperatura = LeerTemperatura();
	_Eleccion = LeerSeleccionUsuario();
	ConvertirTemperatura(_Temperatura, _Eleccion);
	
	return 0;
}

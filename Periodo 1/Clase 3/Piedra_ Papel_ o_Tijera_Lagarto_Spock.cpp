#include <iostream> //Encabezado que define los objetos de flujo de entrada / salida estándar

#include <windows.h> //Archivo cabecera específico de Windows para la programación en lenguaje C/C++ que 
					 //contiene las declaraciones de todas las funciones de la biblioteca Windows API.
					 
#include <string>	//Las cadenas son objetos que representan secuencias de caracteres.

#include <cstdlib>	//Este encabezado define varias funciones de propósito general, incluida la gestión dinámica de la memoria, la generación de números aleatorios,
					//la comunicación con el entorno, la aritmética de enteros, la búsqueda, la clasificación y la conversión.
					
#include <ctime>	//Este archivo de encabezado contiene definiciones de funciones para obtener y manipular información de fecha y hora.

using namespace std;

//Llamanos la funcion MiMenu

int MiMenu();

int main()
{
	SetConsoleTitleA("Piedra, Papel o Tijera + Lagarto - Spock - Tarea UFG"); //Cambiar el titulo de la consola

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //Acceder a la consola de colores
	
	//Creador del juego
	SetConsoleTextAttribute(h, 11); //Método para cambiar el color del texto de la consulta - 11 = aqua
	cout << " ESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO " << endl;
	cout << " CARNE: CA102817" << endl;
	cout << "\n";
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	
	int _OpcionMenu;
	int _MovimientoJugador;
	int _MovimientoSistema;
	string _MovimientoSistemaTexto;
	string _ResultadoJuego;
	bool _IsGanoElJuego = false; //Bandera para identificar si gano o perdio el usuario
		
	_OpcionMenu = MiMenu();
	
	while(_OpcionMenu != 3)
	{
		if(_OpcionMenu == 1)
		{
			cout << " Juguemos a Piedra, Papel o Tijera + Lagarto - Spock \n\n";
			cout << " 1-Piedra \n 2-Papel \n 3-Tijera \n 4-Largarto \n 5-Spock \n\n";
			
			cout << " Seleccione su movimiento: ";
			cin >> _MovimientoJugador;
			
			srand(time(0));
			_MovimientoSistema = rand() % 5 + 1;
		
			switch(_MovimientoSistema)
			{
				case 1:
					_MovimientoSistemaTexto = "Piedra";
					break;
				case 2:
					_MovimientoSistemaTexto = "Papel";
					break;
				case 3:
					_MovimientoSistemaTexto = "Tijera";
					break;
				case 4:
					_MovimientoSistemaTexto = "Lagarto";
					break;
				case 5:
					_MovimientoSistemaTexto = "Spock";
					break;
					
			}
			
			SetConsoleTextAttribute(h,13); //Método para cambiar el color del texto de la consulta - 13 = purple
			cout << " La computadora escogio: " << _MovimientoSistemaTexto << endl;
			SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
			
			if(_MovimientoJugador == _MovimientoSistema)
			{
				_ResultadoJuego = " Empate";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 1) && (_MovimientoSistema == 3))
			{
				//La piedra aplasta las tijeras
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 2) && (_MovimientoSistema == 1))
			{
				//El papel envuelve a la piedra
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 3) && (_MovimientoSistema == 2))
			{
				//Las tijeras cortan el papel
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 1) && (_MovimientoSistema == 4))
			{
				//La piedra aplasta al lagarto
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 4) && (_MovimientoSistema == 5))
			{
				//El lagarto envenena a Spock
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 5) && (_MovimientoSistema == 3))
			{
				//Spock aplasta las tijeras
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 3) && (_MovimientoSistema == 4))
			{
				//Las tijeras decapitan al lagarto
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 4) && (_MovimientoSistema == 2))
			{
				//El lagarto devora el papel
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 2) && (_MovimientoSistema == 5))
			{
				//El papel desaprueba a Spock
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else if ((_MovimientoJugador == 5) && (_MovimientoSistema == 1))
			{
				//Spock desintegra la piedra
				_ResultadoJuego = " Ganaste";
				_IsGanoElJuego = true;
			}
			else
			{
				_ResultadoJuego = " Lamentablemente, perdiste";
				_IsGanoElJuego = false;
			}
			
			cout << " \nResultado: ";
			if(_IsGanoElJuego)
			{
				SetConsoleTextAttribute(h,9); //Color blue si GANA el usuario
				cout << _ResultadoJuego;
			}
			else		
			{
				SetConsoleTextAttribute(h,12);  //Color Rojo cuando PIERDE el usuario
				cout << _ResultadoJuego;
			}
			
				
			SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
			cout << "\n-------------------------------------------------------------------\n" << endl;
		}
		else if (_OpcionMenu == 2)
		{
			cout << "\n A continuacion, se le muestran las condiciones para ganar en el juego:" << endl;
			cout << " --> Las tijeras cortan el papel." << endl;
			cout << " --> El papel envuelve la piedra." << endl;
			cout << " --> La piedra aplasta al lagarto." << endl;
			cout << " --> El lagarto envenena a Spock." << endl;
			cout << " --> Spock aplasta las tijeras." << endl;
			cout << " --> Las tijeras decapitan al lagarto." << endl;
			cout << " --> El lagarto devora el papel." << endl;
			cout << " --> El papel desaprueba a Spock." << endl;
			cout << " --> Spock desintegra la piedra." << endl;
			cout << " --> La piedra aplasta las tijeras.\n" << endl;
		}
		_OpcionMenu = MiMenu();
	}
	return 0;	
}


/***********************************FUNCIONES DEL JUEGO************************************************************/

//Se crea un menú para el juego, el jugar tiene la opción de jugar varias veces.
int MiMenu(){
	int _Opcion = 0;
	
	cout << " *******************************************" << endl;
	cout << "		MENU JUEGO                           " << endl;
	cout << " *******************************************" << endl;
	
	cout << " [1] - Jugar una partida." << endl << " [2] - Formas de Ganar." << endl << " [3] - Salir del juego \n" << endl << " Opcion: ";
	cin >> _Opcion;
	
	cout << "\n";
	
	while (_Opcion < 1 || _Opcion > 3)
	{
		if(_Opcion < 0 || _Opcion > 3)
		{
			cout << endl << " Opcion invalida " <<endl << endl;
		}
		
		cout << " [1] - Jugar una partida." << endl << " [2] - Formas de Ganar." << endl << " [3] - Salir del juego \n" << endl << "Opcion: ";
		cin >> _Opcion;
	}
	
	return _Opcion;
}



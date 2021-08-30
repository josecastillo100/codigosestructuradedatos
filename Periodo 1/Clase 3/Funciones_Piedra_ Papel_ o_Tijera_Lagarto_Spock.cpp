#include <iostream> //Encabezado que define los objetos de flujo de entrada / salida estándar

#include <windows.h> //Archivo cabecera específico de Windows para la programación en lenguaje C/C++ que 
					 //contiene las declaraciones de todas las funciones de la biblioteca Windows API.
					 
#include <string>	//Las cadenas son objetos que representan secuencias de caracteres.

#include <cstdlib>	//Este encabezado define varias funciones de propósito general, incluida la gestión dinámica de la memoria, la generación de números aleatorios,
					//la comunicación con el entorno, la aritmética de enteros, la búsqueda, la clasificación y la conversión.
					
#include <ctime>	//Este archivo de encabezado contiene definiciones de funciones para obtener y manipular información de fecha y hora.

#include <stdio.h>

#include <map>

using namespace std;

//Inicio: Constantes
const int Constante_Piedra = 1;
const int Constante_Papel = 2;
const int Constante_Tijera = 3;
const int Constante_Lagarto = 4;
const int Constante_Spock = 5;

//Fin: Constantes

//Inicio: Prototipos
int MiMenu(); //Funcion
int CrearOpcionesMenu(); //Funcion
int ObtenerMovimientoJugador(); //Funcion
int GenerarMovimientoSistema(); //Funcion
std::string IdentificarMovimientoSistema(int pOpcionSistema); //Funcion
std::map<std::string, std::string> CondicionesDelJuego(); //Funcion

void DeterminarGanador(int pOpcionJugador, int pOpcionSistema); //Procedimiento
void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour); //Procedimiento
void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea); //Procedimiento
void ResetConsoleColour(WORD Attributes); //Procedimiento
void MostrarResultadoFinal(bool pIsUsuarioGanoElJuego, string pRespuestaJuego); //Procedimiento
//Fin: Prototipos
	
int main()
{
	SetConsoleTitleA("Funciones: Piedra, Papel o Tijera + Lagarto - Spock - Tarea UFG"); //Cambiar el titulo de la consola
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "ESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "CARNE: CA102817", true); // Color CYAN
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //Acceder a la consola de colores
	cout << "\n";
	
	int _OpcionMenu;
	int _MovimientoJugador;
	int _MovimientoSistema;
	string _MovimientoSistemaTexto;
	string _MensajeSalida;
		
	_OpcionMenu = MiMenu();
	
	while(_OpcionMenu != 3)
	{
		if(_OpcionMenu == 1)
		{
			_MovimientoJugador = ObtenerMovimientoJugador();
			_MovimientoSistema = GenerarMovimientoSistema();			
			_MovimientoSistemaTexto = IdentificarMovimientoSistema(_MovimientoSistema);
						
			_MensajeSalida = "La computadora escogio: " + std::to_string(_MovimientoSistema) + "-" + _MovimientoSistemaTexto; 
			//Background morado lila + letra blanca
			//AplicarColorDinamico_ConTexto(BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE, _MensajeSalida, true);
			
			//Background azul + letra negra
			AplicarColorDinamico_ConTexto(BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE, _MensajeSalida, true);
			
			DeterminarGanador(_MovimientoJugador, _MovimientoSistema);
		}
		else if (_OpcionMenu == 2)
		{
			//create a map that stores strings indexed by strings
    		std::map<std::string, std::string> m_Dictionary;  		
    		m_Dictionary = CondicionesDelJuego();
    		
    		cout << " A continuacion, se le muestran las condiciones para ganar en el juego:" << endl;
    		
			//now loop through all of the key-value pairs
		    //in the map and print them out
		    for (auto item: m_Dictionary)
		    {
		        //item.first is the key
		        //item.second is the value
				cout << " --> " << item.second << endl;
		    }
		}
		cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n" << endl;
		
		_OpcionMenu = MiMenu();
	}
	return 0;	
}

//Implementacion

int MiMenu(){
	
	int _Opcion = 0;
	
	cout << " *******************************************" << endl;
	cout << "		MENU JUEGO                           " << endl;
	cout << " *******************************************" << endl;
	
	_Opcion = CrearOpcionesMenu();
	
	while (_Opcion < 1 || _Opcion > 3)
	{
		if(_Opcion < 0 || _Opcion > 3)
		{
			cout << endl << " Opcion invalida " <<endl << endl;
		}
		
		_Opcion = CrearOpcionesMenu();
	}
	
	return _Opcion;
}

int CrearOpcionesMenu()
{
	int _Opcion = 0;
	cout << " [1] - Jugar una partida." << endl << " [2] - Formas de Ganar." << endl << " [3] - Salir del juego \n" << endl << " Opcion: ";	
	cin >> _Opcion;	
	cout << "\n";
	
	return _Opcion;
}
int ObtenerMovimientoJugador()
{
	int _MovimientoJugador;
	cout << " Juguemos a Piedra, Papel o Tijera + Lagarto - Spock \n\n";
	cout << " 1-Piedra \n 2-Papel \n 3-Tijera \n 4-Largarto \n 5-Spock \n\n";
			
	cout << " Seleccione su movimiento: ";
	cin >> _MovimientoJugador;
		
	return _MovimientoJugador;
}
int GenerarMovimientoSistema()
{
	int _MovimientoSistema;
	srand(time(0));
	_MovimientoSistema = rand() % 5 + 1;
	
	return _MovimientoSistema;
}

std::string IdentificarMovimientoSistema(int pOpcionSistema)
{
	string _MovimientoSistemaTexto;
	
	switch(pOpcionSistema)
	{
		case Constante_Piedra:
			_MovimientoSistemaTexto = "Piedra";
			break;
		case Constante_Papel:
			_MovimientoSistemaTexto = "Papel";
			break;
	    case Constante_Tijera:
			_MovimientoSistemaTexto = "Tijera";
			break;
		case Constante_Lagarto:
			_MovimientoSistemaTexto = "Lagarto";
			break;
		case Constante_Spock:
			_MovimientoSistemaTexto = "Spock";
			break;
		default:
			_MovimientoSistemaTexto = "Opcion no valida";
					
	}
	return _MovimientoSistemaTexto;
}

void DeterminarGanador(int pOpcionJugador, int pOpcionSistema)
{
	std::map<std::string, std::string> m_Dictionary;  		
    m_Dictionary = CondicionesDelJuego();
	
	string _ResultadoJuego;
	bool _IsUsuarioGanoElJuego = false; //Bandera para identificar si gano o perdio el usuario
	if(pOpcionJugador == pOpcionSistema)
	{
		_ResultadoJuego = "Empate";
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Piedra) && (pOpcionSistema == Constante_Tijera))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["PiedraAplastaTijeras"]);
		_IsUsuarioGanoElJuego = true;		
	}
	else if ((pOpcionJugador == Constante_Papel) && (pOpcionSistema == Constante_Piedra))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["PapelEnvuelvePiedra"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Tijera) && (pOpcionSistema == Constante_Papel))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["TijeraCortaPapel"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Piedra) && (pOpcionSistema == Constante_Lagarto))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["PiedraAplastaLagarto"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Lagarto) && (pOpcionSistema == Constante_Spock))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["LagartoEnvenenaSpock"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Spock) && (pOpcionSistema == Constante_Tijera))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["SpockAplastaTijeras"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Tijera) && (pOpcionSistema == Constante_Lagarto))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["TijerasDecapitanLagarto"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Lagarto) && (pOpcionSistema == Constante_Papel))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["LagartoDevoraPapel"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Papel) && (pOpcionSistema == Constante_Spock))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["PapelDesapruebaSpock"]);
		_IsUsuarioGanoElJuego = true;
	}
	else if ((pOpcionJugador == Constante_Spock) && (pOpcionSistema == Constante_Piedra))
	{
		_ResultadoJuego = (string() + "Usted Gana" + " - " + m_Dictionary["SpockDesintegraPiedra"]);
		_IsUsuarioGanoElJuego = true;
	}
	//Sistema
	else if ((pOpcionJugador == Constante_Tijera) && (pOpcionSistema == Constante_Piedra))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["PiedraAplastaTijeras"]);
		_IsUsuarioGanoElJuego = false;		
	}
	else if ((pOpcionJugador == Constante_Piedra) && (pOpcionSistema == Constante_Papel))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["PapelEnvuelvePiedra"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Papel) && (pOpcionSistema == Constante_Tijera))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["TijeraCortaPapel"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Lagarto) && (pOpcionSistema == Constante_Piedra))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["PiedraAplastaLagarto"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Spock) && (pOpcionSistema == Constante_Lagarto))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["LagartoEnvenenaSpock"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Tijera) && (pOpcionSistema == Constante_Spock))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["SpockAplastaTijeras"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Lagarto) && (pOpcionSistema == Constante_Tijera))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["TijerasDecapitanLagarto"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Papel) && (pOpcionSistema == Constante_Lagarto))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["LagartoDevoraPapel"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Spock) && (pOpcionSistema == Constante_Papel))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["PapelDesapruebaSpock"]);
		_IsUsuarioGanoElJuego = false;
	}
	else if ((pOpcionJugador == Constante_Piedra) && (pOpcionSistema == Constante_Spock))
	{
		_ResultadoJuego = (string() + "El Sistema Gana" + " - " + m_Dictionary["SpockDesintegraPiedra"]);
		_IsUsuarioGanoElJuego = false;
	}
	else
	{
		_ResultadoJuego = "Lamentablemente, perdiste";
		_IsUsuarioGanoElJuego = false;
	}
	
	MostrarResultadoFinal(_IsUsuarioGanoElJuego, _ResultadoJuego);
}

void MostrarResultadoFinal(bool pIsUsuarioGanoElJuego, string pRespuestaJuego)
{
	cout << " \nResultado del Juego: ";
	if(pIsUsuarioGanoElJuego)
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, pRespuestaJuego, true);
	}
	else		
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, pRespuestaJuego, true);
	}
}
std::map<std::string, std::string> CondicionesDelJuego()
{
	//create a map that stores strings indexed by strings
    std::map<std::string, std::string> _m_Dictionary;
    
    //add some items to the map
    _m_Dictionary["TijeraCortaPapel"] = "Las tijeras cortan el papel.";
    _m_Dictionary["PapelEnvuelvePiedra"] = "El papel envuelve la piedra.";
    _m_Dictionary["PiedraAplastaLagarto"] = "La piedra aplasta al lagarto.";
    _m_Dictionary["LagartoEnvenenaSpock"] = "El lagarto envenena a Spock.";
	_m_Dictionary["SpockAplastaTijeras"] = "Spock aplasta las tijeras."; 
	_m_Dictionary["TijerasDecapitanLagarto"] = "Las tijeras decapitan al lagarto.";
	_m_Dictionary["LagartoDevoraPapel"] = "El lagarto devora el papel.";
	_m_Dictionary["PapelDesapruebaSpock"] = "El papel desaprueba a Spock.";
	_m_Dictionary["SpockDesintegraPiedra"] = "Spock desintegra la piedra.";
	_m_Dictionary["PiedraAplastaTijeras"] = "La piedra aplasta las tijeras."; 
    
    return _m_Dictionary;
}

void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea)
{
	WORD Attributes = 0;
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
    
    if(pIsSaltoLinea)
    {
    	cout << " " << pTexto << endl;
	}
	else
	{
		cout << pTexto;
	}
    
    
    ResetConsoleColour(Attributes);
}

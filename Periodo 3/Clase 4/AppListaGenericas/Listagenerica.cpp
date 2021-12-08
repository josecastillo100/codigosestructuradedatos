//Created by Jose Alfredo Castillo on 30/10/2021

#include "listagenerica.h"
#include <iostream>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;

void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour); //Procedimiento
void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea); //Procedimiento
void ResetConsoleColour(WORD Attributes); //Procedimiento

//int main()
int mainListaGenerica()
{
	SetConsoleTitleA("Tarea pilas y colas con herencia a partir de lista generica - Tarea UFG"); //Cambiar el titulo de la consola
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
	cout << endl;
	
	/**/
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "TIPO DE DATOS A: Int", false); cout << endl << endl;
	Lista<int> miLista;
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	
	Lista<int> miLista2 = miLista;
	cout << endl;
	
	cout << (miLista.estaVacia() ? "true": "false") << endl << endl;
	
	miLista.adjuntar(41);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	
	miLista.adjuntar(52);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	
	miLista.adjuntar(63);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	
	miLista.insertar(2, 74);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	
	miLista.insertar(0, 30);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	
	cout << "Tamano de la lista: " << miLista.tamano() << endl << endl;
	
	cout << miLista.obtener(4) << endl << endl;
	
	cout << miLista.remover(2) << endl << endl;
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	
	miLista.adjuntar(85);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miLista.comoCadena(), false); cout << endl << endl;
	/**/
	
	cout << endl << endl;
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "CAMBIANDO DE TIPO DE DATOS A: Double", false); cout << endl << endl;
 	
	Lista<double> miListaDouble;
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	Lista<double> miListaDouble2 = miListaDouble;
	cout << endl;
	
	cout << (miListaDouble.estaVacia() ? "true": "false") << endl << endl;
	
	miListaDouble.adjuntar(100.1);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	miListaDouble.adjuntar(105.3);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	miListaDouble.adjuntar(94.5);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	miListaDouble.insertar(1, 107.7);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	miListaDouble.insertar(2, 365.50);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	cout << "Tamano de la lista: " << miListaDouble.tamano() << endl << endl;
	
	cout << miListaDouble.obtener(4) << endl << endl;
	
	cout << miListaDouble.remover(2) << endl << endl;
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	miListaDouble.adjuntar(104.5);
	cout << "La lista es: "; AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, miListaDouble.comoCadena(), false); cout << endl << endl;
	
	return 0;
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
    	cout << pTexto << endl;
	}
	else
	{
		cout << pTexto;
	}
    
    ResetConsoleColour(Attributes);
}

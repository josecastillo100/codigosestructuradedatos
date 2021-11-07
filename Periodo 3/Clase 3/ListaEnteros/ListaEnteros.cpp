#include "lista.h"
#include <iostream>
#include <windows.h>

using namespace std;

void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour); //Procedimiento
void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea); //Procedimiento
void ResetConsoleColour(WORD Attributes); //Procedimiento

int main() {
	
	SetConsoleTitleA("Ejercicios de Listas - Tarea UFG"); //Cambiar el titulo de la consola
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
	cout << endl;
	
	ListaEnteros lint1(10);
	
	lint1.adjuntar(12);
	lint1.adjuntar(7);
	lint1.adjuntar(19);
	cout << "\tAdjuntar(12, 7, 19)   :"; lint1.imprimirLista();
	
	lint1.adjuntar(30);
	cout << "\tAdjuntar(30)          :"; lint1.imprimirLista();
	
	lint1.insertar(1, 41);
	cout << "\tInsertar(1, 41)       :"; lint1.imprimirLista();
	
	lint1.remover(2);
	cout << "\tRemover(2)            :"; lint1.imprimirLista();
	
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

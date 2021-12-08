//Created by Jose Alfredo Castillo on 23/1/2021

#include <windows.h>

#ifndef UTILIDADES_H
#define UTILIDADES_H

using namespace std;

class Utilidades
{
	public:
		Utilidades();
		void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour);
		void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea);
		void ResetConsoleColour(WORD Attributes);
	protected:
		//No
};

Utilidades::Utilidades()
{
	
}

void Utilidades::AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour)
{
 	CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void Utilidades::AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea)
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
void Utilidades::ResetConsoleColour(WORD Attributes)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}

#endif

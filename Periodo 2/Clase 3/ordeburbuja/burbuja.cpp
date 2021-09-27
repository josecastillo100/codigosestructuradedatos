#include <iostream>
#include <array>
#include <ctime>
#include <windows.h>

using namespace std;

const int TAMANIO = 2000; //Numero de elementos en el arreglo

//Inicio: prototipos
void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour); //Procedimiento
void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea); //Procedimiento
void ResetConsoleColour(WORD Attributes); //Procedimiento
//Fin: prototipos

//Imprime hasta num_elementos de un arreglo
void imprimirArreglo(array<int, TAMANIO> &arr, int num_elementos)
{
	for(int i = 0; i < arr.size() && i < num_elementos; i++)
	{
		cout << arr[i] << endl;
	}
}

void ordenamientoBurbuja(array<int, TAMANIO> &arr)
{
	int tamanio = arr.size();
	bool desordenado = true;
	for(int pase = 0; pase < tamanio - 1 && desordenado; pase++)
	{
		desordenado = false;
		for(int j = 0; j < tamanio - 1 - pase; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				desordenado = true;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main()
{
	SetConsoleTitleA("Ordenamiento de burbuja - Tarea UFG"); //Cambiar el titulo de la consola
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
	cout  << endl;
	
	array<int, TAMANIO> miArreglo;
	
	//leer elementos del arreglo
	for(int i = 0; i < TAMANIO; i++)
	{
		cin >> miArreglo[i];
	}
	
	clock_t inicio = clock();
	ordenamientoBurbuja(miArreglo);
	clock_t fin = clock();
	
	double tiempoSegundos = double(fin - inicio) / CLOCKS_PER_SEC; // Tiempo transcurrido
	
	cout << "Cantidad de elemenos: " << miArreglo.size() << endl;
	cout << "Tiempo transcurrido :" << tiempoSegundos << " segundos" << endl;
	
	return 0;
}

//Implementaciones
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



//Created by Jose Alfredo Castillo on 31/10/2021

#include <iostream>
#include <windows.h>
#include <string>

#include "Utilidades.h"
#include "Ejemplolistagenerica.h"
#include "EjemploLlaves.h"
#include "EjemploPapaCaliente.h"

using namespace std;

int main() 
{
	SetConsoleTitleA("Tarea pilas y colas con herencia a partir de lista generica - Tarea UFG"); //Cambiar el titulo de la consola
	
	//Instanciando clases
	Utilidades _Utilidad;
	Ejemplolistagenerica _Ejemplolistagenerica;
	EjemploLlaves _EjemploLlaves;
	EjemploPapaCaliente _EjemploPapaCaliente;
	
	int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
		
        cout << "\n\t\t\t Menu del sistema" << endl;
        cout << "\t\t\t-------------------" << endl;
        cout << "\n\t1. Ejemplo de Lista genercia" << endl;
        cout << "\t2. Ejemplo de Pilas (Llaves)" << endl;
        cout << "\t3. Ejemplo de Colas (Papa Caliente)" << endl;
        cout << "\t4. Informacion del autor...." << endl;
        cout << "\t0. SALIR" << endl;
        
        cout << "\n\tDigite una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1:
				_Ejemplolistagenerica.ImplementarListaGenerica();       	
                cout << endl;
				_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN          
                system("pause>nul");
                
                break;
                
            case 2:
                _EjemploLlaves.ImplementarLlaves();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
                
            case 3:
               _EjemploPapaCaliente.ImplementarPapaCaliente();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
                
            case 4:            	
            	_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->ESTUDIANTE (AUTOR): Castillo Artiaga, Jose Alfredo", true); // Color CYAN
				_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->CARNE: CA102817", true); // Color CYAN 
				cout << endl;
				_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->ESTUDIANTE DE LA MATERIA: Estructura de datos - Grupo V01", true); // Color CYAN
				cout << endl;
				_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->CARRERA: Ingenieria en Ciencias de la Computacion", true); // Color CYAN 
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
				
				system("pause>nul");   
				  
                break;         
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
	
	return 0;
}


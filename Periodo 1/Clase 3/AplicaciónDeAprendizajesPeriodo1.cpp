#include <iostream>
#include <cstdlib>
#include <string>	//Las cadenas son objetos que representan secuencias de caracteres.
#include <windows.h>
#include <stdio.h>
#include <math.h>

using namespace std;

//Inicio: Prototipos
float CalcularAreaTriangulo(float pLado1, float pLado2, float pLado3); //Funcion
int Mayor(float pNumero1, float pNumero2, float pNumero3, float pNumero4, float pNumero5); //Funcion
void IdentificarTriangulo(); //Procedimiento
void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour); //Procedimiento
void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea); //Procedimiento
void ResetConsoleColour(WORD Attributes); //Procedimiento
void BuscarNumeroMayor(); //Procedimiento
void CalcularPromedioN_Numeros(); //Procedimientos
//Fin: Prototipos

int main()
{
	SetConsoleTitleA("Aplicacion de aprendizajes periodo 1 - Tarea UFG"); //Cambiar el titulo de la consola
	
    int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
		
        cout << "\n\t\t\t Menu del sistema" << endl;
        cout << "\t\t\t-------------------" << endl;
        cout << "\n\t1. Identificar triangulo" << endl;
        cout << "\t2. Buscar el numero mayor" << endl;
        cout << "\t3. Calcular promedio" << endl;
        cout << "\t4. Informacion del autor...." << endl;
        cout << "\t0. SALIR" << endl;
        
        cout << "\n\tDigite una opcion: ";
        cin >> opcion;
        
        int numero1, numero2;
		float resultado;
        switch (opcion) {
            case 1:           	
                IdentificarTriangulo();
                cout << endl;
				AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN          
                system("pause>nul");
                
                break;
                
            case 2:
                BuscarNumeroMayor();
                cout << endl;
                AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
                
            case 3:
                CalcularPromedioN_Numeros();
                cout << endl;
                AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
                
            case 4:            	
            	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->ESTUDIANTE (AUTOR): Castillo Artiaga, Jose Alfredo", true); // Color CYAN
				AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->CARNE: CA102817", true); // Color CYAN 
				cout << endl;
				AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->ESTUDIANTE DE LA MATERIA: Estructura de datos - Grupo V01", true); // Color CYAN
				cout << endl;
				AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_BLUE, "\t-->CARRERA: Ingenieria en Ciencias de la Computacion", true); // Color CYAN 
                 cout << endl;
                AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
				
				system("pause>nul");   
				  
                break;         
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
	 
    return 0;
}

//Implementacion

void IdentificarTriangulo()
{
	float _Lado1, _Lado2, _Lado3, _Area;
	string _MensajeResultado = "";
	
	//lectura de datos
    cout << "\n\tDigite el lado 1 (A): ";
    cin >> _Lado1;
                
    cout << "\tDigite el lado 2 (B): ";
    cin >> _Lado2;
    
    cout << "\tDigite el lado 3 (C): ";
    cin >> _Lado3;
	
	//Comprobamos como es el triangulo
	
	if(_Lado1 == _Lado2 && _Lado2 == _Lado3)
	{
		_MensajeResultado = "\tEl triangulo es equilatero";
	}
	else if(_Lado1 == _Lado2 || _Lado1 == _Lado3 || _Lado2 == _Lado3)
	{
		_MensajeResultado = "\tEl triangulo es isosceles";
	}
	else
	{
		_MensajeResultado = "\tEl triangulo es escaleno";
	}
	
	cout << "\n\t--------------------------------------------------" << endl;
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, _MensajeResultado, true);
	
	_Area = CalcularAreaTriangulo(_Lado1, _Lado2, _Lado3);
	cout << "\n";
	
	_MensajeResultado = "\tEl area es: " + to_string(_Area);
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, _MensajeResultado, true);
	
}

float CalcularAreaTriangulo(float pLado1, float pLado2, float pLado3)
{
	 float _P, _AreaCuadrado, _Area;
	 
	 _P = (pLado1 + pLado2 + pLado3) / 2.0;
	 _AreaCuadrado = _P * (_P - pLado1) * (_P - pLado2) * (_P - pLado3);
	 
	 _Area = sqrt(_AreaCuadrado);
	 
	 return _Area;
}

void BuscarNumeroMayor()
{
	float _Numero1, _Numero2, _Numero3, _Numero4, _Numero5;
	string _MensajeResultado = "";
	int _NumeroMayor = 0;
	
	//lectura de datos
    cout << "\n\tDigite el numero 1: ";
    cin >> _Numero1;
                
    cout << "\tDigite el numero 2: ";
    cin >> _Numero2;
    
    cout << "\tDigite el numero 3: ";
    cin >> _Numero3;
    
    cout << "\tDigite el numero 4: ";
    cin >> _Numero4;
    
    cout << "\tDigite el numero 5: ";
    cin >> _Numero5;
    
    cout << "\n\t--------------------------------------------------" << endl;
    if(_Numero1 == _Numero2 == _Numero3 == _Numero4 == _Numero5)
    {
    	_MensajeResultado = "\tLos numeros no pueden ser iguales";   
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, _MensajeResultado, true);
	}
   else
   {
   		//Obtener el mayor numero
		_NumeroMayor = Mayor(_Numero1, _Numero2, _Numero3, _Numero4, _Numero5);
    	
    	_MensajeResultado = "\tEl numero mayor es " + to_string(_NumeroMayor);   
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, _MensajeResultado, true);
   }
}

int Mayor(float pNumero1, float pNumero2, float pNumero3, float pNumero4, float pNumero5)
{
	float _NumeroMayor = 0;
	
	if(pNumero1 > pNumero2 && pNumero1 > pNumero3 && pNumero1 > pNumero4 && pNumero1 > pNumero5)
	{
		_NumeroMayor = pNumero1;
	}
	else if(pNumero2 > pNumero1 && pNumero2 > pNumero3 && pNumero2 > pNumero4 && pNumero2 > pNumero5)
	{
		_NumeroMayor = pNumero2;
	}
	else if(pNumero3 > pNumero1 && pNumero3 > pNumero2 && pNumero3 > pNumero4 && pNumero3 > pNumero5)
	{
		_NumeroMayor = pNumero3;
	}
	else if(pNumero4 > pNumero1 && pNumero4 > pNumero2 && pNumero4 > pNumero3 && pNumero4 > pNumero5)
	{
		_NumeroMayor = pNumero4;
	}
	else 
	{
		_NumeroMayor = pNumero5;
	}
	
	return _NumeroMayor;
}

void CalcularPromedioN_Numeros()
{
	int _TotalNumero = 0;
	float _Numero, _Suma, _Promedio = 0;
	string _MensajeResultado = "";
	
	//lectura de datos
	cout << "\n\tDigite el total de numeros a calcular el promedio: ";
	cin >> _TotalNumero;
	
	cout << endl;
	
	for(int i = 0; i < _TotalNumero; i++)
	{
		cout << "\tDigitite numero " << (i + 1) << ": ";
		cin >> _Numero;
		
		_Suma += _Numero;
	}
	cout << "\n\t--------------------------------------------------" << endl;
	_Promedio = _Suma / _TotalNumero;
	
	_MensajeResultado = "\tTotal numeros (" + to_string(_TotalNumero) + "), Suma: " +  to_string(_Suma) + ", su promedio es: " + to_string(_Promedio);
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, _MensajeResultado, true);
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


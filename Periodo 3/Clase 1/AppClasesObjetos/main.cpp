#include "CuentaBancaria.h"
#include "Persona.h"
#include "Personaje.h"

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

//Inicio: prototipos
void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour); //Procedimiento
void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea); //Procedimiento
void ResetConsoleColour(WORD Attributes); //Procedimiento
void OperarCuentaBancaria(); //Procedimiento
void AgregarPersona(); //Procedimiento
void AgregarPersonaje(); //Procedimiento
//Fin: prototipos
int main() 
{
	SetConsoleTitleA("Clases y Objetos: Cuenta Bancaria - Tarea UFG"); //Cambiar el titulo de la consola
	
	int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
		
        cout << "\n\t\t\t Menu del sistema" << endl;
        cout << "\t\t\t-------------------" << endl;
        cout << "\n\t1. Cuenta Bancaria" << endl;
        cout << "\t2. Agregar persona" << endl;
        cout << "\t3. Agregar personaje" << endl;
        cout << "\t4. Informacion del autor...." << endl;
        cout << "\t0. SALIR" << endl;
        
        cout << "\n\tDigite una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1:           	
                OperarCuentaBancaria();
                cout << endl;
				AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN          
                system("pause>nul");
                
                break;
                
            case 2:
                AgregarPersona();
                cout << endl;
                AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
                
            case 3:
                AgregarPersonaje();
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

//Implementaciones
void OperarCuentaBancaria()
{
	//Crear primera cuenta bancaria
	CuentaBancaria miCuenta("A-480920", "Jose Castillo", 12000.00);
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tTitular: " + miCuenta.getNombreTitular(), true);
	cout << "\t#Cuenta: " << miCuenta.getNumeroCuenta() << endl;
	cout << "\tSaldo: $" << miCuenta.getSaldo() << endl;
	cout << "\t------------------------------------------ " << endl;
	
	//Creando segunda cuenta bancaria
	CuentaBancaria cuentaAmigo("C-165426", "Maria Gomez", 10000);
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tTitular: " + cuentaAmigo.getNombreTitular(), true);
	cout << "\t#Cuenta: " << cuentaAmigo.getNumeroCuenta() << endl;
	cout << "\tSaldo: $" << cuentaAmigo.getSaldo() << endl;
	cout << "\t------------------------------------------ " << endl;
	
	//Creando tercera cuenta bancaria
	CuentaBancaria cuentaNoValida("C-354698", "Alex Fuentes", 5000);
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tTitular: " + cuentaNoValida.getNombreTitular(), true);
	cout << "\t#Cuenta: " << cuentaNoValida.getNumeroCuenta() << endl;
	cout << "\tSaldo: $" << cuentaNoValida.getSaldo() << endl;
	cout << "\t------------------------------------------ " << endl;
	
	//Hacer un retiro de la cuenta miCuenta
	cout << "\tQuiero retirar $2000.00 de la cuenta " << miCuenta.getNumeroCuenta() << endl;
	cout << "\tSaldo inicial: $" << miCuenta.getSaldo() << endl;
	miCuenta.retirar(2000);
	cout << "\tSaldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
	cout << "\t------------------------------------ " << endl;
	
	//Hacer un retiro de la cuenta miCuenta mayor al saldo disponible
	cout << "\tQuiero retirar $15000.00 de la cuenta " << miCuenta.getNumeroCuenta() << endl;
	cout << "\tSaldo inicial: $" << miCuenta.getSaldo() << endl;
	miCuenta.retirar(15000);
	cout << "\tSaldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
	cout << "\t------------------------------------ " << endl;
	
	//Hacer un retiro de un monto negativo
	cout << "\tQuiero retirar -$1000.00 de la cuenta " << miCuenta.getNumeroCuenta() << endl;
	cout << "\tSaldo inicial: $" << miCuenta.getSaldo() << endl;
	miCuenta.retirar(-1000);
	cout << "\tSaldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
	cout << "\t------------------------------------ " << endl;
	
	//Hacer un deposito a la cuenta miCuenta
	cout << "\tQuiero depositar $500.00 a la cuenta " << miCuenta.getNumeroCuenta() << endl;
	cout << "\tSaldo inicial: $" << miCuenta.getSaldo() << endl;
	miCuenta.depositar(500);
	cout << "\tSaldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
	cout << "\t------------------------------------ " << endl;
	
	//Hacer un deposito de un monto negativo
	cout << "\tQuiero depositar -$500.00 a la cuenta " << miCuenta.getNumeroCuenta() << endl;
	cout << "\tSaldo inicial: $" << miCuenta.getSaldo() << endl;
	miCuenta.retirar(-500);
	cout << "\tSaldo luego de la operacion: $" << miCuenta.getSaldo() << endl;
	cout << "\t------------------------------------ " << endl;
}

void AgregarPersona()
{
	string nombres;
	string apellidos;
	int anioNacimiento;
	
	cout << "\tPor favor ingrese sus nombres: ";
	getline(cin, nombres);
    getline(cin, nombres);
	
	cout << "\tPor favor ingrese sus apellidos: ";
	getline(cin, apellidos);
		
	cout << "\tPor favor ingrese su anio de nacimiento: ";
	cin >> anioNacimiento;
	
	Persona persona1(nombres, apellidos, anioNacimiento);
	cout << endl;
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\t----- Datos de la persona -----", true);
	cout << "\tNombre: " << persona1.nombreCompleto() << endl;
	cout << "\tEdad: " << persona1.edad() << " anios" << endl;
}

void AgregarPersonaje()
{
	
	//Crear personaje
	string _Nombre = "Jose Castillo";
	int _PuntosVidaInicio = 15;
	int _puntosPerdidos = 5;
	int _puntosGanados = 5;
	Personaje mipersonaje(_Nombre, _PuntosVidaInicio);
	
	//Mostrar el personaje
	cout << "\tPersonaje creado: " << mipersonaje.getNombre() << endl;
	cout << "\tPuntos Inciales: " << "[ " << mipersonaje.getPuntosVida() << " ]" << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	
	//Personaje esquivó el golpe
	cout << "\tPersonaje logro esquivar el golpe" << endl;
	mipersonaje.comer(_puntosGanados);
	cout << "\tPuntos actuales: " << mipersonaje.getPuntosVida() << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	//Personaje recibio el golpe	
	cout << "\tPersonaje recibio el golpe" << endl;
	mipersonaje.recibirGolpe(_puntosPerdidos);
	cout << "\tPuntos actuales: " << mipersonaje.getPuntosVida() << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	//Personaje recibio el golpe	
	cout << "\tPersonaje recibio el golpe" << endl;
	mipersonaje.recibirGolpe(_puntosPerdidos);
	cout << "\tPuntos actuales: " << mipersonaje.getPuntosVida() << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	//Personaje recibio el golpe	
	cout << "\tPersonaje recibio el golpe" << endl;
	mipersonaje.recibirGolpe(_puntosPerdidos);
	cout << "\tPuntos actuales: " << mipersonaje.getPuntosVida() << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	//Personaje esquivó el golpe
	cout << "\tPersonaje logro esquivar el golpe" << endl;
	mipersonaje.comer(_puntosGanados);
	cout << "\tPuntos actuales: " << mipersonaje.getPuntosVida() << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	//Personaje recibio el golpe	
	cout << "\tPersonaje recibio el golpe" << endl;
	mipersonaje.recibirGolpe(_puntosPerdidos);
	cout << "\tPuntos actuales: " << mipersonaje.getPuntosVida() << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	//Personaje recibio el golpe	
	cout << "\tPersonaje recibio el golpe" << endl;
	mipersonaje.recibirGolpe(_puntosPerdidos);
	cout << "\tPuntos actuales: " << mipersonaje.getPuntosVida() << endl;
	if(mipersonaje.estaVivo())
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tPersonaje esta vivo?: SI", true);
	}
	else
	{
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tPersonaje esta vivo?: NO", true);
	}
	cout << "\t------------------------------------ " << endl;
	
	
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

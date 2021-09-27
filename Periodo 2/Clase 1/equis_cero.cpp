#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <windows.h>
#include <stdio.h>
#include <math.h>

using namespace std;

const int LADO = 3;

//Inicio: Prototipos
void imprimirTablero(char tablero[][LADO]); //Procedimiento
int marcarCasillaJugador(char tablero[][LADO]); //Funcion
int leerNumero(string indicacion, string mensajeError, int min, int max); //Funcion
int marcarCasillaComputadora(char tablero[][LADO]); //Funcion
char ganadorFilas(char tablero[][LADO]); //Funcion
char ganadorColumnas(char tablero[][LADO]); //Funcion
char ganadorDiagonales(char tablero[][LADO]); //Funcion
char determinarGanador(char tablero[][LADO]); //Funcion
void jugar(); //Procedimiento

void AplicarColorDinamico_SinTexto(WORD* Attributes, DWORD Colour); //Procedimiento
void AplicarColorDinamico_ConTexto(DWORD Colour, string pTexto, bool pIsSaltoLinea); //Procedimiento
void ResetConsoleColour(WORD Attributes); //Procedimiento
//Fin: Prototipos

int main(){
	
	SetConsoleTitleA("Juego de equis cero - Tarea UFG"); //Cambiar el titulo de la consola
	
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
	AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
		
	char jugarDeNuevo;
	srand(time(0));  //inicializa la semilla de los numeros aleatorios
	do {
		jugar();
		cout << "\tDesea jugar de nuevo (S|n)?";
		cin >> jugarDeNuevo;
		cout << endl;
	} while (toupper(jugarDeNuevo) == 'S');
	
	return 0;
}

//Implementacion

void jugar() {
	char tablero[LADO][LADO] = {};
	char ganador = 0;
	
	cout << "\n\tJuego de equis-cero" << endl;
	int casillasLibres = LADO * LADO;
	bool turnoJugador = true;
	imprimirTablero(tablero);
	
	while(casillasLibres > 0 && ganador == 0){
		if(turnoJugador){
			casillasLibres -= marcarCasillaJugador(tablero);
		} else {
			casillasLibres -= marcarCasillaComputadora(tablero);
		}
		turnoJugador = !turnoJugador; // Turno del otro jugador
		ganador = determinarGanador(tablero);
	}
	switch (ganador) {
		case 'X':
			AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tUste gana!!!", true);
			break;
		case '0':
			cout << "\tLa computadora gana :(" << endl;
			break;
		default:
			cout << "\tEmpate." << endl;
	}
	
}

void imprimirTablero(char tablero[][LADO]){
	// Cuente los espacios usando los puntos
	// Guia: .................   ...............
	cout << "\n    0   1   2\n    -----------" << endl ; 
	for (int fila = 0; fila < LADO; fila++){
		cout << " " << fila	<< " |";
		for (int columna = 0; columna < LADO; columna++){
			cout << " " << tablero[fila][columna] << " |";
		}
		// Guia: ..........
		cout << "\n    -----------" << endl;
	}
	cout << endl;
	
}

int leerNumero(string indicacion, string mensajeError, int min, int max){
	int numero;
	cout << indicacion << ": ";
	
	// Valida que la entrada sea un entero
	while(!(cin >> numero) || (numero < min || numero >= max)) {
		cin.clear(); // limpiar la entrada estandar
		cin.ignore(10000, '\n'); // descarta la entrada hasta encontrar un salto de linea
		cout << mensajeError << endl; // muestra un mensaje de error
		cout << indicacion << ": "; // le da otra oportunidad al usuario
	}
	
	return numero;
}

int marcarCasillaJugador(char tablero[][LADO]){
	int fila, columna;
	cout << "\tJugador (x):" << endl;
	string mensaje = "\tIngrese un valor entre 0 y " + to_string(LADO);
	fila = leerNumero("\tFila", mensaje, 0, LADO);
	columna = leerNumero("\tColumna", mensaje, 0, LADO);
	while (tablero[fila][columna] != 0){
		AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tCasilla ocupada. Intente de nuevo", true);
		cout << endl;
		fila = leerNumero("\tFila", mensaje, 0, LADO);
		columna = leerNumero("\tColumna", mensaje, 0, LADO);
	}
	tablero[fila][columna] = 'X';
	imprimirTablero(tablero);
	return 1;
}

int marcarCasillaComputadora(char tablero[][LADO]) {
	int fila, columna;
	fila = rand() % LADO;
	columna = rand() % LADO;
	while (tablero[fila][columna] != 0) {
		fila = rand() % LADO;
		columna = rand() % LADO;
	}
	tablero[fila][columna] = '0';
	cout << "\tComputadora (o): seleccion automatica" << endl;
	imprimirTablero(tablero);
	return 1;
}

char determinarGanador(char tablero[][LADO]) {
	char ganador;
	
	// Ganador por filas?
	ganador = ganadorFilas(tablero);
	
	// Ganador por columnas?
	if (ganador == 0)
		ganador = ganadorColumnas(tablero);
	
	// Ganador por diagonales?
	if (ganador == 0)
		ganador = ganadorDiagonales(tablero);
	
	return ganador;
}


char ganadorFilas(char tablero[][LADO]) {
	for (int fila = 0; fila < LADO; fila++){
		// Primer caracter de la fila
		char caracter = tablero[fila][0];
		int veces = 0;
		if (caracter != 0){
			// Cantar cuantas veces aparece el caracter en la fila
			for (int columna = 0; columna < LADO; columna++) {
				if (tablero[fila][columna] == caracter) {
					veces++;
				}
			}
			if (veces == LADO) {
				return caracter;
			}
		}
	}
	return 0;
}

char ganadorColumnas(char tablero[][LADO]) {
	for (int columna = 0; columna < LADO; columna++){
		// Primer caracter de la columna
		char caracter = tablero[0][columna];
		int veces = 0;
		if (caracter != 0){
			// Cantar cuantas veces aparece el caracter en la columna
			for (int fila = 0; fila < LADO; fila++) {
				if (tablero[fila][columna] == caracter) {
					veces++;
				}
			}
			if (veces == LADO) {
				return caracter;
			}
		}
	}
	return 0;
}

char ganadorDiagonales(char tablero[][LADO]) {
	char caracter;
	int veces;
	
	// Diagonal de izquierda a derecha (\)
	caracter = tablero[0][0];
	veces = 0;
	if(caracter != 0) {
		for (int i = 0; i < LADO; i++)
			if (tablero[i][i] == caracter)
				veces++;
		if (veces == LADO)
			return caracter;
	}
	
	//Diagonal dela derecha a izquierda (/)
	caracter = tablero[0][LADO - 1];
	veces = 0;
	if (caracter != 0){
		for (int i = 0; i < LADO; i++)
			if(tablero[i][LADO - 1 - i] == caracter)
				veces++;
		if (veces == LADO)
			return caracter;
	}
	
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

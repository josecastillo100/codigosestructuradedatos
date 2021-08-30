#include <iostream>
#include <limits>
#include <Windows.h>

using namespace std;

int main(){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //Acceder a la consola de colores
	SetConsoleTitleA("TAMANIO DE TIPO DE DATOS - TAREA UFG"); //Cambiar el titulo de la consola

	SetConsoleTextAttribute(h, 9); //Método para cambiar el color del texto de la consulta - 9 = LIGHTBLUE
	cout << " ESTUDIANTE: CASTILLO ARTIAGA, JOSE ALFREDO " << endl;
	cout << " CARNE: CA102817" << endl;
	cout << "\n";
	
	//-----------------------------------------------------------------------------------
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de datos Integer positivo (int): " << endl;
	int intmin = numeric_limits<int>::min(); //valor minimo que puede tener un Integer
	int intmax = numeric_limits<int>::max(); //valor máximo posible que puede tener un valor Integer
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " intmin = " << intmin << endl;
	cout << " intmax = " << intmax << "\n";
	cout << " tamanio de int: " << sizeof(int) << endl << "\n";
	
	//--------------------------------------------------------------------------------------
	
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de dato con punto flotante (float): " << endl;
	float floatmin = std::numeric_limits<float>::min();
	float floatmax = std::numeric_limits<float>::max();	
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " floatmin = " << floatmin << endl;
	cout << " floatmax = " << floatmax << "\n";
	cout << " tamanio de float: " << sizeof(float) << endl << "\n";
	
	//---------------------------------------------------------------------------------------
	
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de dato caracter (char): " << endl;
	char charmin = numeric_limits<char>::min();
	char charmax = numeric_limits<char>::max();
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " charmin = " << charmin << endl;
	cout << " charmax = " << charmax << endl;
	cout << " tamanio de char: " << sizeof(char) << endl << "\n";
	
	//---------------------------------------------------------------------------------------
	
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de dato Integer positivo largo (long): " << endl;
	long longmin = numeric_limits<long>::min();
	long longmax = numeric_limits<long>::max();
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " longmin = " << longmin << endl;
	cout << " longmax = " << longmax << endl;
	cout << " tamanio de long: " << sizeof(long) << endl << "\n";
	
	//---------------------------------------------------------------------------------------
	
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de dato Integer corto positivo (short): " << endl;
	short shortmin = numeric_limits<short>::min();
	short shortmax = numeric_limits<short>::max();
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " shortmin = " << shortmin << endl;
	cout << " shortmax = " << shortmax << endl;
	cout << " tamanio de short: " << sizeof(short) << endl << "\n";
	
	//---------------------------------------------------------------------------------------
	
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de dato con doble punto flotante (double): " << endl;
	double doublemin = numeric_limits<double>::min();
	double doublemax = numeric_limits<double>::max();
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " doublemin = " << doublemin << endl;
	cout << " doublemax = " << doublemax << endl;
	cout << " tamanio de double: " << sizeof(double) << endl << "\n";
	
	//---------------------------------------------------------------------------------------
	
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de dato booleano (bool): " << endl;
	bool boolmin = numeric_limits<bool>::min();
	bool boolmax = numeric_limits<bool>::max();
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " boolmin = " << boolmin << endl;
	cout << " boolmax = " << boolmax << endl;
	cout << " tamanio de bool: " << sizeof(bool) << endl << "\n";
	
	
	//---------------------------------------------------------------------------------------
	
	SetConsoleTextAttribute(h,14); //Método para cambiar el color del texto de la consulta - 14 = YELLOW
	cout << " Tipo de dato Carácter amplio (wchar_t): " << endl;
	wchar_t wchar_tmin = numeric_limits<wchar_t>::min();
	wchar_t wchar_tmax = numeric_limits<wchar_t>::max();
	
	SetConsoleTextAttribute(h,7); //Método para cambiar el color del texto de la consulta - 7 = LIGHTGRAY
	cout << " wchar_tmin = " << wchar_tmin << endl;
	cout << " wchar_tmax = " << wchar_tmax << endl;
	cout << " tamanio de wchar_t: " << sizeof(wchar_t) << endl << "\n";
	
	return 0; 
}

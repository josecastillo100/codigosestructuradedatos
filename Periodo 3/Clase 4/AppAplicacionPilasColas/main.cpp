//Created by Jose Alfredo Castillo on 02/10/2021

#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <stack> //Pila
#include <queue> //Cola
#include "Utilidades.h"
#include <list>
#include <algorithm>

using namespace std;

string pilaComoCadena(stack<string> pPila);
string colaComoCadena(queue<string> pCola);
bool IsEtiquetasBalanceadas(string expresion);
void Ejercicio1_etiquestasHTML();
void Ejercicio2_palabrasPolindromas();
bool IsPalabrapalindromo(string expresion);

int main(int argc, char** argv) {
	SetConsoleTitleA("Ejercicios de aplicacion de pilas y colas - Tarea UFG"); //Cambiar el titulo de la consola
	
	//Instanciando clases
	Utilidades _Utilidad;
	
	
	int opcion;
    bool repetir = true;
    
    do {
        system("cls");
        
        _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tESTUDIANTE (AUTOR): CASTILLO ARTIAGA, JOSE ALFREDO", true); // Color CYAN
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tCARNE: CA102817", true); // Color CYAN
		
        cout << "\n\t\t\t Menu del sistema" << endl;
        cout << "\t\t\t-------------------" << endl;
        cout << "\n\t1. Ejemplo de Pilas (Etiquestas HTML)" << endl;
        cout << "\t2. Ejemplo de Pilas y Colas  (Verificar palabra palindromo)" << endl;
        cout << "\t3. Informacion del autor...." << endl;
        cout << "\t0. SALIR" << endl;
        
        cout << "\n\tDigite una opcion: ";
        cin >> opcion;
        cout << endl;
        switch (opcion) {
            case 1:
				Ejercicio1_etiquestasHTML();     	
                cout << endl;
				_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN          
                system("pause>nul");
                
                break;
                
            case 2:
                Ejercicio2_palabrasPolindromas();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
            case 3:            	
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

void Ejercicio1_etiquestasHTML()
{
	//Instanciando clases
	Utilidades _Utilidad;
	string cadena;
	cout << "\tIngrese un HTML: " ;
	getline(cin, cadena);
	getline(cin, cadena);
	cout << endl;
	
	//string cadena = "<html> <head> <title> Ejemplo </title> </head> <body> <h1>Hola mundo</h1> </body> </html>";
    //string cadena = "<html> <head> <title> Ejemplo </title> <body> <h1>Hola mundo</h1> </body> </html>"; //HTML con error
    //string cadena = "<html"; //HTML con error
    
    if(IsEtiquetasBalanceadas(cadena))
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "Las etiquetas estan balanceadas.", true);
	}
	else
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "Las etiquestas no estan balanceadas.", true);
	}
}
void Ejercicio2_palabrasPolindromas()
{
	//Instanciando clases
	Utilidades _Utilidad;
	
	queue<string> unaColaPalabras;
	
	string _Palabra;
	cout << "\tIngrese una palabra: " ;
	getline(cin, _Palabra);
	getline(cin, _Palabra);
	cout << endl;
	
	cout << "\t\tAPLICANDO REGLAS DE NEGOCIO A TEXTO (FORMATOS)" << endl;
	cout << "\t\t----------------------------------------------" << endl;
	
	//Eliminando espacios en blanco
	cout << endl;
	cout << "\tValidando y elimiando espacios----------------------> "; 
	_Palabra.erase(std::remove(_Palabra.begin(), _Palabra.end(), ' '), _Palabra.end());
	cout << _Palabra << endl; 
	
	//Eliminando signos de puntuacion
	cout << "\tValidando y elimiando signos de puntuacion----------> "; 
	_Palabra.erase(std::remove_if(_Palabra.begin(), _Palabra.end(), [](unsigned char c) { return std::ispunct(c); }), _Palabra.end());
    cout << _Palabra << endl;
    
	//Elimiinando caracteres no alfanuméricos
	cout << "\tValidando y elimiando caracteres no alfanumericos---> "; 
	_Palabra.erase(std::remove_if(_Palabra.begin(), _Palabra.end(), [](char c) { return !std::isalnum(c); }), _Palabra.end());
	cout << _Palabra << endl;
	
	//Eliminando numeros
	cout << "\tValidando y elimiando numeros-----------------------> "; 
	_Palabra.erase(std::remove_if(_Palabra.begin(), _Palabra.end(), [](int ch) { return std::isdigit(ch); }), _Palabra.end()); 
	cout << _Palabra << endl;
	
	//Convirtienod letras a minuculas
	cout << "\tValidando y convirtiendo a minusculas---------------> "; 
	transform(_Palabra.begin(), _Palabra.end(), _Palabra.begin(), [](unsigned char c){ return tolower(c); });
	cout << _Palabra << endl << endl;
	
	if(IsPalabrapalindromo(_Palabra))
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_BLUE, "\tLa palabra (" + _Palabra + ") es palindromo.", true);
	}
	else
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\tLa palabra (" + _Palabra + ") no es palindromo.", true);
	}
}

bool IsEtiquetasBalanceadas(string expresion)
{
	//Instanciando clases
	Utilidades _Utilidad;
	
	cout << "HTML entrante: " << expresion << endl << endl;
	//Creando el objeto pila
	stack<string> unaPilaEtiquetas;

	//Aplicando expresiones regulares para obtener las etiquesta del html
	regex self_regex("REGULAR EXPRESSIONS", regex_constants::ECMAScript | regex_constants::icase);
    regex word_regex("(<\\w+>|</\\w+>)");
    auto words_begin =  sregex_iterator(expresion.begin(), expresion.end(), word_regex);
    auto words_end = sregex_iterator();
 
 	//Creando la lista para almacenar las etiquetas
 	list<string> MiListaEtiquestasHTML;
 	for (sregex_iterator i = words_begin; i != words_end; ++i) 
	{
		 smatch match = *i;
		 MiListaEtiquestasHTML.push_back(match.str());
	}
 	
 	bool doubleValidar = true;
 	//Contador las etiquestas de la lista
 	cout << "Etiquetas encontradas: " << MiListaEtiquestasHTML.size() << endl;
 	cout << endl;
 	
 	//Validando que la lista no esta vacia
 	if(!MiListaEtiquestasHTML.empty())
 	{
	 	//Recorriendo la lista 		
 		for(list<string>::iterator s = MiListaEtiquestasHTML.begin(); s != MiListaEtiquestasHTML.end(); s++)
   		{
   			string _IterEtiquesta = *s;
   			
   			//Verificar que la etiquesta sea de apertura o de cierre
      		if(_IterEtiquesta.substr(0,2) != "</")
        	{
        		//Si la etiquesta es de apertura, entonces la almacenamos en la pila usando push
        	 	unaPilaEtiquetas.push(_IterEtiquesta);
			}
			else if(_IterEtiquesta.substr(0,2) == "</" /*&& _IterEtiquesta.substr(_IterEtiquesta.length() - 1 ) == ">"*/) 
			{
				if(unaPilaEtiquetas.empty()) 
				{
					return false;
				}
				
				string _InicioEtiquestaPila_pop = unaPilaEtiquetas.top();
				
				string _InicioEtiquestaPila_pop_Find = _InicioEtiquestaPila_pop;
				_InicioEtiquestaPila_pop_Find.erase(0, 1);
				_InicioEtiquestaPila_pop_Find.erase(_InicioEtiquestaPila_pop_Find.size() - 1);
				
				if (_IterEtiquesta.find(_InicioEtiquestaPila_pop_Find) != std::string::npos)
				{
					//Hacemos la union de etiqueta de apertura con su cierre.	
					cout << "Etiqueta inicio: " << _InicioEtiquestaPila_pop << " | " << "Etiqueta cierre: " << _IterEtiquesta << endl;
					//Quitar etiquesta de la pila
					unaPilaEtiquetas.pop();
				}
				else
				{
					cout << "Etiqueta inicio: ";
					_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, _InicioEtiquestaPila_pop, false);
					cout << " | Etiqueta cierre: ";
					_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, _IterEtiquesta, false);
					cout << endl;
					doubleValidar = false;
				}
			}
   		}
   		cout << endl;
   		cout << "\nFinal de la Pila: " << pilaComoCadena(unaPilaEtiquetas) << endl;
	}
	else
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\nNo se han encontrado ninguna etiqueta", true);
		cout << endl;
		return false;
	}
	cout << endl;
	
	bool resultado = (unaPilaEtiquetas.empty() && doubleValidar) ? true : false; 
	return resultado;
}
string pilaComoCadena(stack<string> pPila)
{
	stack<string> _tempPila;
	_tempPila = pPila;
	
	int cuenta = _tempPila.size();
	ostringstream s;
	s << "[";
	for(int i = 0; i < cuenta; i++)
	{
		s << _tempPila.top();
		if(i < cuenta - 1)
		{
			s << ", ";
			_tempPila.pop();
		}
	}
	s << "]";
	return s.str();
}

string colaComoCadena(queue<string> pCola)
{
	queue<string> _tempCola;
	_tempCola = pCola;
	
	int cuenta = _tempCola.size();
	ostringstream s;
	s << "[";
	for(int i = 0; i < cuenta; i++)
	{
		s << _tempCola.front();
		if(i < cuenta - 1)
		{
			s << ", ";
			_tempCola.pop();
		}
	}
	s << "]";
	return s.str();
}
bool IsPalabrapalindromo(string expresion)
{
	bool _Resultado = false;
	
	stack<string> _tempPila;
	queue<string> _tempCola;
	
	for(size_t i = 0; i < expresion.length(); i++)
	{
		char caracter = expresion[i];
		string s;
        s.push_back(caracter);
         
		_tempPila.push(s);
		_tempCola.push(s);
	}
	string _CadenaPila = pilaComoCadena(_tempPila);
	string _CadenaCola = colaComoCadena(_tempCola);
	
	cout << "\tResultado pila: " << _CadenaPila << endl;
	cout << "\tResultado cola: " << _CadenaCola << endl << endl;
	
	if(_CadenaPila == _CadenaCola)
	{
		_Resultado = true;
	}
	else
	{
		_Resultado = false;
	}
	
	return _Resultado;
}

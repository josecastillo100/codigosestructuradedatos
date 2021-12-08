//Created by Jose Alfredo Castillo on 02/10/2021

#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <list>
#include <algorithm>

#include "Utilidades.h"
#include "pila.h" //Pila usando listas genericas
#include "cola.h" //Colas usando listas genercias
//#include listagenerica.h //Lista generica principal

using namespace std;

bool IsEtiquetasBalanceadas(string expresion);
void Ejercicio1_etiquestasHTML();
void Ejercicio2_palabrasPolindromas();
bool IsPalabrapalindromo(string expresion);
void ExamenParcial3Pregunta2();
void ExamenParcial3Pregunta3();
void ExamenParcial3Pregunta5();
void ExamenParcial3Pregunta6();
void ExamenParcial3Pregunta4();
void ExamenParcial3Pregunta8();
void ExamenParcial3PreguntaListas();

int main(int argc, char** argv) {
	SetConsoleTitleA("Ejercicios de aplicacion de pilas y colas Con listas genercias - Tarea UFG"); //Cambiar el titulo de la consola
	
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
        cout << "\t4. Parcial 3 Pregunta 2...." << endl;
        cout << "\t5. Parcial 3 Pregunta 3...." << endl;
        cout << "\t6. Parcial 3 Pregunta 5...." << endl;
        cout << "\t7. Parcial 3 Pregunta 6...." << endl;
        cout << "\t8. Parcial 3 Pregunta 4...." << endl;
        cout << "\t9. Parcial 3 Pregunta 8...." << endl;
        cout << "\t10. Parcial 3 Pregunta Listas enteror...." << endl;
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
            case 4:
                ExamenParcial3Pregunta2();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
			 case 5:
                ExamenParcial3Pregunta3();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
             case 6:
                ExamenParcial3Pregunta5();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
             case 7:
                ExamenParcial3Pregunta6();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
             case 8:
                ExamenParcial3Pregunta4();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
            case 9:
                ExamenParcial3Pregunta8();
                cout << endl;
                _Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE, "\tEnter o Intro para regresar...", true); // Color CYAN
                system("pause>nul");
                
                break;
            case 10:
                ExamenParcial3PreguntaListas();
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
	Pila<string> unaPilaEtiquetas;

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
				if(unaPilaEtiquetas.estaPilaVacia()) 
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
   		cout << "\nFinal de la Pila: " << unaPilaEtiquetas.pilaComoCadena() << endl;
	}
	else
	{
		_Utilidad.AplicarColorDinamico_ConTexto(FOREGROUND_INTENSITY | FOREGROUND_RED, "\nNo se han encontrado ninguna etiqueta", true);
		cout << endl;
		return false;
	}
	cout << endl;
	
	bool resultado = (unaPilaEtiquetas.estaPilaVacia() && doubleValidar) ? true : false; 
	return resultado;
}

bool IsPalabrapalindromo(string expresion)
{
	bool _Resultado = false;
	
	Cola<string> _tempCola;
	Pila<string> _tempPila;
	
	for(size_t i = 0; i < expresion.length(); i++)
	{
		char caracter = expresion[i];
		string s;
        s.push_back(caracter);
         
		_tempCola.enqueue(s);
		_tempPila.push(s);
	}
	string _CadenaPila = _tempPila.pilaComoCadena();
	string _CadenaCola = _tempCola.colaComoCadena();
	
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
void ExamenParcial3Pregunta2()
{
	Cola<int> _Cola;
	_Cola.enqueue(1);
	_Cola.enqueue(2);
	_Cola.enqueue(3);
	_Cola.enqueue(4);
	_Cola.enqueue(5);
	_Cola.enqueue(6);
	_Cola.enqueue(7);
	
	//aplicar reglas
	_Cola.dequeue();
	_Cola.dequeue();
	_Cola.dequeue();
	_Cola.enqueue(1);
	_Cola.enqueue(2);
	_Cola.enqueue(3);

	string _Imprimir = _Cola.colaComoCadena();
	
 	cout << "\tResultado cola: " << _Imprimir << endl;
}
void ExamenParcial3Pregunta3()
{
	Cola<int> _C;
	Pila<int> _P;
	
	_C.enqueue(1);
	_C.enqueue(3);
	_C.enqueue(5);
	_C.enqueue(7);
	_C.enqueue(9);
	
	cout << "\tCola original: " << _C.colaComoCadena() << endl << endl;
	
	//Se remueven 3 elementos de la cola y se agregan a la pila
	_P.push(_C.front());
	_C.dequeue();
	
	_P.push(_C.front());
	_C.dequeue();
	
	_P.push(_C.front());
	_C.dequeue();
	
	cout << "\tRemoviendo 3 elementos, quedan en la cola C: " << _C.colaComoCadena() << endl ;
	cout << "\tAgregando los 3 elementos a la Pila P: " << _P.pilaComoCadena() << endl << endl;
	
	//Se remueven todos los elementos de la Pila y se agregan nuevamente a la Cola
	_C.enqueue(_P.top());
	_P.pop();
	
	_C.enqueue(_P.top());
	_P.pop();
	
	_C.enqueue(_P.top());
	_P.pop();
	
	cout << "\tRemoviendo los elementos de la pila P: " << _P.pilaComoCadena()<< endl;
	cout << "\tAgregando los elementos a la Cola C: " << _C.colaComoCadena() << endl << endl;
	
	cout << "\tResultado cola: " << _C.colaComoCadena() << endl;
}
void ExamenParcial3Pregunta5()
{
	Pila<string> _P;
	_P.push("M");
	_P.push("A");
	_P.pop();
	
	cout << "\tEjecutamos pop, la pila queda con: " << _P.pilaComoCadena() << endl << endl;
	
	_P.push("R");
	_P.push("I");
	_P.push("O");
	_P.pop();
	
	cout << "\tResultado pila: " << _P.pilaComoCadena() << endl;
}
 void ExamenParcial3Pregunta6()
 {
 	Cola<int> _C;
 	_C.enqueue(25);
 	_C.enqueue(12);
 	_C.dequeue();
 	_C.enqueue(19);
 	_C.dequeue();
 	
 	cout << "\tResultado Cola: " << _C.colaComoCadena() << endl;
 }
 
 void ExamenParcial3Pregunta4()
 {
 	Pila<int> P;
 	P.push(1);
 	P.push(2);
 	
 	string _Resultado_POP_Salida;
 	
 	_Resultado_POP_Salida = to_string(P.top()) + ", ";
 	P.pop();
 	P.push(3);
 	P.push(4);
 	
 	_Resultado_POP_Salida = _Resultado_POP_Salida + to_string(P.top()) + ", ";
 	P.pop();
 	
 	_Resultado_POP_Salida = _Resultado_POP_Salida + to_string(P.top()) + ", ";
 	P.pop();
 	
 	_Resultado_POP_Salida = _Resultado_POP_Salida + to_string(P.top()) + ", ";
 	P.pop();
 	P.push(5);
 	
 	_Resultado_POP_Salida = _Resultado_POP_Salida + to_string(P.top());
 	P.pop();
 	
 	cout << "\tResultado pila: " << _Resultado_POP_Salida << endl;
 }
 
 void ExamenParcial3Pregunta8()
 {
 	Pila<int> P;
 	Cola<int> C;
	P.push(42);
	P.push(28);
	P.push(64);
	P.push(53);
	P.push(14);
	P.push(16);
	
	cout << "\tPila original: " << P.pilaComoCadena() << endl << endl;
	
	//Se remueven 4 elementos de la Pila y se agregan a la cola
	C.enqueue(P.top());
	P.pop();
	
	C.enqueue(P.top());
	P.pop();
	
	C.enqueue(P.top());
	P.pop();
	
	C.enqueue(P.top());
	P.pop();
	
	cout << "\tSe remueven 4 elementos de la P, en la pilan quedan: " << P.pilaComoCadena() << endl;
	cout <<  "\tSe Agregan 4 elementos a la cola: " << C.colaComoCadena() << endl << endl;
	
	//Se remueven todos los elementos de la cola C y se agregan nuevamente a la pila P
	P.push(C.front());
	C.dequeue();
	
	P.push(C.front());
	C.dequeue();
	
	P.push(C.front());
	C.dequeue();
	
	P.push(C.front());
	C.dequeue();
	
	cout << "\tRemoviendo todos los elementos de la cola C, quedan en la cola: " << C.colaComoCadena() << endl;
	cout << "\tAgregando los elementos de nuevo a la Pila P: " << P.pilaComoCadena() << endl << endl;
	
	cout << "\tResultado pila: " << P.pilaComoCadena() << endl;
 }
 void ExamenParcial3PreguntaListas()
 {
 	Lista<int> L;
	
	L.adjuntar(5);
	L.insertar(0, 7);
	L.insertar(1, 3);
	L.remover(0);
	L.adjuntar(2);
	cout << "\t" << L.comoCadena() << endl;
 }

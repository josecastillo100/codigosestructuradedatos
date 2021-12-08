#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class ArbolBinarioBusqueda;

class NodoArbol{
	friend class ArbolBinarioBusqueda;
	private:
		string clave;
		int valor;
		NodoArbol *izq;
		NodoArbol *der;
		
	public:
		NodoArbol(string clave, int valor): clave(clave), valor(valor), izq(0), der(0){
			
		} 
};

class ArbolBinarioBusqueda{
	private:
		NodoArbol *raiz;
		int numeroNodos;
		void auxiliarPoner(NodoArbol *&raizSubarbol, string clave, int valor);
		void auxiliarDestruir(NodoArbol *raizSubarbol);
		void auxiliarBorrar(NodoArbol *&raizSubarbol, string clave);
		void auxliarEnOrden(NodoArbol *raizSubarbol, vector<string> &v);
		void auxiliarCopiar(NodoArbol *raizSubarbol);
		NodoArbol *desvincularMinimo(NodoArbol *&raizSubarbol);
	public:
		ArbolBinarioBusqueda();
		~ArbolBinarioBusqueda();
		ArbolBinarioBusqueda(const ArbolBinarioBusqueda &otro);
		int obtener(string clave);
		void poner(string clave, int valor);
		bool contiene(const string &clave);
		void borrar(string clave);
		bool estaVacio();
		bool tamano();
		vector<string> claves();
};

bool ArbolBinarioBusqueda::contiene(const string &clave){
	return this->obtener(clave)==-1;
}

int ArbolBinarioBusqueda::obtener(string clave){
	NodoArbol *nodoActual = this->raiz;
	while(nodoActual != 0){
		if (clave < nodoActual->clave)
			nodoActual = nodoActual->izq;
		else if (clave > nodoActual->clave)
			nodoActual = nodoActual->der;
		else
			return nodoActual->valor;
	}
	return -1;
}

void ArbolBinarioBusqueda::poner(string clave, int valor){
	this->auxiliarPoner(this->raiz, clave, valor);
}


void ArbolBinarioBusqueda::auxiliarPoner(NodoArbol *&raizSubarbol, string clave, int valor){
	if (raizSubarbol==0){
		raizSubarbol = new NodoArbol(clave, valor);
		this->numeroNodos += 1;
		return;
	}
	if (clave < raizSubarbol->clave)
		this->auxiliarPoner(raizSubarbol->izq,clave,valor);
	else if (clave > raizSubarbol->clave)
		this->auxiliarPoner(raizSubarbol->der,clave,valor);
	else
		raizSubarbol->valor = valor;
}

void ArbolBinarioBusqueda::auxliarEnOrden(NodoArbol *raizSubarbol, vector<string> &v){
	if (raizSubarbol==0)
		return;
	auxliarEnOrden(raizSubarbol->izq, v);
	v.push_back(raizSubarbol->clave);
	auxliarEnOrden(raizSubarbol->der, v);
}

vector<string> ArbolBinarioBusqueda::claves(){
	vector<string> v;
	this->auxliarEnOrden(this->raiz, v);
	return v;
}

NodoArbol *ArbolBinarioBusqueda::desvincularMinimo(NodoArbol *&raizSubarbol){
	if (raizSubarbol==0)
		return 0;
	if (raizSubarbol->izq ==0){
		NodoArbol *min= raizSubarbol;
		raizSubarbol=raizSubarbol->der;
		return min;
	}else{
		this->desvincularMinimo(raizSubarbol->izq);
	}
}

void ArbolBinarioBusqueda::borrar(string clave){
	this->auxiliarBorrar(this->raiz, clave);
}

void ArbolBinarioBusqueda::auxiliarBorrar(NodoArbol *&raizSubarbol, string clave){
	if(raizSubarbol==0)
		return;
	
	if (clave < raizSubarbol->clave)
		this->auxiliarBorrar(raizSubarbol->izq, clave);
	else if (clave < raizSubarbol->clave)
		this->auxiliarBorrar(raizSubarbol->der, clave);
	else{
		NodoArbol *temp = raizSubarbol;
		if (raizSubarbol->der==0)
			raizSubarbol=raizSubarbol->izq;
		else if (raizSubarbol->izq==0)
			raizSubarbol=raizSubarbol->der;
		else{
			raizSubarbol = desvincularMinimo(raizSubarbol->der);
			raizSubarbol->der = temp->der;
			raizSubarbol->izq = temp->izq;
		}
		delete temp;
		this->numeroNodos-=1;
	}	
}


#include "miArbol.h"
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]){
	using namespace std;
	
	if (argc != 2){
		cout << "Uso: "<<argv[0]<<" longitud_minima < nombre_archivo\n"<<endl;
		return 1;
	}
	
	int longitudMinima = stoi(argv[1]);
	cout << longitudMinima<<endl;
	ArbolBinarioBusqueda abb;
	string palabra;
	
	while(cin>>palabra){
		if(palabra.size()<longitudMinima)continue;
		if(!abb.contiene(palabra)) abb.poner(palabra, 1);
		else abb.poner(palabra, abb.obtener(palabra)+1);
	}
	
	vector<string> palabras=abb.claves();
	string palabraMasFrecuente="";
	for (int i=0; i<palabras.size();i++){
		string estaPalabra= palabras[i];
		if (abb.obtener(estaPalabra)>abb.obtener(palabraMasFrecuente))
			palabraMasFrecuente=estaPalabra;			
	}
	cout << "Este archivo contiene "<<palabras.size()<<" palabra unica."<<endl;
	cout << "La palabra de al menos "<<longitudMinima<<" letras ";
	cout << "que mas se repite es: "<<palabraMasFrecuente<<endl;
	
	return 0;
}

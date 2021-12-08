#include <iostream>

using namespace std;

//Clase rectangulo
class Rectangulo {
	int ancho, alto;
	public:
		void set_valores(int,int);
		int area() {return ancho*alto;}
};

//Metodo para setear valores
void Rectangulo::set_valores (int x, int y){
	ancho = x;
	alto = y;
}

int main () {
	Rectangulo rect;
	rect.set_valores (4,5);
	cout << "El area es: " << rect.area();
	
	return 0;
}


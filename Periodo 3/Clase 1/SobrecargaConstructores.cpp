//ejemplo : sobrecarga de constructores
#include <iostream>

using namespace std;

class Rectangulo{
	int ancho, alto;
	public:
		Rectangulo();
		Rectangulo(int,int);
		int area (void) {return ancho*alto;}
};

Rectangulo::Rectangulo(){
	ancho = 5;
	alto = 5;
}

Rectangulo::Rectangulo (int x, int y){
	ancho = x;
	alto = y;
}

int main () {
	Rectangulo rect (3,4);
	Rectangulo rectb;
	cout << "rect area: " << rect.area () << endl;
	cout << "rectb area: " << rectb.area () << endl;
	return 0;
}


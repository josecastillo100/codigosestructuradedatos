#include <iostream>

using namespace std;

//Clase Circulo
class Circulo{
	double radius;
	public:
		Circulo(double r) { radius = r;}
		double circunf () { return 2*radius*3.14159265;}
};

int main() {
	Circulo foo (20.0); 		// Para una forma funcional.
	Circulo bar = 30.0; 		// En donde inicializamos por asignación.
	Circulo baz {40.0}; 		// En donde inicializaciamos por uniforme
	Circulo qux = {50.0};  		//POD like (Plain Old Data)
	cout << "Circunferencia de foo: " << foo.circunf () << "\n";
	cout << "Circunferencia de bar: " << bar.circunf () << "\n";
	cout << "Circunferencia de baz : " << baz.circunf () << "\n";
	cout << "Circunferencia de qux : " << qux.circunf () << endl;
	
	return 0;
}

#include <iostream>
using namespace std;

int main(){
	
	double x;
	double y;
	
	cout << " *** Calcula operaciones aritmeticas de dos números *** \n";
	
	cout << "Inserte un numero: ";
	cin >> x;
	
	cout << "Inserte el otro numero: ";
	cin >> y;
	
	cout << "Suma: " << x + y << endl; 				//Suma de x + y
	cout << "Resta: " << x - y << endl;				//Resta de x - y
	cout << "Multiplicacion: " << x * y << endl;	//Multiplica x * y
	cout << "Division: " << x / y << endl;			//Divide x / y
	
	int z = x;
	int w = y;
	cout << "Residuo de division: " << z % w << endl; //Residuo de divir x % y
	
	++x;
	++y;
	cout << "Incremento en uno: " << "x: " << x << " y: " << y << endl;
	
	--x;
	--y;
	cout << "Decremento en uno: " << "x: " << x << " y: " << y << endl;
	
	return 0;
	
}

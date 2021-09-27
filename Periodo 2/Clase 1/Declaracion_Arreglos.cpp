#include <iostream>
#include <iomanip>

//int main(int num_args, char** arg_strings)
//int main(int argc, const char * argv[])
int main()
{
	using namespace std;
	
	//Declarar arreglo de 10 enteros
	int numeros[10];
	
	//Llenar arreglo con valores de 10 a 100
	for(int i=0; i<10; i++)
	{
		numeros[i] = 10 * (i + 1);
	}
	
	//Imprimir valores del arreglo
	cout << "Indice\tValor\n------\t-----\n";
	for(int i=0; i<10; i++)
	{
		cout << setw(6) << i << "\t" << setw(5) << numeros[i] << endl;
	}
	
	return 0;
}



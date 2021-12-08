#include <iostream>
#include <iomanip>

 //Prototipo
void imprimirArreglo(int[][3], int, int);

int main(int argc, const char * argv[])
{
	using namespace std;
	
	int arreglo1[2][3] = {{1,2,3}, {4,5,6}};
	int arreglo2[2][3] = {1,2,3,4,5};
	int arreglo3[2][3] = {{1,2}, {4}};
	
	cout << "Los valores del arreglo 1 son: " << endl;
	imprimirArreglo(arreglo1, 2, 3);
	cout << endl;
	
	cout << "Los valores del arreglo 2 son: " << endl;
	imprimirArreglo(arreglo2, 2, 3);
	cout << endl;
	
	cout << "Los valores del arreglo 3 son: " << endl;
	imprimirArreglo(arreglo3, 2, 3);
	cout << endl;
	
	//modificamos el arreglo3
	arreglo3[0][2] = 3;
	arreglo3[1][1] = 5;
	arreglo3[1][2] = 6;
	
	cout << "Los valores del arreglo 3 (Modificado) son: " << endl;
	imprimirArreglo(arreglo3, 2, 3);
	
	return 0;
}

//Implementacion
void imprimirArreglo(int arr[][3], int filas, int columnas)
{
	using namespace std;
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			cout << "[" << i << "][" << j << "] = ";
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

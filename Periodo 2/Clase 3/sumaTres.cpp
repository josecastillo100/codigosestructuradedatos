#include <iostream>

using namespace std;

//Fuerza bruta
int contarSumaTres(int arr[], int tamanio)
{
	int contar = 0;
	for(int i = 0; i < tamanio; i++)
	{
		for(int j = i + 1; j < tamanio; j++)
		{
			for(int k = j + 1; k < tamanio; k++)
			{
				cout << arr[i] << arr[j] << arr[k] << endl;
				if(arr[i] + arr[j] + arr[k] == 0)
				{
					contar++;
				}
			}
		}
	}
	return contar;
}

int main()
{
	int arr[] = {1, 2, 4};
	int arr2[] = {-1, 3, -2};
	int size = sizeof(arr) / sizeof(arr[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	cout << contarSumaTres(arr, size) << endl;
	cout << contarSumaTres(arr2, size2) << endl;
}

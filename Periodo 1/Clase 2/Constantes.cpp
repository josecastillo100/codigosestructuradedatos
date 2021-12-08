#include <iostream>
using namespace std;

const int LIGHT_SPEED = 299792458;

int main(){
	cout << LIGHT_SPEED << endl;
	LIGHT_SPEED = 2500;
	// Error! LIGHT_SPEED  es una constante
	cout << LIGHT_SPEED << endl;
}


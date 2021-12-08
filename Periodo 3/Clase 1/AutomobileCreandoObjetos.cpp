#include <iostream>

using namespace std;

class Automobile {
	public: // public functions
		Automobile(); // constructor
		void Input();// mutador
		void set_NumDoors ( int doors );// mutador
		void Display() const;// accesor
		int get_NumDoors() const;// accesor
	private: // private data
		string Make;
		int	NumDoors;
		int	NumCylinders;
		int	EngineSize;
};

int main() {
	Automobile myCar;
	
	myCar.set_NumDoors(4);
	cout << "Enter all data for an automobile :";
	myCar.Input();
	cout << "This is what you entered :";
	myCar.Display();
	cout << "This car has "	<<	myCar.get_NumDoors() << " doors \n";
	
	return 0;
}

Automobile::Automobile()
{
	NumDoors = 0;
	NumCylinders = 0;
	EngineSize = 0;
}

void Automobile::Display() const
{
	cout << "Make : " << Make
	<< ", Doors : " << NumDoors
	<< ", Cyl : " << NumCylinders
	<< ", Engine : " << EngineSize
	<< endl;
}

void Automobile::Input()
{
	cout << "Enter the make: ";
	cin >> Make;
	cout << "How many doors? ";
	cin >> NumDoors;
	cout << "How many cylinders? ";
	cin >> NumCylinders;
	cout << "What size engine? ";
	cin >> EngineSize;
}

void Automobile::set_NumDoors ( int doors ){
	NumDoors = doors;
}

int Automobile::get_NumDoors() const{
	return NumDoors;
}


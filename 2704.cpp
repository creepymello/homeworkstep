#include <iostream>

using namespace std;


struct boiler
{
	char company[50];
	char color[15];
	double power;
	double capacity;
	double temp;
};


int main() {
	boiler B;

	cout << "company: "; cin >> B.company; 
	cout << "color: "; cin >> B.color; 
	cout << "power:"; cin >> B.power; 
	cout << "capacity: "; cin >> B.capacity;
	cout << "temperature: "; cin >> B.temp; 

	cout << "company: " << B.company << endl
		<< "color: " << B.color << endl
		<< "power: " << B.power << endl
		<< "capacity: " << B.capacity << endl
		<< "temperature: " << B.temp << endl;





	return 0;
}
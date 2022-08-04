//DESTRUCTOR
//clears out memory occupied by object
//automatically called when obj goes out of scope; eg obj created inside a function is destroyed once control goes out of function

//shallow copy vs deep copy
//need for creating own copy constructor rather than default
//if any dynamic allocation inside constructor; default constructor copies everything; it will copy the address of dynamic allocated member value as well;
//i.e member variable in different object is being pointed to same address now; so change will affect in all
#include<iostream>
using namespace std;

class Car {
private:
	float price;
public:
	int model_no;
	char *name;

	void setPrice(float p) {
		float msp = 11;
		if (p > 0) {
			price = p;
		}
		else
			price = msp;
	}

	void print() {
		cout << "name: " << name << endl;
		cout << "model no. : " << model_no << endl;
		cout << "price : " << price << endl;
	}


	Car() {
		name = NULL;
	}

	Car(int m, float p, char *n) {
		price = p;
		model_no = m;
		name = new char[strlen(n) + 1]; //+1 for \0
		strcpy(name, n);
	}

	//DESTRUCTOR overloaded
	~Car() {

		cout << "inside destructor for model_no: " << model_no << endl;
		//need to define own destructo to destroy dynamically created variable
		if (name != NULL) {
			delete [] name;
		}
	}

};

int main(int argc, char const *argv[])
{
	Car c(12355, 200, "BMW");

	cout << "Car c" << endl;
	c.print();

	Car e(c);
	e.model_no = 12;
	cout << "Car c" << endl;
	e.print();

	//DESTRUCTOR CALLED IN THE ORDER OF CREATION STACK
	//poping the top

	//to force delete dnamically created object use below
	Car *d = new Car(1221, 190, "ferrari");
	d->print(); //ptr need to be called like this
	//dynamic obj d doesn't gets destroyed automatically
	//use below
	//comment ot see difference
	delete d;

	return 0;
}



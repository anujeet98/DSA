//COPY ASSIGNMENT OPERATOR
//COPIES WHEN YOU DO ASSIGNMENT
//car d = c; //calls copy constructor

//below doesn't call copy constructor
//it is COPY ASSIGNMENT OPERATOR
//Car d;
//d=c;
//it suffers from shallow copy problem can create own cppy assignment operator to make deep copy


//shallow copy vs deep copy
//need for creating own copy constructor rather than default
//if any dynamic allocation inside constructor; default constructor copies everything; it will copy the address of dynamic allocated member value as well;
//i.e member variable in different object is being pointed to same address now; so change will affect in all
//ADVANTAGE OF COPY ASSIGNMENT : CONSTRUCTOR CAN BE CALLED ONLY ONCE WHILE ASSIGNMENT OPERATOR CAN BE USED MANY TIME
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
		//dynamicly created member variable
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	//DEEP COPY; thus need to create own copy constr rather than default to avoid shallow copy problem when dynamic memory allocation is used
	//UNCOMMENT to SEE DEEP COPY EFFECT
	Car(Car &x) {
		cout << "inside copy constr to check deep copy not called when used assignment operator" << endl;
		price = x.price;
		model_no = x.model_no;
		name = new char[strlen(x.name) + 1]; //avoid name=x.name as done in default copy constructor
		strcpy(name, x.name);
	}


	//COMMENT out below to see difference
	void operator=(Car &x) {
		cout << "inside copy own overloaded copy assignment operator" << endl;
		price = x.price;
		model_no = x.model_no;
		//to make deep copy
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}
};

int main(int argc, char const *argv[])
{
	Car c(12355, 200, "BMW");
	//Car d(c);  //this calls own copy constr
	//COMMENT out operator= to see difference
	Car d;
	d = c; //this is copy assgn operator so, doesn't calls copy constr// need to create own cpy assgn operator to overload default cpy assgn operator

	d.name[0] = 'A';
	d.setPrice(120);


	cout << "Car c" << endl;
	c.print();
	cout << "Car d" << endl;
	d.print();

	//to solve this instead of shallow create a deep copy; i.e leave dynamic values : allocate new memory and copy it; other variable copy as it is
	//thus we need to create own copy constructor (this is copy constructor need i.e to avoid shallow copy due to default copy constructor)
	//DEEP COPY; UNCOMMENT COPY CONSTRUCTOR PART TO SEE DEEP COPY EFFECT
	return 0;
}



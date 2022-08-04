#include<iostream>
using namespace std;


//creating does't allocate memory; class is just a blueprint; while object is stored in memory
//equivalent to definig a new datatype for the compiler
//contains  1) datamember; 2) function
class Car {
private:
	float price; //making private ; can't be accessed(read/write) outside class eg main; only access using getter/setter/member functions
public:
	int model_no;
	char name[20];

	float getPrice() {
		return price;
	}

	void setPrice(float p) {
		float msp = 11;
		if (p > 0) {
			price = p;
		}
		else
			price = msp;
	}



	void print() {
		//print is member function ; inside class so don't need getters
		cout << "name: " << name << endl;
		cout << "model no. : " << model_no << endl;
		cout << "price : " << price << endl;

	}

	//member function to get discounted price
	float getDiscountedPrice(float X) {
		return price * (1.0 - X);
	}

	float apply_discountedPrice(float X) {
		price = price * (1.0 - X);
		return price;
	}

	//constructor: same name as constructor
	Car() { //we have overwritten it
		//gets called 3 time as we create 3 object c,d,e
		cout << "inside constructor" << endl;
	}

	//parameterized constructopr
	Car(int m, float p, char *n) {
		price = p;
		model_no = m;
		strcpy(name, n);
	}

	//constructor overloading
	Car(float p) {
		price = p;
	}

	//copy constructor
	//defining default copy constructor code
	//always pass object by reference rather than creating a copy for copy constructor purpose
	Car(Car &x) {   //passing object by reference; why by referencce; instead of creating a copy while passing for copy constructor; compiler wants to have refereence pf that variable rather than creating a copy itself which itself the constructor role is to do
		cout << "inside copy constructor" << endl;

		price = x.price;
		model_no = x.model_no;
		strcpy(name, x.name);
	}
};

int main(int argc, char const *argv[])
{
	//create the object of class
	// c is a variable of type c; it is a bucket ; and would contain monel no, price and name char array
	Car c, d; //makes call to constructor inside class//all car on=bject in different memory and separate bucket
	//another way: Car e = f;
	Car f(12355, 200, "Audi");//called parameteried constructor
	cout << "Car f" << endl;
	f.print();

	//checking default copy constructor
	cout << "Car e" << endl;
	Car e(f);//call to default copy constructor
	e.setPrice(120);
	e.print();


	cout << sizeof(c) << endl; // 2*4(int) + 20*1(char) = 28bytes
	cout << sizeof(Car) << endl; //doesn't create memory; just says amout of sapce that will be required when create a car objrect


//--------------------------------------------------------------

	//set values of attributes using '.'
	//can't directly set private data members; need access modifier functions to access these
	//c.price = 100;
	c.model_no = 111234;
	c.name[0] = 'B';
	c.name[1] = 'M';
	c.name[2] = 'W';
	c.name[3] = '\0';
	//print
	//cout << c.name << " ,Model no.: " << c.model_no << " ,price: " << c.price << endl;
	// cout << "enter the discount to give: ";
	// float perc;
	// cin >> perc;
	//cout << endl << "discounted price: " << c.getDiscountedPrice(perc) << endl;
	//c.apply_discountedPrice(perc);
	c.setPrice(-1);//illegal value corrected in member function restricting direct access to class member variable

	c.print();
	return 0;
}



//some special functn in cpp give you when create a class/obj
//4 diff spec fun that are always preset inside a class
//1) constructor: responsible for creating an object; gets call automatically and only once;
//2) copy constructor: make copy of object; it by default exists
//3) copy assignment operator
//4) destructor
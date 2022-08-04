//initialization list demo
//const helps in debugging process

#include<iostream>
using namespace std;

class Car {
private:
	float price;
public:
	int model_no;
	char *name;
	const int msp; //CONST VARIABLE //READ ONLY VARIABLE //CANOTT WRITE/ASSIGNMENT ON X ie X++ etc

	Car(): msp(99) {
		name = NULL;
		//msp = 4; //<===ASSIGNMENT OF CONST VARIABLE THROWS ERROR
	}

	// Car(const float p) {
	// 	price = p;
	// }

	Car(int m, float p, char *n, int minprice = 99): price(p), msp(minprice) {
		//price = p;  //SETTING PRICE AS INITIALIZATION LIST
		model_no = m;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	Car(Car &x): msp(x.msp) {
		price = x.price;
		model_no = x.model_no;
		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	~Car() {

		cout << "inside destructor for model_no: " << model_no << endl;
		if (name != NULL) {
			delete [] name;
		}
	}

	void setPrice(float p) {
		float msp = 11;
		if (p > 0) {
			price = p;
		}
		else
			price = msp;
	}

	//const function Eg => function doesn't update data members
	float getPrice() const {
		return price;
	}

	void print() {
		cout << "name: " << name << endl;
		cout << "model no. : " << model_no << endl;
		cout << "price : " << price << endl;
	}
};

int main(int argc, char const *argv[])
{
	Car c(12355, 200, "BMW");

	cout << c.msp << endl;

	cout << "Car c" << endl;
	c.print();

	Car e(c);
	e.model_no = 12;
	cout << "Car c" << endl;
	e.print();
	return 0;
}



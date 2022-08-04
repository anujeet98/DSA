#include<iostream>
using namespace std;

void update(int *a){
	//*a: ptr dereferencing
	*a=*a+1; //*a=10; 10+1=11
	cout<<"inside function: "<<*a<<endl;
}

int main()
{
	int x=10;
	update(&x);
	cout<<"Inside main: "<<x<<endl;
	return 0;
}

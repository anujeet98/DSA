#include<iostream>
using namespace std;

string digit_string[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void print_number_string_rec(int number){

	//base condn; if number ==0
	if(number==0){
		//cout<<"zero";
		return;
	} 

	//last digit
	int digit=number%10;
	//call rec functn to print prior digits 
	print_number_string_rec(number/10);
	cout<<digit_string[digit]<<" ";
}

int main(){
	int number;
	cin>>number;
	if(number==0)
		cout<<digit_string[number];
	else
		print_number_string_rec(number);
	return 0;
}

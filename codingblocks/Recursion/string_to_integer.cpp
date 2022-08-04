#include<iostream>
#include<string>
using namespace std;

int convert_str_int(string input_integer, int length){
	if(length==0)
		return 0;
	int last_digit = input_integer[length-1]-'0';
	//solve the remaining string 
	int remaining = convert_str_int(input_integer, length-1);	
	return (remaining*10)+last_digit;
}

int main(){
	string input_integer="5467";
	//cin>>input_integer;
	int len=input_integer.length();
	int result=convert_str_int(input_integer, len);
	cout<<result<<endl;
	return 0;
}

//Remove consecutive duplicate character
//https://online.codingblocks.com/app/player/239418/content/224368/12557/lecture
#include<iostream>
using namespace std;

int main(){
	string a;
	int N;
	cin>>N;

	after integer input N taking string from cin takes \n as new input
	cin.get();
	cin.ignore();

	getline(cin,a);
	cout<<a<<endl;

	// cin.getline(a, 1000);
	// char b[1000];
	// cin.getline(b, 1000);
	// if(compare_str(a,b))
	// 	cout<<"Match"<<endl;
	// else
	// 	cout<<"No match"<<endl;
	// longest_K_Unq_Char_SubStr(a,b);
}

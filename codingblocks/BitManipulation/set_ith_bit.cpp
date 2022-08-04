#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	cin>>i;
	int mask=1<<i;
	cout<<(n | mask)<<endl;

	//n->5: 00101
	//i=3
	//mask->01000
	//n|mask->01101 :13
}
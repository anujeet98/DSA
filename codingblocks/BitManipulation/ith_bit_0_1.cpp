#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	cin>>i;
	int mask=1<<i;
	if((n & mask)>0)
		cout<<"ith bit is 1"<<endl;
	else
		cout<<"ith bit is 0"<<endl;
}
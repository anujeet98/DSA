#include<iostream>
using namespace std;

bool isPrime(int n){
	if(n==1)
		return false;
	if(n==2)
		return true;
	//i<n i.e 2.....n-1 O(n)
	//better way i<sqrt(n) or i*i<n  i.e 2......sqrt(n)  O(sqrt(n))
	for(int i=2; i*i<n; i++){
		if(n%i==0)
			return false;
	}
	return true;
}

//optimised sieve approach

int main(){
	int n;
	cin>>n;
	if(isPrime(n))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}

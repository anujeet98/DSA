#include<iostream>
using namespace std;

int fibonacci_rec(int n){
	if(n==0 || n==1)
		return n;

	return fibonacci_rec(n-1)+fibonacci_rec(n-2);
}
int main(){
	int n;
	cin>>n;
	cout<<fibonacci_rec(n)<<endl;;
	return 0;
}

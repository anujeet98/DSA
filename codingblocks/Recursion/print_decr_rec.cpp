#include<iostream>
using namespace std;

void print_decr_rec(int n){
	if(n==0)
		return;
	cout<<n<<" ";
	print_decr_rec(n-1);
}

int main(){
	int n;
	cin>>n;
	print_decr_rec(n);
 	return 0;
}

#include<iostream>
using namespace std;

void print_decr_rec(int n){
	if(n==0)
		return;
	//swap below 2 instrn to make it increasing order
	print_decr_rec(n-1);
	cout<<n<<" ";
}

int main(){
	int n;
	cin>>n;
	print_decr_rec(n);
 	return 0;
}

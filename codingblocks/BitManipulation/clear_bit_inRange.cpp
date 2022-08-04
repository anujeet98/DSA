#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	cin>>i;
	int j;
	cin>>j;

	//clear bit in range [j,i) i not include
	//will need mask 11111000111 0s in range part
	//to get we need 2 mask as intermediate to get final mask

	int maskA=(~0);
	maskA=maskA<<j;

	//maskA = 111100000  0 till jth index

	//int maskB=(int)pow(2,i)-1;
	//better way
	int maskB=(1<<i)-1;
	//mask b eg i=2;  2^2-1 = 3->000111

	int mask=(maskA | maskB);

	cout<<(mask & n);
}
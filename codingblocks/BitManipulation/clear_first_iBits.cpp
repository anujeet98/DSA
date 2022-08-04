#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	cin>>i;

	//first create a mask of all 0 bits; i.e all bit as 0

	//take not of mask i.e all bits becomes 1

	//mask = (~mask);

	int mask = (~0);//shortcut direct get mask

	//now left shift mask till ith position

	mask=mask<<i;

	//now take n AND mask
	cout<<(n & mask)<<endl;

	//n->5: 00101
	//i=3
	//mask->01000
	//n|mask->01101 :13
}
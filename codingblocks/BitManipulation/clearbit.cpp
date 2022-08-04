#include<iostream>
using namespace std;
void clearBit(int &n,int i){
	int mask=(1<<i);
	mask=(~mask);
	n=(n & mask);
}

void updateBit(int &n,int v,int i){
	int mask=(1<<i);
	mask=(~mask);
	n=(n & mask);

	n = n | (v << i);
}

int main(){
	int n=10;
	// int i=3;
	//clearBit(n,i);
	//updateBit(n,0,3); //o/p->2
	updateBit(n,1,3); //o/p->10
	cout<<n<<endl;
	return 0;
}

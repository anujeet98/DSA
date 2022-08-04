#include<iostream>
using namespace std;

void clearBitRange(int &n,int j,int i){
	int maskA=(~0);
	maskA=(maskA<<j);
	int maskB=(1<<i)-1;
	int mask=(maskA | maskB);
	n=(n & mask);
}



int main(){
	int n,m;
	cin>>n>>m;
	int i,j;
	cin>>i>>j;


	//clear bit in range [j,i) in n
	clearBitRange(n,j,i);
	//update m by left shifting to correct position
	m=(m<<(i-1));
	//take AND of updated M and N
	n=(n | m);
	cout<<n<<endl;
}
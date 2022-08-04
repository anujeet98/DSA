#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int mask=1;
	int count=0;
	while(n!=0){
		if(n & mask)
			count++;
		n=n>>1;
	}
	cout<<count<<endl;

	//get LSb
	//if 1 count++;
	//right shift n by 1
	//now check for next LSB
	//do this till n becomes 0 i.e all bits moved to LSB and got checked 
}
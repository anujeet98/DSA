#include<iostream>
using namespace std;

int find_power_rec(int base, int exp){
	if(exp==0)
		return 1;
	return base*find_power_rec(base,exp-1);
}
int main(){
	int base;
	int exp;
	cin>>base>>exp;
	cout<<find_power_rec(base,exp)<<endl;
	return 0;	
}

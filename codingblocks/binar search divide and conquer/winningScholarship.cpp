#include<iostream>
#define li long int
using namespace std;

int solve(li N,li M,li X,li Y){
	li start=0; //0student to get 100% scholarship
	li end=N; //N ''    ''       ''     ''
	li mid;
	li ans=0;
	while(start<=end){
		mid=(start+end)/2;
		li reqCupons = mid*X; //req cupons for mid students
		li available_cupons = M + (N-mid)*Y; //available = M cupons + (N-M)Y <--bad performer(not getting cupon) are N-mid

		if(reqCupons <= available_cupons){
			ans=mid;
			start=mid+1;   //to maximise check for next mid ahead of previous
		}
		else
			end=mid-1;

	}
	return ans;
}

int main(){
	li N,M,X,Y;
	cin>>N>>M>>X>>Y;
	cout<<solve(N,M,X,Y);
	return 0;
}

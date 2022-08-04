// Chef prepared two dishes yesterday. Chef had assigned the tastiness T1 and T2 to the first and to the second dish respectively. The tastiness of the dishes can be any integer between 0 and N (both inclusive).

// Unfortunately, Chef has forgotten the values of T1 and T2 that he had assigned to the dishes. However, he remembers the sum of the tastiness of both the dishes - denoted by S.

// Chef wonders, what can be the maximum possible absolute difference between the tastiness of the two dishes. Can you help the Chef in finding the maximum absolute difference?

// It is guaranteed that at least one pair {T1,T2} exist such that T1+T2=S,0≤T1,T2≤N.

// https://www.codechef.com/LP1TO201/problems/MAX_DIFF
#include<iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	int N,S;
	while(T--){
		cin>>N>>S;
		if(S<=N)
			cout<<S<<endl; //S-0 always 
		else
			cout<<2*N-S<<endl;//N-(S-N)
	}
	return 0;
}

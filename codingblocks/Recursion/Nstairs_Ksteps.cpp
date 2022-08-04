#include<iostream>
using namespace std;

int Nstairs_Ksteps(int N, int K){
	//standing on 0th stair will be only one way, no other way
	//-ve stairs rem has no ways
	if(N==0)
		return 1;
	if(N<0)
		return 0;

	// if(N==2)
	// 	return 2;
	// if(N==3)
	// 	return 4;
	int ways=0;
	for(int i=1;i<=K;i++){
		ways+=Nstairs_Ksteps(N-i,K);
	}
	return ways;
}

int main(){
	int N,K;
	cin>>N>>K;
	cout<<Nstairs_Ksteps(N,K);
	return 0;
}


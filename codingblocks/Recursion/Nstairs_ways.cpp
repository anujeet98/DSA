#include<iostream>
using namespace std;

int Nstairs(int N){
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
	return Nstairs(N-1) + Nstairs(N-2) + Nstairs(N-3);
}

int main(){
	int N;
	cin>>N;
	cout<<Nstairs(N);
	return 0;
}


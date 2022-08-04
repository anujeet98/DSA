#include<iostream>
using namespace std;

int count_ways(int N, int prev){

	//base case
	if(N==0)
		return 1;
	int ways=0;
	if(prev==0)
		ways=count_ways(N-1,1)+count_ways(N-1,0);//since prev digit was 0 we can take next digit 0/1(becomes prev for next rec call) and check for smaller part
	else
		ways=count_ways(N-1,0);//if(!=0 ie prev=1 then we can only chose 0)
	return ways;
}

int main(){
	int N;
	//length of bin string req
	cin>>N;
	cout<<count_ways(N,0);//passing prev as 0; i.e 1st eleme can pick anything 0/1
	return 0;
}


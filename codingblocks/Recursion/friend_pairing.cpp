#include<iostream>
using namespace std;

int count_ways(int N){

	//base case only  1/0 member. can always have only one was for this case
	if(N<=1)
		return 1;

	//if wants to go single, find using rec taking 1 person out
	//ways+=count_ways(N-1);

	//if wants to go as couple i.e can pair with N-1 people , find using rec by taking couple out for remaining people
	//(n-1)C1 * f(n-2)   out of N-1 person chose 1 to couple with current and call for solve for remaining n-2 people
	// for(int i=1;i<=N-1;i++){
	// 	ways+=count_ways(N-2);
	// }

	//above for loop is basically doing (n-1)* count_ways(n-1)
	return count_ways(N-1) + ((N-1) * count_ways(N-2));
}

int main(){
	int N;
	//length of bin string req
	cin>>N;
	cout<<count_ways(N);//passing prev as 0; i.e 1st eleme can pick anything 0/1
	return 0;
}


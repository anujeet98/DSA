//given wall of size 4*N
//given tiles of size 1*4 or 4*1
//how many ways these tiles can be placed
// _____________________________ ^
// | 							| |
// |							| |4
// |							| |
// |___________________________| v
// <----------- N ------------->
//if place vertical tile 1 tile and N-1 remaining length will be remaining 
//if horizontal tile 4 space length taken and 4tiles stacked one above other. so remaining n-4 length to be filled
//if 3/2/1/0 length remaining then we can arrange 3/2/1/0 vertical tiles i.e only one way
//4 length remaining can be filled using 2 ways either horiz or vertical. and solve remaining length in recurrence

int place_tile(int N){
	if(N<=3)
		return 1;
	//ways = place tile horz (takes 1 length space) + place tile vertically(takes 4 length space)
	//cal recurence on remaining length
	int ways=place_tile(N-1) + place_tile(N-4);
	return ways;
}

#include<iostream>
using namespace std;

int main(){
	int N;
	cin>>N;
	cout<<place_tile(N);
	return 0;
}

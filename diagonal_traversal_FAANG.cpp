//diagonal traversal of 2d matrix FAANG
//https://online.codingblocks.com/app/player/239418/content/224355/8438/code-challenge

#include<iostream>
using namespace std;
int main() {
	int M,N;
	cin>>M>>N;
	int arr[M][N];
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<endl;
		}
	}
	int i=0;
	int j=0;
	int round=-1;
	bool is_boundary_hit=true;
	while((i<=M-1) && (j<=N-1)){
		cout<<arr[i][j]<<" ";
		if(is_boundary_hit){
			if(j==N-1){
				i++;
			}
			else if(i==0){
				j++;
			}
			else if(i==M-1){
				j++;
			}
			else if(j==0){
				i++;
			}
			is_boundary_hit=false;
			round++;
			if(round==2)
				round=0;
		}
		else{
			if(round==0){
				i++;
				j--;
			}
			else{
				i--;
				j++;
			}
			if(i==0 || i==M-1 || j==0 || j==N-1)
				is_boundary_hit=true;
		}
	}
	return 0;
}


// Given an array of M x N elements (M rows, N columns), return all elements of the array in diagonal order .

// Input Format
// Two integers M(row) and N(column) and Second line contains N*M space separated integers denoting the elements of Array.

// Constraints
// The total number of elements of the given array will not exceed 10,000.

// Output Format
// display Diagonal

// Sample Input
// 3 3
// 1 2 3 4 5 6 7 8 9
// Sample Output
// 1 2 4 7 5 3 6 8 9 
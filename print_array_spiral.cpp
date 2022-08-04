//print array spiral pattern

#include<iostream>
using namespace std;

void print_spiral(int arr[][100],int M,int N){
	int sr=0,sc=0,er=M-1,ec=N-1;
	while(sr<=er && sc<=ec){
		for(int i=sr;i<=er;i++){
			cout<<arr[i][sc]<<", ";
		}
		sc++;
		for(int i=sc;i<=ec;i++){
			cout<<arr[er][i]<<", ";
		}
		er--;
		for(int i=er;i>=sr;i--){
			cout<<arr[i][ec]<<", ";
		}
		ec--;
		for(int i=ec;i>=sc;i--){
			cout<<arr[sr][i]<<", ";
		}
		sr++;
	}
	cout<<"END";
	return;
}

int main(){
	int M,N;
	cin>>M>>N;
	int arr[100][100];
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	print_spiral(arr,M,N);
	return 0;
}

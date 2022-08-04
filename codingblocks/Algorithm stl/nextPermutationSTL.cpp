//next_permutation() 
#include<iostream>
#include<algorithm>//to use find,binary_search,
using namespace std;

int main(){
	int arr[]={1,2,3};
	//int arr[]={2,1,3}; from 2,1,3
	int n=sizeof(arr)/sizeof(arr[0]);

	//can print all permutaion using this do while loop
	do{
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}while(next_permutation(arr,arr+n)==true);

}

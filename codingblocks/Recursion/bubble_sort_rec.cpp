//bubble sort 
//recursion: break bigger problem int smaller problem
//every iteration largest element gets at end that is correct position
//use recursion to solve for remaining elements

#include<iostream>
using namespace std;

void bubble_sort_rec(int *arr, int n){
	if(n<=1)
		return;
	//below iteration will set the largest value at the end
	for(int i=0;i<n-1;i++){
		if(arr[i]>arr[i+1]){
			//swap
			int temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=temp;
		}
	}

	//use recursion to sort for remaining elements except the last element in curr array;
	bubble_sort_rec(arr, n-1);
}

int main(){
	int arr[]={2,4,1,46,23,44,12,33,56,78,23,12,44,55,44,23,89,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubble_sort_rec(arr,n);

	//after sorting
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}


	return 0;
}

#include<iostream>
using namespace std;

bool isSorted_rec(int *arr, int arr_size){
	if(arr_size==1 || arr_size==0)
		return true;
	bool isSorted_smaller=isSorted_rec(arr+1,arr_size-1);
	if(arr[0]<=arr[1] && isSorted_smaller)
		return true;
	else
		return false;
}

bool isSorted_rec_iterator(int *arr, int arr_size, int iter){
	if(iter==arr_size-1)
		return true;
	bool isSorted_smaller=isSorted_rec_iterator(arr,arr_size,iter+1);
	if(arr[iter]<=arr[iter+1] && isSorted_smaller)
		return true;
	else
		return false;
}

int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,11,13,17,45,122,223};
	//unsorted test
	//int arr[]={1,2,3,4,5,6,7,8,9,11,13,17,45,322,223};
	int arr_size=sizeof(arr)/sizeof(int);

	if(isSorted_rec_iterator(arr,arr_size,0))
		cout<<"sorted"<<endl;
	else
		cout<<"unsorted"<<endl;

	//without iterator
	// if(isSorted_rec(arr,arr_size))
	// 	cout<<"sorted"<<endl;
	// else
	// 	cout<<"unsorted"<<endl;
	return 0;
}

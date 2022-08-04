#include<iostream>
using namespace std;

void merge(int *arr, int start, int end){

	//copy arr to be merge to separate array: copy_arr
	int size = end - start + 1;
	int copy_arr[size];
	for(int i=0 ; i<size ; i++){
		copy_arr[i] = arr[start + i];
	}


	//from copy_arr add elements in sorted order back to arr
	int i=0;
	int mid=(size-1)/2;
	int j=mid+1;

	int index=start;


	//compare index i and index j in copy_arr and sort the eleme in order into arr from start-end
	//do increment of index and i/j
	while(i<=mid && j<size){
		if(copy_arr[i] < copy_arr[j])
			arr[index++] = copy_arr[i++];
		else
			arr[index++] = copy_arr[j++];
	}

	//add the remaining i or j elem

	while(i<=mid){
		arr[index++] = copy_arr[i++];
	}
	while(j<size){
		arr[index++] = copy_arr[j++];
	}
}


void merge_sort(int *arr,int start,int end){
	int mid=(start+end)/2;

	//when only 1 element or start overshoots end
	if(start>=end)
		return;

	merge_sort(arr,start,mid);
	merge_sort(arr,mid+1,end);

	merge(arr,start,end);
}

int main(){
	int arr[]={2,4,1,46,23,44,12,33,56,78,23,12,44,55,44,23,89,10};
	int n=sizeof(arr)/sizeof(arr[0]);

	//before sorting

	cout<<"before"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	merge_sort(arr,0,n);

	//after sorting
	cout<<endl<<"final after sorting"<<endl; 
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}


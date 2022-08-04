#include<iostream>
#include<algorithm>
using namespace std;

int partition(int *arr,int start,int end){
	int i=start-1;//last element of segment 1(elments containing <=pivot)
	int pivot=end-1;

	for(int j=start; j<pivot; j++){
		if(arr[j] < arr[pivot]){
			//if less move it to segment 1 i.e i+1th place; currnt i+1th is seg 2 element
			//so swap jth and i+1th. now jth comes to seg 1 and prev i+1th goes in place of j as seg2 loc
			i++;
			swap(arr[i],arr[j]);
		}
	}

	//after arranging pivot i.e eleme to left are smaller than pivot and right are greater than
	//2 segment created. move pivot to i+1th pos i.e swap i+t with pivot
	swap(arr[i+1],arr[pivot]);
	//update pivot position
	pivot=i+1;

	return pivot;
}


void quick_sort(int *arr,int start,int end){
	//when only 1 element or start overshoots end
	if(start>=end)
		return;
	//partition and put pivot in correct position
	int pivot=partition(arr,start,end);
	//call functn to arrange further smaller arr/seg1&2 by chosing respt pivot
	quick_sort(arr,start,pivot);
	quick_sort(arr,pivot+1,end);
}

int main(){
	int arr[]={2,4,1,46,23,44,12,33,56,78,23,12,44,55,44,23,89,10,0};
	int n=sizeof(arr)/sizeof(arr[0]);

	//before sorting

	cout<<"before"<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	quick_sort(arr,0,n);

	//after sorting
	cout<<endl<<"final after sorting"<<endl; 
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}


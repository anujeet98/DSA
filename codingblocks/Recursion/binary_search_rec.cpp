#include<iostream>
using namespace std;

int bin_search_rec(int arr[], int n, int elem, int start, int end){
	int mid=(start+end)/2;
	if(start>end)
		return -1;
	if(arr[mid]==elem)
		return mid;
	if(elem<arr[mid])
		return bin_search_rec(arr,n,elem,start,mid-1);
	return bin_search_rec(arr,n,elem,mid+1,end);
}

int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,11,13,17,45,122,223};
	int n=sizeof(arr)/sizeof(arr[0]);
	int elem;
	cin>>elem;
	//start=0
	//end=n
	cout<<bin_search_rec(arr,n,elem,0,n);
	return 0;
}

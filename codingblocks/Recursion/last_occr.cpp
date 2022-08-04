//to find last occr of a number, we can recurse from end and find its first occr from end
//m-2 foind last occr from begin. we will do m-2

#include<iostream>
using namespace std;

int last_occr_recur_iter(int *arr, int n, int iter, int x){
	//base condn iterator reaches end of array then x not found ,return -1
	if(iter==n)
		return -1;
	//check for index in later smaller array
	int index_later_smaller_array=last_occr_recur_iter(arr, n, iter+1, x);
	// if current element is x and current iter>index later: return current iter
	if(arr[iter]==x && iter>index_later_smaller_array)
		return iter;
	return index_later_smaller_array;
}

int last_occr_recur(int *arr, int n, int x){

	if(n==0)
		return -1;
	int index_later_smaller_array=last_occr_recur(arr+1, n-1, x);
	if(index_later_smaller_array==-1){
		if(arr[0]!=x)
			return -1;
		else
			return 0;
	}
	return index_later_smaller_array+1;
}

int main(){
	int arr[]={2,4,1,46,23,44,12,33,56,78,23,12,44,55,44,23,89,10};
	int n=sizeof(arr)/sizeof(n);
	int x;
	cin>>x;
	cout<<last_occr_recur_iter(arr,n,0,x);
	// cout<<last_occr_recur(arr,n,x);
	return 0;
}

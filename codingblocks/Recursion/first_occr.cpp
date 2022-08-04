#include<iostream>
using namespace std;

int find_first_occr(int *arr,int n, int x){
	//base condn 0 elements i.e not found so return -1
	if(n==0)
		return -1;

	//assumption if current 1st element is x then return. if not then find in smaller array
	if(arr[0]==x)
		return 0;
	int index=find_first_occr(arr+1,n-1,x);

	//if current 1st element NOT x and smaller array also return -1 ie not present in it. Then return -1
	if(index==-1)
		return -1;
	//else if smaller returns a first occr of X then return index+1 because it will be 1(1st element)+ index(starting from smaller array)
	return index+1;
}

int find_first_occr_iterator(int arr[],int n,int iter,int x){
	if(iter==n)
		return -1;
	if(arr[iter]==x)
		return iter;
	int index=find_first_occr_iterator(arr,n,iter+1,x);
	return index;

}

int main(){
	int arr[]={2,4,1,46,23,44,12,33,56,78,23,12,44,55,44,23,89,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x;
	cin>>x;
	//cout<<find_first_occr(arr,n,x);
	//using iterator
	cout<<find_first_occr_iterator(arr,n,0,x); 
}

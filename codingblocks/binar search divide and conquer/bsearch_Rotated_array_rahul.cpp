#include<iostream>
using namespace std;

int bsearch_Rotated(int arr[], int n, int key){
	int ans=-1;
	int start=0, end=n-1;
	while(start<=end){
		int mid=(start+end)/2;
		if(arr[mid]==key)
			return mid;

		if(arr[mid] >= arr[s]) //lying on first line
		{
			//2 cases, need to check whether element lies on left or right of the mid
			if(arr[s]<=key && key>=arr[mid])
				end=mid-1;
			else
				start=mid+1;
		}
		else{ //mid on second line
			if(arr[mid]<=key && key<=arr[end])
				start=mid+1;
			else
				end=mid-1;
		}
	}
	return ans;
}

int main(){
	int arr[10000]={4,5,1,2,3};
	int key;
	cin>>key;
	int n=sizeof(arr)/sizeof(int);
	cout<<"index: "<<bsearch_Rotated(arr,n,key);
	return 0;
}

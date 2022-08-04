//binary search
#include<iostream>
#include<algorithm>//to use find,binary_search,
using namespace std;

void printarray(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<*(a+i)<<" ";//a[i]
	}
	cout<<endl;
}

int binarySearch(int *a, int n, int key){

	int start=0, end=n-1,mid;
	while(start<=end){
		mid=(start+end)/2;
		if(a[mid]==key)
			return mid;
		if(a[mid]>key)
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
}


int main(){

	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(int);

	printarray(arr,n);

	int key;
	cin>>key;
	cout<<"index: "<<binarySearch(arr,n,key);

}

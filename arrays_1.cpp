#include<iostream>
using namespace std;

int main(){

	int arr[5]={1,2,3,4,5};
	int n=5;

	//size declared 10 and value assigned only 3 => thus remaining initialized to 0 by default
	int arr1[10]={1,2,3};

 	//No size declared => thus takes size from assigned values in initialization
 	//skipping array size can be done in array ONLY at INITIALIZATION
 	//size of array will be taken from elements declared in initialization
	int arr2[]={1,2,3,4,6,7};

	//invalid declaration since size is smaller than declared values
	//int arr[3]={1,2,3,4,5,6};

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		cout<<arr1[i]<<" ";
		cout<<arr2[i]<<endl;
	}

	//accepting values from user after initialization

	int a[100];//can't skip array size when taking user input, only skip at initialization
	cout<<"enter n max 100"<<endl;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}
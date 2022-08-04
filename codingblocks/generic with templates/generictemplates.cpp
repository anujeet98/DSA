#include<iostream>
#include<string>
using namespace std;

template<typename T>
int Search(T arr[], int n, T key){
	for(int i=0;i<n;i++){
		if(arr[i]==key)
			return i;
	}
	return n;
}

int main(){
	int arr1[]={2,5,11,43,65,756,33,54,13};
	string arr2[]={"batman","bat","apple"};

	int n1=sizeof(arr1)/sizeof(int);
	int n2=3;

	string key="bat";

	//woring for both integer array and string array
	cout<<Search(arr1,n1,43)<<endl;
	cout<<Search(arr2,n2,key)<<endl;
}

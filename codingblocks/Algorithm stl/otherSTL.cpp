//rotate(), reverse(),swap(),min(),max() STL 
#include<iostream>
#include<algorithm>//to use find,binary_search,
using namespace std;

void printarray(int *a, int n){
	for(int i=0;i<n;i++){
		cout<<*(a+i)<<" ";//a[i]
	}
	cout<<endl;
}

int main(){

	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(int);

	printarray(arr,n);
	//rotate around an index
	rotate(arr,arr+3,arr+n);
    
	//to reverse array
	reverse(arr,arr+n);

	printarray(arr,n);

	//to swap elements

	int a=10,b=20;
	cout<<a<<" "<<b<<endl;
	swap(a,b);
	cout<<a<<" "<<b<<endl;

	int c=5;
	cout<<min(a,b)<<endl;
	cout<<min(a,min(b,c))<<endl;

	cout<<max(a,max(b,c))<<endl;

}

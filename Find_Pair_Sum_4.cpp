#include<iostream>
using namespace std;

//Question given sorted array and a sum, find pair of elenment with sum equal to the given sum
int main(){
	int a[]={1,4,5,6,8,10};
	int n=sizeof(a)/sizeof(int);

	int sum=0;
	cout<<"enter sum"<<endl;
	cin>>sum;

	//TWO POINTER approach
	int i=0,j=n-1; //i points to first and j to last element

	//when i and j cross or equal to each other stop loop
	while(i<=j){
		if(a[i]+a[j]==sum){    
			cout<<a[i]<<" "<<a[j]<<endl;
			i++;
			j--;
		}
		else if(a[i]+a[j]>sum)   //i.e sum of 2 elements greater than given sum therefore need to decrement j since it is larger value
			j--;
		else
			i++;
	}
	return 0;
}
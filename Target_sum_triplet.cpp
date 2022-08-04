#include<iostream>
#include <algorithm>
using namespace std;

//O(n^2)
void TargetSumTriplets(int a[],int arraySize,int TargetSum){
	for(int i=0;i<arraySize-2;i++){
		int element_2_ptr=i+1;
		int element_3_ptr=arraySize-1;
		while(element_2_ptr < element_3_ptr){
			int sum_2_3 = a[element_2_ptr]+a[element_3_ptr];
			if((sum_2_3 + a[i]) > TargetSum)
				element_3_ptr--;
			else if((sum_2_3 + a[i]) < TargetSum)
				element_2_ptr++;
			else{
				cout<<a[i]<<", "<<a[element_2_ptr]<<" and "<<a[element_3_ptr]<<endl;
				element_2_ptr++;
				element_3_ptr--;
			}
		}
	}
}
int main() {
	int arraySize,TargetSum;
	cin>>arraySize;
	int a[arraySize];
	for(int i=0;i<arraySize;i++){
		cin>>a[i];
	}
	cin>>TargetSum;
	sort(a,a+arraySize);
	TargetSumTriplets(a,arraySize,TargetSum);
	return 0;
}
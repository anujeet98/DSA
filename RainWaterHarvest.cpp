#include<iostream>
using namespace std;

void waterHarvest(int a[],int n){
	int total_water_count=0;
	int left=0,right=0;
	//for every location between 1 and n-1 check for highest block on its left and right
	for(int i=1;i<n-1;i++){
		//finding highest block on left of ith element
		left=a[i];
		for(int j=0;j<i;j++){
			left = max(left,a[j]);
		}
		//finding highest block on right of ith element
		right=a[i];
		for(int j=i+1;j<n;j++){
			right = max(right,a[j]);
		}
		//water containing in ith block will be min height of(left, right) - current ith block height
		total_water_count += (min(left,right)-a[i]);
	}
	cout<<total_water_count<<endl;
}

//optimized code
//precompute finding max height on left and right and store it in array

void waterHarvest_optimized(int a[],int n){
	int total_water_count=0;

	//storing left max block for each block
	int left_max_height_array[n];
	int leftmax=0;
	left_max_height_array[0]=a[0];
	for(int i=1;i<n-1;i++){
		left_max_height_array[i] = max(left_max_height_array[i-1] , a[i]);  //max left height will be max of(current height of ith , maxleftheight of i-th block)
	} 




	int right_max_height_array[n];
	int rightmax=0;
	right_max_height_array[n-1]=a[0];
	for(int i=n-2;i>=0;i--){
		right_max_height_array[i] = max(right_max_height_array[i+1] , a[i]);
	} 


	//for every location between 1 and n-1 check for highest block on its left and right
	for(int i=1;i<n-1;i++){
		//water containing in ith block will be min height of(left, right) - current ith block height
		total_water_count += min(left_max_height_array[i] , right_max_height_array[i]) - a[i];
	} 
	cout<<total_water_count<<endl;
}

void waterHarvest_optimized_alternate(int a[],int n){
	int total_water_count=0;

	//no need to store left max block for each block
	//just precompute max block on right for each ith block and store it in array.
	//can compute on left max in last loop itself


	int right_max_height_array[n];
	int rightmax=0;
	right_max_height_array[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--){
		right_max_height_array[i] = max(right_max_height_array[i+1] , a[i]);
	} 


	//for every location between 1 and n-1 check for highest block on its left and right
	int leftmax=a[0];
	for(int i=1;i<n-1;i++){
		leftmax = max(leftmax,a[i]);
		//water containing in ith block will be min height of(left, right) - current ith block height
		total_water_count += min(leftmax , right_max_height_array[i]) - a[i];
	} 
	cout<<total_water_count<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	waterHarvest_optimized_alternate(a,n);
	return 0;
}
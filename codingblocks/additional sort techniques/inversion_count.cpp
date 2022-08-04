//given array : count the no of pairs where i<j and a[i]>a[j]
//solve using O(n) i.e using divide and conquer technique

//divide ip arr into half, call recursive function to find number of inversion pairs in both(A,B)
//merge the divide arr while building upwards.
//count the inversion pairs in the new merged arr(Z)
//return total count = A+B+Z


#include<iostream>
using namespace std;

int merge_count(int *arr, int start, int end, int mid){
	int count=0;
	int i=start;
	int j=mid+1;
	int k=0;
	int helper_array[end-start+1];
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j])
			helper_array[k++]=arr[i++];
		else{
			helper_array[k++]=arr[j++];
			count+=mid-i+1;
		}

	}
	while(i<=mid)
		helper_array[k++]=arr[i++];
	while(j<=end)
		helper_array[k++]=arr[j++];

	k=0;
	for(int i=start; i<=end; i++){
		arr[i]=helper_array[k++];
	}
	return count;
}



int inversion_count(int *arr, int start, int end){
	int size=end-start+1;
	if(start>=end)
		return 0;
	int mid=(start+end)/2;
	int A = inversion_count(arr, start, mid);
	int B = inversion_count(arr, mid+1, end);
	int Z = merge_count(arr, start, end, mid);
	return A+B+Z;
}



int main(){
	int arr[]={1, 5, 2, 6, 3, 0};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<inversion_count(arr,0,n-1)<<endl;
	return 0;
}

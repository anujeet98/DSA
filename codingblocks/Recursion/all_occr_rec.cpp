#include<iostream>
using namespace std;

//extra
//storing indices/occurance in out arr and print it in main()
int out[100];
int j=0;


//using iterator method
void all_occr_recur_iter(int arr[], int n, int iter, int x){
	if(iter==n)
		return;
	if(arr[iter]==x){
		cout<<iter<<" ";

		//storing indices in out array// extra part just to print in main
		out[j]=iter;
		j++;
	}
	all_occr_recur_iter(arr, n, iter+1, x);
}
int main(){
	int arr[]={2,4,1,46,23,44,12,33,56,78,23,12,44,55,44,23,89,10};
	int n=sizeof(arr)/sizeof(n);
	int x;
	cin>>x;
	all_occr_recur_iter(arr,n,0,x);

	cout<<endl;

	//printing indices stored in out array //extra part
	for(int i=0;i<j;i++){
		cout<<out[i]<<" ";
	}
}

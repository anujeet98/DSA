#include<iostream>
using namespace std;

// int kadane(int a[],int n){
// 	int current_max_sum=0;
// 	int overall_max_sum=0;
// 	for(int i=0;i<n;i++){
// 		current_max_sum = max(current_max_sum , current_max_sum+a[i]);
//   		overall_max_sum=max(overall_max_sum , current_max_sum);
// 	}
// 	return overall_max_sum;
// }

void max_circ_sum_subarray(int a[], int n){

    // Corner Case
    if (n == 1)
        return a[0];

	int total_sum=0;

	int current_max_sum=a[0];
	int overall_max_sum=a[0];

	int current_min_sum=a[0];
	int overall_min_sum=a[0];


	for(int i=0;i<n;i++){
		total_sum+=a[i];

		current_max_sum = max(a[i] , current_max_sum+a[i]);
  		overall_max_sum=max(overall_max_sum , current_max_sum);

  		current_min_sum = min(a[i]  , current_min_sum+a[i]);
  		overall_min_sum=min(overall_min_sum , current_min_sum);


	}
	cout<<max(overall_max_sum , total_sum - overall_min_sum)<<endl;
}

int main(){
	int t,n,Ai;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		max_circ_sum_subarray(a,n);
	}
	return 0;
}

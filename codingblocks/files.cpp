#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int Q;
	cin>>Q;
	int Qi;
	while(Q--){
		cin>>Qi;
		int index_LB=lower_bound(arr,arr+n,Qi)-arr;
		int index_UB=upper_bound(arr,arr+n,Qi)-arr-1;
		if(index_UB>n-1)	index_UB=-1;
		if(index_LB>n-1)	index_LB=-1;
		cout<<index_LB<<" "<<index_UB<<endl;
	}
	return 0;
}

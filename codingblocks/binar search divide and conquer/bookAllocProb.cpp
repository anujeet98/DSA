#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int arr[], int mid, int n, int m){
	int booksToRead=0;
	m--;
	for(int i=0;i<n;i++){
		booksToRead+=arr[i];
		if(booksToRead>mid){
			m--;
			booksToRead=arr[i];
		}
		if(m<0)
			return false;
	}
	return true;
}



int sum_all_pages(int arr[],int n){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	return sum;
}

int BookAlloc(int arr[],int n,int m){
	int ans=-1;
	int start = arr[n-1];
	int end = sum_all_pages(arr,n);
	while(start<=end){
		int mid=(start+end)/2;
		//cout<<start<<" "<<mid<<" "<<end<<endl;
		if(isPossible(arr,mid,n,m)){
			end=mid-1;
			ans=mid;
		}
		else{
			start=mid+1;
		}
	}
	return ans;
}

int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<BookAlloc(arr,n,m)<<endl;
	}
	return 0;
}

90 146 203
90 117 145
90 103 116
104 110 116
111 113 116
111 111 112
112 112 112
113
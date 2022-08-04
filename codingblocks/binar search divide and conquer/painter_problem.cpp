#include<iostream>
#include<algorithm>
#include<climits>
#define ll long long
#define m 10000003

using namespace std;

int numberOfPainters(int arr[], int n, int maxLen) 
{ 
    int total = 0, numPainters = 1; 

    for (int i = 0; i < n; i++) { 
        total += arr[i]; 

        if (total > maxLen) { 

            // for next count 
            total = arr[i]; 
            numPainters++; 
        } 
    } 

    return numPainters; 
} 

int partition(int arr[], int n, int k) 
{ 
    int max_length=INT_MIN;
    int sum_length=0;
    for(int i=0;i<n;i++){
		max_length=max(max_length, arr[i]);
		sum_length=arr[i];
    }
    int lo = max_length; 
    int hi = sum_length; 

    while (lo < hi) { 
        int mid = lo + (hi - lo) / 2; 
        int requiredPainters = numberOfPainters(arr, n, mid); 

        if (requiredPainters <= k) 
            hi = mid; 


        else
            lo = mid + 1; 
    } 

    return lo; 
} 
int main(){
	int N,K,T;
	cin>>N>>K>>T;
	int board_length[N];
	for(int i=0;i<N;i++){
		cin>>board_length[i];
	}
	cout<<(partition(board_length,N,K)*T)%m<<endl;
	return 0;
}

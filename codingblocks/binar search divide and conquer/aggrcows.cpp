#include<iostream>
#include<algorithm>
using namespace std;

bool ispossible(long int arr[], int mid, int n, int c){
    c--;
    int prevCowAt=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[prevCowAt]>=mid){
            c--;
            prevCowAt=i;
        }
        if(c==0)
            return true;
    }
    return false;
}

int fitCows(long int arr[], int n, int c){
    int ans=-1;
    sort(arr,arr+n);
    int start=arr[0];
    int end=arr[n-1]-arr[0];
    while(start<=end){
        int mid=(start+end)/2;
        if(ispossible(arr,mid,n,c)){
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
    }
    return ans;
}

int main() {
    int n,c;
    cin>>n>>c;
    long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<fitCows(arr,n,c);
    return 0;
}
#include<iostream>
#include<algorithm>
#include<math.h>
#define ll long long
using namespace std;

//KTH_root_bsearch.cpp

ll Kth_root(ll K, ll N){
	ll ans=0;
	ll start=0;
	ll end=N;
	ll mid;
	cout<<"p"<<endl;
	while(start<=end){
		mid=(start+end)/2;
		ll val=(ll)pow(mid,K);
		cout<<val<<endl;
		if(val==N)
			return mid;
		if(val>N)
			end=mid-1;
		else{
			ans=mid;
			start=mid+1;
		}
	}
	cout<<"l"<<endl;
	return ans;
}

int main(){
	ll T,K;
	ll N;
	cin>>T;
	while(T--){
		cin>>N>>K;
		cout<<Kth_root(K,N)<<endl;
	}

	return 0;
}

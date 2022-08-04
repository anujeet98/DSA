#include<iostream>
#include<vector>
using  namespace std;

const int N = 100000;
vector<int> primes; //to store all the primes
int p[N] = {0}; //to mark numbers not prime

void sieve(){
	for(int i=2;i<N;i++){
		if(p[i]==0){
			//store i in primes vector
			primes.push_back(i);
			for(int j = i*i ; j<=N ; j+=i){
				p[j]=1; //not prime
			}
		}
	}
}

int main(){
	sieve(); //build this sieve once for all

	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>m>>n;

		bool segment[n-m+1];
		for(int i=0; i<n-m+1; i++){
			segment[i] = 0;
		}

		for(auto x:primes){
			if(x*x>n){
				break;
			}

			int start = (m/x)*x;

			if(x>=m and x<=n){
				start = x*2; 
			}

			for(int i=start; i<=n; i+=x){				
				segment[i-m]=1;
			}
		}
		for(int i=m; i<=n; i++){
			if(segment[i-m]==0 and i!=1){
				cout<<i<<endl;
			}
			cout<<endl;
		}
	}
}



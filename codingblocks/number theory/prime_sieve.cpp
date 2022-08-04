#include<iostream>
#define ll long long
using namespace std; 	 	

//limitation : upto 10^7
void prime_sieve(int *arr){
	//make all odd numbers as prime i.e eliminating all even numbers
	for(int i=3;i<=1000005;i+=2){
		arr[i]=1;
	}
	//iterate over all odd numbers and remove its multiples in the range i.e mark it as not prime
	for(ll i=3;i<=1000000;i+=2){
		if(arr[i]==1){
			for(ll j=i*i; j<1000005; j+=i){
				arr[j]=0;
			}
		}
	}	
	//special case
	//mark 0 and 1 as not prime (not required since already 0)
	//mark 2 as prime
	arr[2]=1;
	arr[0]=arr[1]=0;
}


int main(){
	// int n;
	// cin>>n;
	

	int arr[100005]={0};
	//int arr[10]={0};

	//find all prime sieve in the range of arr
	prime_sieve(arr);

	//print all n primes

	// for(int i=0;i<=n;i++){
	// 	if(arr[i]==1)
	// 		cout<<i<<", ";
	// }

	//make cumulative sum arr 
	int csum[100005]={0};
	for(int i=1;i<100005;i++){
		csum[i]=csum[i-1]+arr[i];
	}

	int Q;
	cin>>Q;
	while(Q--){
		int a,b;
		cin>>a>>b;
		cout<<csum[b]-csum[a-1]<<endl;
	}



	return 0;
}

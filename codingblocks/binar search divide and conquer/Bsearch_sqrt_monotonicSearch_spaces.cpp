#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int start=0;
	int end=n;
	float ans=-1;
	while(start<=end){
		int mid=(start+end)/2;
		if(mid*mid==n){
			ans=mid;
			break;
		}
		if(mid*mid>n)
			end=mid-1;
		else{
			ans=mid;
			start=mid+1;
		}
	}

	//to get with floating point values i.e exact sqrt
	//let p be decimal space required

	int p=5;
	float incr=0.1;
	for(int i=1;i<=p;i++){
		while((ans * ans)<=n){
			ans=ans+incr;
		}
		ans=ans-incr;
		incr/=10;
	}





	cout<<"sqrt of "<<n<<" : "<<ans<<endl;
	return 0;
}

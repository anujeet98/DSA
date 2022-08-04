#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int cnt_bits[64]={0};
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		int pos=0;

		while(num>0){
			if((num & 1)>0)
				cnt_bits[pos]++;
			num=num>>1;
			pos++;
		}
	}

	int ans=0;
	int power=1;
	for(int i=0;i<64;i++){
		int bit=cnt_bits[i]%3;
		ans+=bit*power;
		power*=2;
	}
	cout<<ans<<endl;
	return 0;
}
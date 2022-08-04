#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	int result=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		result=(result ^ arr[i]);
	}
	
	int pos=0;
	int resultAxorB=result;
	while(resultAxorB>0){
		if((resultAxorB & 1)==1)
			break;
		pos++;
		resultAxorB>>1;
	}
	int mask=1<<pos;

	int uniq1=0;
	for(int i=0;i<n;i++){
		if((arr[i] & mask)>0)
			uniq1=(uniq1 ^ arr[i]);
			//cout<<arr[i]<<" "<<uniq1<<endl;
	}

	int uniq2=result^uniq1;

	uniq1=min(uniq1,uniq2);

	cout<<uniq1<<" "<<(result^uniq1)<<endl;

	return 0;
}
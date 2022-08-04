#include<iostream>
#include<climits>
using namespace std;
int main() {
	int maxvalue=INT_MIN;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxvalue=max(a[i],maxvalue);
	}
	cout<<maxvalue<<endl;
	return 0;
}
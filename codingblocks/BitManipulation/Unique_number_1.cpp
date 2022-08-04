#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int uniq=0;
	while(n--){
		int a;
		cin>>a;
		uniq = (uniq ^ a);
	}
	cout<<uniq<<endl;
	return 0;
}
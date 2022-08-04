//https://www.codechef.com/START28D/problems/PERMXORITY

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	int n;
	cin>>T;
	while(T--){
	    cin>>n;
        if(n==2){
            cout<<"-1"<<endl;
            continue;
        }
        if(n%2!=0){
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }
        cout<<"2 3 1 ";
        for(int i=4;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
	}
	return 0;
}
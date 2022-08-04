//coin change problem
#include<iostream>
#include<algorithm>//to use find,binary_search,
using namespace std;

bool compare(int a,int b){
	return a<=b;
}

int main(){
	//int arr[]={2,5,7,12,12,54,12,98};
	int denomination[]={1,2,5,10,20,50};
	int n=sizeof(denomination)/sizeof(denomination[0]);

	int money;
	cin>>money;

	int change_count=0;

	//cout<<money<<endl;
	while(money>0){
		int *addr=lower_bound(denomination,denomination+n,money,compare);//og gives >=key, modify by adding compare-> now, <=key(modified Lower_bound())
		int index=addr-denomination-1;
		//cout<<index<<endl;
		int change=denomination[index];
		// if(denomination[index]>money)
		// 	change=denomination[index-1];
		// else
		// 	change=denomination[index];
		change_count++;

		money-=change;

	}
	cout<<change_count<<endl;

}

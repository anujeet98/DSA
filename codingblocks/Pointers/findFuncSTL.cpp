//Algorithms STL find function
#include<iostream>
#include<algorithm>//to use find,binary_search
using namespace std;

int main(){
	int arr[]={2,5,7,12,34,54,77,98};
	int n=sizeof(arr)/sizeof(arr[0]);

	int key;
	cin>>key;
	int *ptr=find(arr,arr+n,key);
	int index=ptr-arr;

	cout<<ptr<<endl;
	if(index==n)//4=sizeof int
		cout<<"not found"<<endl;;
	else
		cout<<"found at "<<index<<endl;

	cin>>key;
	bool present=binary_search(arr,arr+n,key);
	if(present)
		cout<<"found "<<endl;
	else
		cout<<"not found"<<endl;
}

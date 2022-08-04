//Algorithms STL lower bound/upper bound function
#include<iostream>
#include<algorithm>//to use find,binary_search,lower_bound() and upper_b...()
using namespace std;

int main(){
	//int arr[]={2,5,7,12,12,54,12,98};
	int arr[]={10,20,40,40,40,50};
	int n=sizeof(arr)/sizeof(arr[0]);

	int key;
	cin>>key;
	int *ptr=lower_bound(arr,arr+n,key);//return address of value(1st occurance) >=key, also obtain 1st occurance of KEY
	cout<<"value: "<<*ptr<<endl;//address 
	cout<<"1st occurance of key: "<<ptr-arr<<endl;//ptr addr - arr(addr of 0th index) -> index of element pointed by ptr

	int *ans=upper_bound(arr,arr+n,key); //returns addr having value(1st occurance) >key, also obtain last occurance of key
	cout<<"last occurance of key: "<<ans-arr-1<<endl;//index of last occurance of key (sub 1 to get it)



//to find no of occurance of key


	sort(arr,arr+n);//to get occurance of key, only possible after sorting.
	cout<<"number of occurance of key: "<<ans-ptr<<endl;
}

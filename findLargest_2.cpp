#include<iostream>
#include<climits> //for INT_MIN and INT_MAX
using namespace std;

int main()
{
	int arr[5]={3,5,1,12,8};
	int max_value=INT_MIN; //INT_MIN=-2^31
 	int arr_size=5;
	for(int i=0;i<arr_size;i++){
		if(arr[i]>max_value)
			max_value=arr[i];
	}
	cout<<"largest value = "<<max_value<<endl;
	return 0;
}
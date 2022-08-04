#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
bool compare(int a,int b){
	int digits_a = (int)log10(a)+1;
	int digits_b = (int)log10(b)+1;

	long long int ab = a*round(pow(10,digits_b)) + b;
	long long int ba = b*round(pow(10,digits_a)) + a;

	if(ab>ba)
		return 1;
	else
		return 0;

}
int main() {
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n,compare);
		for(int i=0;i<n;i++){
			cout<<arr[i];
		}
		cout<<endl;
	}
	return 0;
}

// you are provided an array of numbers. You need to arrange them in a way that yields the largest value.

// Input Format
// First line contains integer t which is number of test case.
// For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements of the array A .

// Constraints
// 1<=t<=100

// 1<=m<=100

// 1<=A[i]<=10^5

// Output Format
// Print the largest value.

// Sample Input
// 1
// 4
// 54 546 548 60
// Sample Output
// 6054854654
// Explanation
// Upon rearranging the elements of the array , 6054854654 is the largest possible number that can be generated.
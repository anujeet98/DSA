#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;

	int current_length;
	int best_length;
	int decreasing;
	int n;
	int num;
	int prev;

	while(t--){
		current_length=1;
		best_length=0;
		decreasing=0;
		cin>>n;
		if(n==1){
			cout<<1;
			continue;
		}
		cin>>prev;
		for(int i=1;i<n;i++){
			cin>>num;
			if(decreasing==1 && num>prev){
				best_length=max(best_length,current_length);
				current_length=2;
				decreasing=0;
			}
			else{
				current_length++;
				if(num<prev)
					decreasing=1;
			}
			prev=num;
		}
		best_length=max(best_length,current_length);
		cout<<best_length<<endl;
	}
	return 0;
}






// #include<iostream>
// using namespace std;
// int main() {
// 	int t;
// 	cin>>t;

// 	int current_length;
// 	int best_length;
// 	int decreasing;
// 	int n;
// 	int num;
// 	int prev;
// 	int equals;

// 	while(t--){
// 		current_length=1;
// 		best_length=0;
// 		decreasing=0;
// 		equals=0;
// 		cin>>n;
// 		if(n==1){
// 			cout<<1;
// 			continue;
// 		}
// 		cin>>prev;
// 		for(int i=1;i<n;i++){
// 			cin>>num;
// 			if(decreasing==1 && num>prev){
// 				best_length=max(best_length,current_length);
// 				if(equals>0){
// 					current_length=equals+2;
// 				}
// 				else
// 					current_length=2;
// 				decreasing=0;
// 			}
// 			else{
// 				current_length++;
// 				if(num==prev)
// 					equals++;
// 				else
// 					equals=0;
// 				if(num<prev && decreasing==0)
// 					decreasing=1;
// 			}
// 			prev=num;
// 		}
// 		best_length=max(best_length,current_length);
// 		cout<<best_length<<endl;
// 	}
// 	return 0;
// }




// 7481
// 19769
// 22014-----
// 11585
// 9744
// 7718
// 15680----
// 11847
// 17710-----
// 29569
// 15158
// 20814
// 18448
// 6962----
// 11718
// 8177
// 30535
// 16865
// 4396
// 15994
// 11386
// 17338
// 13208
// 8862
// 19047
// 24041
// 121
// 23508
// 18807
// 22824
// 16945
// 8348
// 3504
// 11730
// 13193
// 7626
// 17460
// 9305
// 3887
// 23911
// 9357
// 2218
// 4366
// 19650
// 394
// 5881
// 17067
// 4295
// 16488
// 11853
// 7730
// 10624
// 12523
// 15174
// 6486
// 6231
// 16119
// 24579
// 19737
// 17885
// 11297
// 9975
// 1831
// 16470
// 10340
// 7294
// 14434
// 14488
// 11789
// 11209
// 19839
// 494
// 12595






// You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i … j] is bitonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.

// Constraints
// 1<=t<=100 1<=n<=1000000

// Output Format
// Print the maximum length.

// Sample Input
// 2
// 6
// 12 4 78 90 45 23
// 4
// 40 30 20 10
// Sample Output
// 5
// 4
// Explanation
// ForMaximum length = 4, 78, 90, 45, 23
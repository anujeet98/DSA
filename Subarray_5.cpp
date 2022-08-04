#include<iostream>
#include<climits>
using namespace std;

void generateSubarray(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<=j;k++){
				cout<<a[k]<<" ";
			}
			cout<<endl;
		}
	}
}

void MaxSumSubarray(int a[],int n){
	int max_sum=INT_MIN;//can't be 0, since all elements if -ve then sum is always less than 0

	int start,end;  //to save sub array

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				sum+=a[k];
			}
			if(sum>max_sum){
				max_sum=sum;   //max_sum=max(max_sum,sum);

				//save max subarray start and end to print it later
				start=i;
				end=j;
			}
		}
	}
	cout<<"max subarray sum: "<<max_sum<<endl;
	for(int i=start;i<=end;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


//need to optimize the algo. instead of using 3 loops, can we do it in 2 loops.
//need precomputation => cumulative sum need to be calculated

void optimizedMaxSumSubarray(int a[],int n){  //O(n^2)
	int max_sum=INT_MIN;

	//first create cumulative sum(CSum) array. CSum of 1st element (index 0)=0 since no previous csum
	int csum[100]={0}; 
	for(int i=1;i<n;i++)
		csum[i]+=csum[i-1]+a[i];   //csum[i] = adding csum till previous elment + a[i]

	int start,end;  //to save max sum sub array start and end index

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			sum=csum[j]-csum[i-1];   //sum between 2 index = csum[end index]-csum[start index - 1],  ***this line replaces previous inner loop			}
			if(sum>=max_sum){
				max_sum=sum;   
				start=i;
				end=j;
			}
		}
	}
	cout<<"max subarray sum: "<<max_sum<<endl;
	for(int i=start;i<=end;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

'''//alternate to above
void max_sum_subarray(int a[],int n){
	int sum,max_sum=INT_MIN;

	//int start,end;  //to save subarray indices
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=i;j<n;j++){
			sum+=a[j];
			if(sum>max_sum){
				max_sum=sum;
				//print subarray not required in question
				//start=i;
				//end=j;
			}
		}
	}
	cout<<max_sum<<endl;
}
'''


void BestOptimizedMaxSumSubarray(int a[],int n){  //O(n^2)
	int current_best_sum=0;
	int overall_best_sum=0;
	for(int i=0;i<n;i++){
		current_best_sum+=a[i]; 
		//this means if current best is -ve why to add instead start new, thus new current best = a[i]
		if(a[i]>current_best_sum)
			current_best_sum=a[i];

		//if current best is greater than overall best then update value
		if(current_best_sum>overall_best_sum){
			overall_best_sum=current_best_sum;
		}
	}
	cout<<overall_best_sum<<endl;
}


int main(){
	int a[] = {2,1,4,5,7,6};
	int n=sizeof(a)/sizeof(int);
	//generateSubarray(a,n);


	int arr[] = {0,2,-1,4,5,-7,6};
	int arr_1[] = {0,-1,2,-2,3,6,-4,-3};
 	generateSubarray(arr,7);
	// MaxSumSubarray(arr,n);
	//optimizedMaxSumSubarray(arr,7);
	BestOptimizedMaxSumSubarray(arr,7);
	return 0;
}

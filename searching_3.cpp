#include<iostream>
using namespace std;

void LinerSearch(int a[],int n,int key){
	int i=0;
	for(i=0;i<n;i++){
		if(a[i]==key){
			cout<<"key found at index "<<i<<endl;
			break;//stop the loop
		}
	}
	//two ways to exit loop
	//1. when i==N, loop terminate
	//2. break statement executed, i can never be equal to n-1;
	if(i==n)
		cout<<"key not present"<<endl;
}


void BubbleSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<=n-2-i;j++){//n-2-i since last element gets placed correctly in every iteration no need to check conditions again
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1]);
				// int temp=a[j-1];
				// a[j-1]=a[j];
				// a[j]=temp;
			}
		}
	}
}

void SelectionSort(int a[],int n){
	for(int i=1;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min])
				min=j;
		}
		swap(a[i],a[min]);
	}

}

void print_array(int a[],int n){
	cout<<"your array is : ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void InsertionSort(int a[],int n){
	for(int i=1;i<n;i++){   //loop unsorted deck part i.e from 1 to last card
		int Pcard=a[i];     //Picked card will be ith element 
		int j;
		for(j=i-1 ; j>=0 and a[j]>Pcard ; j--)
			a[j+1]=a[j];
		a[j+1]=Pcard;
		////similar to->
		// for(int j=i-1;j>=0;j--){        //compare picked card from previous card till 0th card
		// 	if(a[j]>Pcard){             
		// 		a[j+1]=a[j];//move right if jth card > picked card
		// 	}
		// 	else{
		// 		break;//break the loop here if jth card < picked card()
		// 	}
		// }
		////when j=-1 loop ends that means last element was moved right =>update 0th(j+1 ie -1+1=0) element to Pcard
		////when break encounter that is a[j] is <= Pcard update j+1 th element with Pcard value
		//a[j+1]=Pcard; 
	}
}

bool compare(int a,int b){
	return a>b;//descending
	//return a<b;//ascending
}

void BubbleSortComparator(int a[],int n, bool (&mycompare)(int a,int b)){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<=n-2-i;j++){//n-2-i since last element gets placed correctly in every iteration no need to check conditions again
			if(mycompare(a[j+1],a[j])){    //comparing using compare function as parameter
				swap(a[j], a[j+1]);
			}
		}
	}
}

int main(){
	int a[] = {5,3,1,2,4};   //size not declared therefore it will initialize with size equal to declared/assigned elements
	int n = sizeof(a)/sizeof(int); //******correct only if size is exactly equal to declared. if a[10] given (X) it will give size 10 but only 5 elements declared originally
	print_array(a,n);

	// int key; //12//9
	// cout<<"enter key :";
	// cin>>key;


	// LinerSearch(a,n,key);

	// BubbleSort(a,n);

	//SelectionSort(a,n);

	// InsertionSort(a,n);



	////Inbuilt sort function sort(a,a+n,comparator function)
	//sort(a,a+n);
	////compare function passed as parameter not as argument
	// sort(a,a+n,compare);//using comparator. comparator function defined to sort in descending in function above. if ret 1(true) a>b, if ret 0(false) b>a
	// print_array(a,n);

    
    ////bubble sort using comparator
    BubbleSortComparator(a,n,compare);
  	print_array(a,n);


	return 0;
}

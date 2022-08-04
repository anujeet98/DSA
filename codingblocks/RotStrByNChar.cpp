//Rotate string by N characters.
//https://online.codingblocks.com/app/player/239418/content/224368/12558/lecture
#include<iostream>
using namespace std;
// void rotateStrByN(char a[], int N){
// 	int len=strlen(a);
// 	int i=len-1;
// 	int j=len-1+N;
// 	while(i>=0){
// 		a[j]=a[i];
// 		j--;
// 		i--;
// 	}
// 	i=len-1+N;
// 	while(j>=0){
// 		a[j]=a[i];
// 		i--;
// 		j--;
// 	}
// 	a[len]='\0';
// 	cout<<a;
// }

//with only one variable i
void rotateStrByN(char a[], int N){
	int len=strlen(a);
	int i=len-1;
	while(i>=0){
		a[i+N]=a[i];
		i--;
	}
	i=N-1;
	while(i>=0){
		a[i]=a[len+i];
		i--;
	}
	a[len]='\0';
	cout<<a;
}

int main(){
	char arr[1000];
	cin.getline(arr, 1000);
	int N;
	cin>>N;
	rotateStrByN(arr,N);
}

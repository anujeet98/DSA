//Remove consecutive duplicate character
//https://online.codingblocks.com/app/player/239418/content/224368/12557/lecture
#include<iostream>
using namespace std;
void removeDupl(char a[]){
	int len=strlen(a);
	int i = 0;
	int j = 1;
	while(j<=len){
		if(a[i]!=a[j]){
			i++;
			a[i]=a[j];
		}
		j++;
	}
	cout<<a;
}

int main(){
	char arr[1000];
	cin.getline(arr, 1000);
	removeDupl(arr);
}
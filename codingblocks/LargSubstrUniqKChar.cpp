//Remove consecutive duplicate character
//https://online.codingblocks.com/app/player/239418/content/224368/12557/lecture
#include<iostream>
using namespace std;

bool compare_str(char a[],char b[]){
	if(strlen(a)!=strlen(b))
		return false;
	int i=0;
	while(i<strlen(a)){
		if(a[i]!=b[i])
			return false;
		i++;
	}
	return true;
}

//with only one variable i
void longest_K_Unq_Char_SubStr(char a[], char b[]){
	int i=strlen(a);
	int j=0;
	while(j<=strlen(b)){
		a[i]=b[j];
		j++;
		i++;
	}
	cout<<a<<endl;
}

int main(){
	char a[1000];
	cin.getline(a, 1000);
	char b[1000];
	cin.getline(b, 1000);
	if(compare_str(a,b))
		cout<<"Match"<<endl;
	else
		cout<<"No match"<<endl;
	longest_K_Unq_Char_SubStr(a,b);
}
//Remove consecutive duplicate character
//https://online.codingblocks.com/app/player/239418/content/224368/12557/lecture
#include<iostream>
using namespace std;

bool compare_str(char a[],char b[]){
	if(strlen(a)!=strlen(b))
		return false;
	int i=0;
	while(i<strlen(a)){
		if(a[i]!=b[i])
			return false;
		i++;
	}
	return true;
}

//with only one variable i
void longest_K_Unq_Char_SubStr(char a[], char b[]){
	int i=strlen(a);
	int j=0;
	while(j<=strlen(b)){
		a[i]=b[j];
		j++;
		i++;
	}
	cout<<a<<endl;
}

int main(){
	char a[1000];
	cin.getline(a, 1000);
	char b[1000];
	cin.getline(b, 1000);
	if(compare_str(a,b))
		cout<<"Match"<<endl;
	else
		cout<<"No match"<<endl;
	longest_K_Unq_Char_SubStr(a,b);
}

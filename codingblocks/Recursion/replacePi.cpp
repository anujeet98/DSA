#include<iostream>
#include<string>
using namespace std;


string replacePi(string ip, int index){
	string smallerString="";
	if(ip.length()==index+1)
		return smallerString+ip[index];
	if(ip.length()<index+1)
		return "";	
	if(ip[index]=='p' && ip[index+1]=='i'){
		smallerString = replacePi(ip, index+2);
		smallerString = "3.14"+smallerString;
	}
	else{
		smallerString = replacePi(ip,index+1);
		smallerString = ip[index]+smallerString;
	}

	return smallerString;
}

void replacePi_char_arr(char *ip, int index){
	if(ip[index]=='\0' || ip[index+1]=='\0')
		return;

	if(ip[index]=='p' && ip[index+1]=='i'){
		//shift elemnts and add 3.14 in char array

		int j=index+2;
		while(ip[j]!='\0'){
			j++;
		}

		while(j>=index+2){
			ip[j+2]=ip[j];
			j--;
		}

		ip[index]='3';
		ip[index+1]='.';
		ip[index+2]='1';
		ip[index+3]='4';

		replacePi_char_arr(ip, index+4);
	}
	else{
		replacePi_char_arr(ip,index+1);
	}

}

int main(){
	//string ip = "axpiaepif";
	//ip = replacePi(ip,0);

	//below using char array; above using string
	char ip[100] =  "axpiaepif";
	replacePi_char_arr(ip, 0);
	
	cout<<ip<<endl;
	return 0;
}

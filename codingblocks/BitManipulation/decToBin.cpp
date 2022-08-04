#include<iostream>
#include<string>

using namespace std;

int decToBin(int n){
	int ans=0;
	int p=1;

	while(n>0){
		//cout<<n%2;//prints in reverse order
		//to print in correct order multiply each remainder with increasing power of 10;
		ans+=(n%2)*p;
		p*=10;//incrementing power of 10;
		n/=2;
	}
	return ans;
}

int decToBin_Bitwise(int n){
	//number stored in 32 bit int container in bin format
	//use AND with 1 to get LSB and then right shift till num>0; continue getting LSB using AND with 1
	int ans=0;
	int p=1;

	while(n>0){
		ans+= (n & 1)*p;
		p*=10;
		n=(n>>1);
	}
	return ans;
}

//LIMITATION of above method. 32 bit number. if we multiple each power and bit it will be very larger number and it will overflow int/ long long bucket
//SOLUTION: use arrays/string to store the bits. check input for example

string decToBin_Bitwise_String(int n){
	//number stored in 32 bit int container in bin format
	//use AND with 1 to get LSB and then right shift till num>0; continue getting LSB using AND with 1
	string ans;

	while(n>0){
		ans.push_back('0'+(n%2));
		//same as above: if(n%2==0) push_back('0')   else push_back('1')
		n/=2;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	//input contains 9 digits but its bin rep will have greater than 9 digits therfore it will overflow int bucket for ans
	int n=140001012;//overflows for first 2 methods therfore use string to store it
	//cin>>n;
	cout<<decToBin(n)<<endl;
	cout<<decToBin_Bitwise(n)<<endl;
	cout<<decToBin_Bitwise_String(n)<<endl;
}

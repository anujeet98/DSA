#include<iostream>
using namespace std;

void generate_subsequence(string op, string ip, int index){
	//base case if balance is -ve i.e "(" occured before ")" so return back
	//if we reached length N==0; check if balance is 0 then print paranthesis string. if not i.e paranthesis not balanced therefore return back
	if(index==ip.length())
	{
		cout<<op<<endl;
		return;
	}

	//have 2 choices to take index char or not take decision; which updates op string; call recucursion for remaining elements starting from index+1 location
	generate_subsequence(op , ip , index+1);  //don't add index char
	generate_subsequence(op+ip[index] , ip , index+1);  //add index char

}






int main(){
	string ip;
	cin>>ip;
	generate_subsequence("",ip,0);
	return 0;
}

#include<iostream>
using namespace std;

void balanced_paranthesis(string op, int N, int balance){
	//base case if balance is -ve i.e "(" occured before ")" so return back
	//if we reached length N==0; check if balance is 0 then print paranthesis string. if not i.e paranthesis not balanced therefore return back
	if(balance<0)
		return;
	if(N==0){
		if(balance==0){
			cout<<op<<endl;
			return;
		}
		else
			return;
	}

	//have 2 choices to take "(" or ")" take decision; which updates balance value and string op; call recucursion for remaining N-1 elements
	balanced_paranthesis(op+"(" , N-1, balance+1);  //add "("
	balanced_paranthesis(op+")" , N-1, balance-1);  //add ")"
}


//m-2 using arrays
void generate(char *a, int index, int open, int close, int n){
	//base case
	if(index == 2*n)  //reached last location
	{
		//add '\0' at end and print array
		a[index] = '\0';
		cout<< a << endl;
		return;
	}	

	//recursive case
	if(open < n)//if opening brac count < number of brackets we can add then can ip one "(" 
	{
		a[index]='(';
		generate(a, index+1, open+1, close, n);
	}

	//now other coice is we can add closing brac also; ")" if balance will not be negative i.e open>close (if equal then adding ")" will make balance -ve )
	if(open > close){
		a[index]=')';
		generate(a, index+1, open, close+1, n);
	}	
}	



int main(){
	int N;
	cin>>N;
	//myt method using string  v
	//balanced_paranthesis("",2*N,0);

	//method 2 using arrays to store string
	char a[100];
	generate(a, 0, 0, 0, N);
	return 0;
}

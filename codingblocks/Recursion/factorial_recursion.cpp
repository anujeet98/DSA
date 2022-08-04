#include<iostream>
using namespace std;

int factorial_rec(int n){
	if(n==0 || n==1)
		return 1;
	return n*factorial_rec(n-1);
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        // Store last digit of 'prod' in res[] 
        res[i] = prod % 10; 
        // Put rest in carry
        carry  = prod/10;   
    }
    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
 
void factorial_largeNumber(int n)
{
    int res[1000];
 
    // Initialize result
    res[0] = 1;
    int res_size = 1;
 
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
 
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
	cout<<endl;
}
 

int main(){
	int n;
	cin>>n;
	cout<<factorial_rec(n);
	//factorial_largeNumber(n);  //for large numbers use array to store results
	return 0;
}

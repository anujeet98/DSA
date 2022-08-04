//pair() 
#include<iostream>
#include<algorithm>//to use find,binary_search,
using namespace std;

int main(){

	pair<int,int> p;
	//pair<int,int> p(500,20);
	p.first=10;
	p.second=101;

	cout<<"first: "<<p.first<<endl;
	cout<<"Second: "<<p.second<<endl;

	pair<string, int> p2;
	//using make_pair() function to create pair
	p2 = make_pair("BMW", 12);

	cout<<"p2 first: "<<p2.first<<endl;
	cout<<"p2 Second: "<<p2.second<<endl;


	pair<string, pair<float,int> > p3;
	p3.first = "BMW";
	p3.second.first = 10.11;
	p3.second.second = 12;

	cout<<p3.first<<endl;
	cout<<p3.second.first<<endl;
	cout<<p3.second.second<<endl;


}

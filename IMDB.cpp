//https://www.codechef.com/LP1TO201/problems/IMDB
#include<iostream>
using namespace std;

int main(){
	int T;
	int N,X;
	int Si,Ri;
	cin>>T;
	while(T--){
		int max_rating=-1;
		cin>>N>>X;
		while(N--){
			cin>>Si>>Ri;
			if(Si<=X && max_rating<Ri)
				max_rating=Ri;
		}
		cout<<max_rating<<endl;
	}
	return 0;
}


// Chef has been searching for a good motivational movie that he can watch during his exam time. His hard disk has X GB of space remaining. His friend has N movies represented with (Si,Ri) representing (space required, IMDB rating). Help Chef choose the single best movie (highest IMDB rating) that can fit in his hard disk.

// Input
// The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test case contains two space-separated integers N and X.
// N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Si and Ri.
// Output
// For each test case, print a single line containing one integer - the highest rating of an IMDB movie which Chef can store in his hard disk
#include<iostream>
using namespace std;
int main() {
	int m,n;
	cin>>m>>n;
	int matrix[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}

	for(int j=0;j<n;j++){
		for(int i=0;i<m;i++){
			int i_value=i;
			if(j%2!=0){
				i_value=m-1-i;
			}
			cout<<matrix[i_value][j]<<", ";
		}
	}
	cout<<"END";
	return 0;
}

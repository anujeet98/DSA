#include<iostream>
using namespace std;

void toh(int N, char source, char destn, char helper){
	if(N==0)
		return;
	//belief that below recursive call function will move N-1 blocks from A tower(source) to tower B(helper) and print its steps
	toh(N-1,source,helper,destn);
	//now above prints steps to move n-1 disk to helper. Now print move of last disk from source to destn
	cout<<"move disk "<<N<<" from rod "<<source<<" to rod "<<destn<<endl;
	//Belieg: now use rec call to print steps to move N-1 disks from helper B to destination C
	toh(N-1,helper,destn,source);
}


int main(){
	int N=3;//number of disk
	//call funt to perform toh move n disk from source A to destination C using helper tower 'C'
	toh(N,'A','C','B');
	return 0;
}




//count no of steps
'''
    long long toh(int N, int source, int destn, int helper) {
    	if(N==0)
    		return 0;
    		
    	long long int steps=0;
    	//belief that below recursive call function will move N-1 blocks from A tower(source) to tower B(helper) and print its steps
    	steps+=toh(N-1,source,helper,destn);
    	//now above prints steps to move n-1 disk to helper. Now print move of last disk from source to destn
    	cout<<"move disk "<<N<<" from rod "<<source<<" to rod "<<destn<<endl;
    	//Belieg: now use rec call to print steps to move N-1 disks from helper B to destination C
    	steps+=toh(N-1,helper,destn,source);
    	return steps+1;
    }
 '''

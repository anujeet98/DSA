// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7997#problem

#include<iostream>
#include<string>
using namespace std;

int get_digit(string N){
    int req_digit=0;
    string:: iterator it;
    for (it = N.begin(); it != N.end();it++) {
    	int digit=(int)*it-48;
    	req_digit+=digit;
    	req_digit=req_digit%9;
    }
    return 9-req_digit;
}

int main(){
    int T;
    cin>>T;
    int iteration=T;
    while(T--){
        string N;
        cin>>N;
        int digit=get_digit(N);
        if(digit==9)
        	digit=0;
        //cout<<digit<<endl;
	    string:: iterator it;
	    bool added=false;
	    for (it = N.begin(); it != N.end();it++) {
	    	if(digit==0 && it==N.begin())
	    		continue;
	    	else if(digit<(int)*it-48){
	    		N.insert(it,(char)(digit+48));
	    		added=true;
	    		break;
	    	}
	    }
	    if(!added)
	    	N+=(char)(digit+48);
        cout<<"Case #"<<iteration-T<<": "<<N<<endl;
    }
    return 0;
}
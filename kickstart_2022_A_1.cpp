// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7021

#include<iostream>
#include<string.h>
#include <cctype>
using namespace std;

int main()
{
    int T;
    cin>>T;
    int iteration=T;
    string I;
    string P;
    while(T--){
        int delete_count=0;
        bool impossible=false;
        cin>>I;
        cin>>P;
        if(I.length()>P.length()){
            impossible=true;
        }
        else{
            int i=0;
            int j=0;
            while(i<I.length() && j<P.length()){
                if(I[i]==P[j]){
                    i++;
                }
                else if(I[i]!=P[j]){
                    delete_count++;
                }
                j++;
            }
            if(i==I.length()){
                delete_count+=(P.length()-j);
            }
            else
                impossible=true;
        }
        if(impossible)
            cout<<"Case #"<<iteration-T<<": IMPOSSIBLE"<<endl;
        else
            cout<<"Case #"<<iteration-T<<": "<<delete_count<<endl;
    }

    return 0;
}
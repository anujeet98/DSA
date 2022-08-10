#include<iostream>
#include<stack>
#include<vector>

using namespace std;


void findCelebrity(vector<vector<int> > arr) {
    stack<int> st;
    int n = arr.size();

//PUSH all people onto stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

//only one celeb exist; can be proved by contradicting the problem statement, also 0 celeb also exist
    //pop 2 person. one of them is confirmed not celeb. so other is pushed back. every time 1 person is eleminated
    //at end 1 person remain
    //this person may be celeb by checking its rows and column values
    while (st.size() > 1) {
        int p1 = st.top();
        st.pop();
        int p2 = st.top();
        st.pop();
        if (arr[p1][p2] == 1) { //confirmed that p1 is not celeb (as celeb doesn't know anyone ; false for P1, P2 might be celeb so push)
            st.push(p2);
        }
        else if (arr[p1][p2] == 0) { //p1 doesn't know p2, p2 not celeb confirmed as (celeb is known by everyone), p1 might be celeb
            st.push(p1);
        }
    }

    int person_index = st.top();
    for (int i = 0; i < n; i++) {
        if (person_index != i) { //for non i,i locations
            if (arr[person_index][i] == 1 or arr[i][person_index] == 0) { //if person_index(celeb) lknows any other person or any person doesn't know this assumed celeb;  then it is not CELEb
                cout << "none" << endl;
                return;
            }
        }
    }
    cout << person_index << endl;

}



int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s); //to ignore white space
    vector<vector<int> > arr (n);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < n; j++) {
            arr[i].push_back(s[j] - '0');
        }
    }

    findCelebrity(arr);

    return 0;
}

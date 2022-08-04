//https://leetcode.com/problems/valid-parentheses/
//https://www.pepcoding.com/resources/online-java-foundation/stacks-and-queues/balanced-brackets-official/ojquestion (modified below to ignore char other than brackets)
#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char>st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')' or s[i] == '}' or s[i] == ']') {
            if (st.empty())
                return false;
            if (s[i] == ')' and st.top() == '(' )
                st.pop();
            else if (s[i] == '}' and st.top() == '{' )
                st.pop();
            else if (s[i] == ']' and st.top() == '[' )
                st.pop();
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    return false;
}


int main(int argc, char const *argv[])
{
    string input;
    getline(cin, input);
    if (isValid(input))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
